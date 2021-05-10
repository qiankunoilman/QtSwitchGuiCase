#include "Test.h"

Test::Test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionswitch, &QAction::triggered, this, [=] {
		

		

		QLabel *label = new QLabel(this);
		//label->resize(this->centralWidget()->size());
		label->setGeometry(this->centralWidget()->geometry());
		label->setPixmap(this->centralWidget()->grab());
		label->show();

		QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
		animation->setDuration(3000);

		animation->setStartValue(QRect(0,0,this->centralWidget()->width(),this->centralWidget()->height()));
		animation->setEndValue(QRect(this->centralWidget()->width(), 0, this->centralWidget()->width(), this->centralWidget()->height()));

		QPropertyAnimation *animation1 = new QPropertyAnimation(this->centralWidget(), "geometry");
		animation1->setDuration(3000);
		animation1->setStartValue(QRect(-this->centralWidget()->width(), 0, this->centralWidget()->width(), this->centralWidget()->height()));
		animation1->setEndValue(QRect(0,0,this->centralWidget()->width(),this->centralWidget()->height()));

		QParallelAnimationGroup *group = new QParallelAnimationGroup;
		group->addAnimation(animation);
		group->addAnimation(animation1);
		group->start();
	});
}
