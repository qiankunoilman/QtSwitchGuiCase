#include "CustomSplash.h"

CustomSplash::CustomSplash(const QPixmap &pixmap, Qt::WindowFlags f)
	: QSplashScreen(pixmap,f)
{
	ui.setupUi(this);
}

CustomSplash::~CustomSplash()
{

}

void CustomSplash::drawContents(QPainter * painter)
{
	painter->drawPixmap(0,0,700,500, QPixmap(R"(D:\MAKER\SwitchWidget\SwitchWidgetCase\test.PNG)"));

	return QSplashScreen::drawContents(painter);
}
