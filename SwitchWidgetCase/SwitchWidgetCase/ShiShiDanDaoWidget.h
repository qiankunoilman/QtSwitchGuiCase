#pragma once

#include <QWidget>
#include "ui_ShiShiDanDaoWidget.h"

class ShiShiDanDaoWidget : public QWidget
{
	Q_OBJECT

public:
	ShiShiDanDaoWidget(QWidget *parent = Q_NULLPTR);
	~ShiShiDanDaoWidget();

private:
	Ui::ShiShiDanDaoWidget ui;
};
