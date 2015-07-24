#ifndef SKYHANDLER_H
#define SKYHANDLER_H

/*
	����ʵ���ǿյĶ�̬�仯
*/

#include <osgGA/GUIEventHandler>
#include <osgEarthUtil/Sky>

namespace MyEarth {

class SkyHandler : public osgGA::GUIEventHandler
{
public:
	SkyHandler(osgEarth::Util::SkyNode* skyNode);
	~SkyHandler();

	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);

private:
	osg::ref_ptr<osgEarth::Util::SkyNode> _skyNode;
	osgEarth::DateTime _datetime;
};

}

#endif // SKYHANDLER_H
