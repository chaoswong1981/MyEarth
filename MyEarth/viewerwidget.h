#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

/**
* ����������Ҫ��Ϊ��ʵ������ڴ�����ʱ�л��������ָ��
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
