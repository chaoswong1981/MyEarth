#ifndef MyMainWindow_H
#define MyMainWindow_H

#include <QtGui/QMainWindow>
#include "ui_myearth.h"

#include <osgViewer/Viewer>
#include <osgEarthQt/ViewerWidget>
#include <osgEarth/MapNode>

namespace MyEarth {
	class Viewer;
}

class EnvironmentSetting;

class MyMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MyMainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyMainWindow();

public:
	virtual void closeEvent(QCloseEvent * e);

protected:
	void initActions();

public slots:
	void onEnvironmentSetting();

private:
	Ui::MyEarthClass ui;

	osgEarth::QtGui::ViewerWidget* _viewerWidget;
	osg::ref_ptr<MyEarth::Viewer> _viewer;

	//dialog
	EnvironmentSetting* _environmentSetting;
};

#endif // MyMainWindow_H
