#include "SwitchWidgetCase.h"
#include <QtWidgets/QApplication>
//#include <QSplashScreen>
#include "CustomSplash.h"
#include <QEventLoop>
#include <QTimer>
#include "CustomSplashWidget.h"

#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//创建启动动画类实例，使用资源文件splash.jpg作为展示图片
	CustomSplashWidget splash;

	//窗口淡入
	QPropertyAnimation *animation = new QPropertyAnimation(&splash, "windowOpacity");
	animation->setDuration(1000);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	splash.show();

	//初始化操作
	


	//动画切换朱主界面
	SwitchWidgetCase w;
	//设置飞溅屏结束后展示的主界面
	splash.SetMainWindow(&w);

	return a.exec();
}
