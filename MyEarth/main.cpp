#include "mymainwindow.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>

#ifdef QT_NO_DEBUG
#else
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgQtd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "osgEarthd.lib")
#pragma comment(lib, "osgEarthQtd.lib")
#pragma comment(lib, "osgEarthUtild.lib")
#endif

int main(int argc, char *argv[])
{
	QTextCodec *codec = QTextCodec::codecForName("System"); //获取系统编码
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);
	setlocale( LC_ALL, "chs" ); // 这行是为了osgDB支持中文路径

	QApplication a(argc, argv);
	MyMainWindow w;
	w.showMaximized();
	return a.exec();
}
