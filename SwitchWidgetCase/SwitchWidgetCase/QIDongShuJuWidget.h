#pragma once

#include <QWidget>
#include "ui_QIDongShuJuWidget.h"

class QIDongShuJuWidget : public QWidget
{
	Q_OBJECT

public:
	QIDongShuJuWidget(QWidget *parent = Q_NULLPTR);
	~QIDongShuJuWidget();

private:
	Ui::QIDongShuJuWidget ui;
};
