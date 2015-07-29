#include "viewer.h"

#include <osgDB/ReadFile>
#include <osgEarthUtil/AutoClipPlaneHandler>
#include <osgEarthUtil/Ocean>
#include <osg/LightModel>
#include <QMessageBox>
#include <QTime>

#include "earthmanipulator.h"
#include "skyhandler.h"

namespace MyEarth {

Viewer::Viewer(std::string earthfile)
{
	setThreadingModel(osgViewer::ViewerBase::SingleThreaded);

	initScene(earthfile);
	initSkyOcean();

	osgEarth::Viewpoint vp;
	vp.setFocalPoint(osg::Vec3d(108.90199,34.04073,0));
	vp.setRange(9668062);
	vp.setPitch(-90);
	_manip->setViewpoint(vp, 2);

	initHandlers();
}

Viewer::~Viewer()
{

}

bool Viewer::initScene(std::string& earthfile)
{
	// 创建基础场景
	osg::Node* earthNode = osgDB::readNodeFile(earthfile);
	if (!earthNode)
	{
		QMessageBox::warning(0, "警告", ".earth 文件不存在或加载失败");
		return false;
	}

	_root = new osg::Group;
	_root->addChild(earthNode);
	setSceneData(_root);

	_mapNode = osgEarth::MapNode::findMapNode(earthNode);
	getCamera()->addCullCallback(new osgEarth::Util::AutoClipPlaneCullCallback(_mapNode));

	_manip = new MyEarth::EarthManipulator;
	setCameraManipulator(_manip);
	return true;
}

void Viewer::initSkyOcean()
{
	// 天空
	if (_mapNode.valid())
	{
		if (_mapNode->getMap()->isGeocentric())
		{
			_sky = osgEarth::Util::SkyNode::create(_mapNode);
			_sky->setDateTime( osgEarth::DateTime(2010, 10, 1, 6) );
			_sky->setLighting(true);
			_sky->attach( this, 0 );

			// 这里把mapNode挪到sky下面, 使sky中的光照生效
			_root->removeChild(_mapNode);
			_sky->addChild(_mapNode);
			_root->addChild(_sky);
		}
	}
}

void Viewer::initHandlers()
{
	addEventHandler(new MyEarth::SkyHandler(_sky));
}

}