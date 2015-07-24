#include "environmentsetting.h"

EnvironmentSetting::EnvironmentSetting(QWidget *parent, osgEarth::Util::SkyNode* sky)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowStaysOnTopHint);

	_sky = sky;
	osgEarth::Util::DateTime d = _sky->getDateTime();
	ui.label_time->setText(QString("%1").arg(d.hours()));
	ui.slider_time->setValue(d.hours());

	ui.checkBox_star->setChecked(_sky->getStarsVisible());
	ui.checkBox_sun->setChecked(_sky->getSunVisible());
	ui.checkBox_moon->setChecked(_sky->getMoonVisible());

	connect(ui.slider_time, SIGNAL(valueChanged(int)), this, SLOT(onSliderTime(int)));
	connect(ui.slider_ambient, SIGNAL(valueChanged(int)), this, SLOT(onSliderAmbient(int)));
	connect(ui.slider_speed, SIGNAL(valueChanged(int)), this, SLOT(onSliderSpeed(int)));
	connect(ui.checkBox_star, SIGNAL(stateChanged(int)), this, SLOT(onCheckStar(int)));
	connect(ui.checkBox_sun, SIGNAL(stateChanged(int)), this, SLOT(onCheckSun(int)));
	connect(ui.checkBox_moon, SIGNAL(stateChanged(int)), this, SLOT(onCheckMoon(int)));
}

EnvironmentSetting::~EnvironmentSetting()
{

}

void EnvironmentSetting::onSliderTime(int v)
{
	osgEarth::Util::DateTime d = _sky->getDateTime();
	_sky->setDateTime(osgEarth::Util::DateTime(d.year(), d.month(), d.day(), v));
	ui.label_time->setText(QString("%1").arg(v));
}

void EnvironmentSetting::onSliderAmbient(int v)
{
	double dv = v / 100.;
	osg::Light* sun = _sky->getSunLight();
	sun->setAmbient(osg::Vec4(dv,dv,dv,1));
	ui.label_ambient->setText(QString("%1").arg(dv));
}

void EnvironmentSetting::onSliderSpeed(int)
{

}

void EnvironmentSetting::onCheckStar(int v)
{
	_sky->setStarsVisible(v);
}

void EnvironmentSetting::onCheckSun(int v)
{
	_sky->setSunVisible(v);
}

void EnvironmentSetting::onCheckMoon(int v)
{
	_sky->setMoonVisible(v);
}