#include "skyhandler.h"

namespace MyEarth {

SkyHandler::SkyHandler(osgEarth::Util::SkyNode* skyNode)
{
	_skyNode = skyNode;
	_datetime = _skyNode->getDateTime();
}

SkyHandler::~SkyHandler()
{

}

bool SkyHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME)
	{
		osgEarth::DateTime dt = _skyNode->getDateTime();
		double hours = dt.hours() + 0.001;
		if (hours > 24)
			hours = 0;

		_skyNode->setDateTime(osgEarth::DateTime(dt.year(), dt.month(), dt.day(), hours));
	}

	return false;
}

}