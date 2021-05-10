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

	//��������������ʵ����ʹ����Դ�ļ�splash.jpg��ΪչʾͼƬ
	CustomSplashWidget splash;

	//���ڵ���
	QPropertyAnimation *animation = new QPropertyAnimation(&splash, "windowOpacity");
	animation->setDuration(1000);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	splash.show();

	//��ʼ������
	


	//�����л���������
	SwitchWidgetCase w;
	//���÷ɽ���������չʾ��������
	splash.SetMainWindow(&w);

	return a.exec();
}
