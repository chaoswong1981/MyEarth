#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

/**
* 派生出来主要是为了实现鼠标在窗口里时切换各种鼠标指针
*/

#include <osgEarthQt/ViewerWidget>

namespace MyEarth {

class ViewerWidget : public osgEarth::QtGui::ViewerWidget
{
public:
	ViewerWidget(osgViewer::Viewer* view);
	~ViewerWidget();
};

}

#endif // VIEWERWIDGET_H
