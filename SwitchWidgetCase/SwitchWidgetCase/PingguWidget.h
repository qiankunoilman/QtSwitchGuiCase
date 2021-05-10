#pragma once

#include <QWidget>
#include "ui_PingguWidget.h"

class PingguWidget : public QWidget
{
	Q_OBJECT

public:
	PingguWidget(QWidget *parent = Q_NULLPTR);
	~PingguWidget();

private:
	Ui::PingguWidget ui;
};
