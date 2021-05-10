#pragma once

#include <QWidget>
#include "ui_KuaiSuDanDaoWidget.h"

class KuaiSuDanDaoWidget : public QWidget
{
	Q_OBJECT

public:
	KuaiSuDanDaoWidget(QWidget *parent = Q_NULLPTR);
	~KuaiSuDanDaoWidget();

private:
	Ui::KuaiSuDanDaoWidget ui;
};
