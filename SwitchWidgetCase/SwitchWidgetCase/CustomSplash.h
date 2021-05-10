#pragma once

#include <QSplashScreen>
#include "ui_CustomSplash.h"
#include <QPainter>
#include <QPicture>

class CustomSplash : public QSplashScreen
{
	Q_OBJECT

public:
	CustomSplash(const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags());
	~CustomSplash();
protected:
	virtual  void drawContents(QPainter *painter) override;
private:
	Ui::CustomSplash ui;
};
