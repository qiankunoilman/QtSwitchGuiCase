#pragma once

#include <QWidget>
#include "ui_SolverWidget.h"

class SolverWidget : public QWidget
{
	Q_OBJECT

public:
	SolverWidget(QWidget *parent = Q_NULLPTR);
	~SolverWidget();

private:
	Ui::SolverWidget ui;
};
