#pragma once

#include <QWidget>
#include "ui_QidongWidget.h"

class QidongWidget : public QWidget
{
	Q_OBJECT

public:
	QidongWidget(QWidget *parent = Q_NULLPTR);
	~QidongWidget();

private:
	Ui::QidongWidget ui;
};
