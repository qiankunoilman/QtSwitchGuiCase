#pragma once

#include <QWidget>
#include "ui_CustomSplashWidget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QPropertyAnimation>

#pragma  excution_character_set("utf-8")

//�ɽ������ֲ�ͼ��ʽչʾ��������Ϣ��չʾ�������ģ����ؽ���չʾ����
class CustomSplashWidget : public QWidget
{
	Q_OBJECT

public:
	CustomSplashWidget(QWidget *parent = Q_NULLPTR);
	~CustomSplashWidget();
public:
	void SetMainWindow(QWidget* widget);
	void SetInitialProgress(int progress);
	void SetInitialInfo(QString intialinfo,int level);
protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual  void closeEvent(QCloseEvent *event);
private:
	Ui::CustomSplashWidget ui;
	int    m_curpic_index;
	QStringList  m_piclist;
	QTimer  m_timer;
	QWidget*  m_MainWindow;
	QTimer m_moni;
	QStringList  m_info;
	int m_index;
	int m_progress;
};
