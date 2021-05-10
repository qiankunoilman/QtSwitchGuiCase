#pragma once

#include <QPushButton>
#include "ui_CustomButton.h"

class CustomButton : public QPushButton
{
	Q_OBJECT

public:
	CustomButton(QWidget *parent = Q_NULLPTR);
	~CustomButton();
signals:
	void CustomClickSignal(int index);
private:
	Ui::CustomButton ui;
};
