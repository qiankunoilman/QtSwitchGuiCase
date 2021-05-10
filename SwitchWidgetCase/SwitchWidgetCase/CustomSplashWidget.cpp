#include "CustomSplashWidget.h"

CustomSplashWidget::CustomSplashWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->resize(700, 540);

	m_piclist.append(R"(D:\MAKER\SwitchWidget\SwitchWidgetCase\test0.PNG)");
	m_piclist.append(R"(D:\MAKER\SwitchWidget\SwitchWidgetCase\test1.PNG)");
	m_piclist.append(R"(D:\MAKER\SwitchWidget\SwitchWidgetCase\test2.PNG)");
	m_piclist.append(R"(D:\MAKER\SwitchWidget\SwitchWidgetCase\test3.PNG)");


	
	m_info.append(QStringLiteral("网络环境检测..."));
	m_info.append(QStringLiteral("GPU加速硬件条件检测..."));
	m_info.append(QStringLiteral("本地mpi并行环境检测..."));
	m_info.append(QStringLiteral("加载流场解算模块..."));
	m_info.append(QStringLiteral("加载快速评估模块..."));
	m_info.append(QStringLiteral("加载气动设计模块..."));
	m_index = 0;
	m_progress = 0;

	m_curpic_index = 0;

	m_timer.start(1000);
	connect(&m_timer, &QTimer::timeout, this, [=] {
		if (m_curpic_index == 3)
		{
			m_curpic_index = 0;
		}
		else {
			m_curpic_index++;
		}

		//m_curpic_index = 0;

		this->update();
	});

	m_moni.start(500);
	connect(&m_moni, &QTimer::timeout, this, [=] {
		if (m_index == 5)
		{
			m_index = 0;
		}
		else {
			m_index++;
		}
		m_progress+=4;

		SetInitialProgress(m_progress);
		SetInitialInfo(m_info.at(m_index), m_index);
		if (m_progress == 96) {
			ui.label->setText(QStringLiteral("启动程序..."));
		}
		if (m_progress == 100)
		{
			this->close();
		}
	});

}

CustomSplashWidget::~CustomSplashWidget()
{
}

void CustomSplashWidget::SetMainWindow(QWidget * widget)
{
	m_MainWindow = widget;
}

void CustomSplashWidget::SetInitialProgress(int progress)
{
	ui.progressBar->setValue(progress);
}

void CustomSplashWidget::SetInitialInfo(QString intialinfo, int level)
{
	ui.label->setText(intialinfo);
	QString stylesheet;
	if (level == 1)
	{
		stylesheet = QString("QLabel{color:black;}");
		
	}else if(level == 2)
	{
		stylesheet = QString("QLabel{color:orange;}");
	}
	else if (level == 3) 
	{
		stylesheet = QString("QLabel{color:red;}");
	}

	ui.label->setStyleSheet(stylesheet);
}

void CustomSplashWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.drawPixmap(ui.widget->rect(), QPixmap(m_piclist.at(m_curpic_index)));


	//return QWidget::paintEvent(event);
}

void CustomSplashWidget::closeEvent(QCloseEvent * event)
{
	//程序主界面淡入
	QPropertyAnimation *animation = new QPropertyAnimation(m_MainWindow, "windowOpacity");
	animation->setDuration(1000);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	//m_MainWindow->resize(900,733);
	//m_MainWindow->show();
	//m_MainWindow->showMaximized();
	m_MainWindow->showFullScreen();

	return QWidget::closeEvent(event);
}
