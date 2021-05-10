#include "CustomButton.h"

CustomButton::CustomButton(QWidget *parent)
	: QPushButton(parent)
{
	ui.setupUi(this);
	connect(this, &QPushButton::clicked, this,[=] {
		QString obj_name = this->objectName();
		int index = obj_name.mid(obj_name.length() - 1, obj_name.length()).toInt();

		emit  CustomClickSignal(index);
	});
}

CustomButton::~CustomButton()
{
}
