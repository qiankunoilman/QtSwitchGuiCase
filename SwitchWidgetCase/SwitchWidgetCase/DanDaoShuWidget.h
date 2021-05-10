#pragma once

#include <QWidget>
#include "ui_DanDaoShuWidget.h"

class DanDaoShuWidget : public QWidget
{
	Q_OBJECT

public:
	DanDaoShuWidget(QWidget *parent = Q_NULLPTR);
	~DanDaoShuWidget();

private:
	Ui::DanDaoShuWidget ui;
};
