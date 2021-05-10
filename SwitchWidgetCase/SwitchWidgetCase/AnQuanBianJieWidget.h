#pragma once

#include <QWidget>
#include "ui_AnQuanBianJieWidget.h"

class AnQuanBianJieWidget : public QWidget
{
	Q_OBJECT

public:
	AnQuanBianJieWidget(QWidget *parent = Q_NULLPTR);
	~AnQuanBianJieWidget();

private:
	Ui::AnQuanBianJieWidget ui;
};
