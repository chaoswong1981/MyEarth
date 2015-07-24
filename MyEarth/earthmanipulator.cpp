#include "earthmanipulator.h"

namespace MyEarth {

EarthManipulator::EarthManipulator()
{
	//_settings->setLockAzimuthWhilePanning(false);
	_settings->setThrowingEnabled(true);
	_settings->setArcViewpointTransitions(false);
}

EarthManipulator::~EarthManipulator()
{

}

bool EarthManipulator::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us)
{
	osgEarth::Viewpoint vp = getViewpoint();
	return osgEarth::Util::EarthManipulator::handle(ea, us);
}

bool EarthManipulator::handleKeyboardAction(const Action& action, double duration)
{
	if (action._type == osgEarth::Util::EarthManipulator::ACTION_HOME)
	{
		osgEarth::Viewpoint vp;
		vp.setFocalPoint(osg::Vec3d(108.90199,34.04073,0));
		vp.setRange(9668062);
		vp.setPitch(-90);

		setViewpoint(vp, 2);
		return true;
	}

	return osgEarth::Util::EarthManipulator::handleKeyboardAction( action, duration );
}

}
