#ifndef ENVIRONMENTSETTING_H
#define ENVIRONMENTSETTING_H

#include <QWidget>
#include "ui_environmentsetting.h"

#include <osgEarthUtil/Sky>

class EnvironmentSetting : public QWidget
{
	Q_OBJECT

public:
	EnvironmentSetting(QWidget *parent, osgEarth::Util::SkyNode* sky);
	~EnvironmentSetting();

public slots:
	void onSliderTime(int);
	void onSliderAmbient(int);
	void onSliderSpeed(int);
	void onCheckStar(int);
	void onCheckSun(int);
	void onCheckMoon(int);

private:
	Ui::EnvironmentSetting ui;

	osg::ref_ptr<osgEarth::Util::SkyNode> _sky;
};

#endif // ENVIRONMENTSETTING_H
