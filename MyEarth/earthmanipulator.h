#ifndef EARTHMANIPULATOR_H
#define EARTHMANIPULATOR_H

#include <osgEarthUtil/EarthManipulator>

namespace MyEarth {

class EarthManipulator : public osgEarth::Util::EarthManipulator
{
public:
	EarthManipulator();
	~EarthManipulator();

public:
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleKeyboardAction(const Action& action, double duration);

private:
	
};

}

#endif // EARTHMANIPULATOR_H
