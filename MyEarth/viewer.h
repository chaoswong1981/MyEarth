#ifndef VIEWER_H
#define VIEWER_H

#include <osgViewer/Viewer>
#include <osgEarth/MapNode>
#include <osgEarthUtil/Sky>
#include <osgEarth/Viewpoint>

namespace MyEarth {

class EarthManipulator;

class Viewer : public osgViewer::Viewer
{
public:
	Viewer(std::string earthfile);
	~Viewer();

public:

protected:
	bool initScene(std::string& earthfile);
	void initSkyOcean();
	void initHandlers();

public:
	osgEarth::Util::SkyNode* getSky() {return _sky;}

protected:
	osg::ref_ptr<osg::Group> _root;
	osg::ref_ptr<osgEarth::MapNode> _mapNode;

	osg::ref_ptr<osgEarth::Util::SkyNode> _sky;
	osg::ref_ptr<MyEarth::EarthManipulator> _manip;
};

}

#endif // VIEWER_H
