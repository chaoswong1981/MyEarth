#include "mymainwindow.h"

#include <QCloseEvent>
#include "viewer.h"
#include "environmentsetting.h"

MyMainWindow::MyMainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, _environmentSetting(0)
{
	ui.setupUi(this);

	_viewer = new MyEarth::Viewer("../data/demo_cn.earth");
	_viewerWidget = new osgEarth::QtGui::ViewerWidget(_viewer);

	setCentralWidget(_viewerWidget);

	initActions();
}

MyMainWindow::~MyMainWindow()
{

}

void MyMainWindow::closeEvent(QCloseEvent * e)
{
	if (_viewerWidget)
	{
		_viewerWidget->getViewer()->setDone(true);
	}

	e->accept();
}

void MyMainWindow::initActions()
{
	connect(ui.action_environment_setting, SIGNAL(triggered()), this, SLOT(onEnvironmentSetting()));
}

void MyMainWindow::onEnvironmentSetting()
{
	if (!_environmentSetting)
		_environmentSetting = new EnvironmentSetting(0, _viewer->getSky());
	_environmentSetting->show();
}