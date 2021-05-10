#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SwitchWidgetCase.h"
#include "SolverWidget.h"
#include "PingguWidget.h"
#include "QidongWidget.h"
#include "KuaiSuDanDaoWidget.h"
#include "ShiShiDanDaoWidget.h"
#include "AnQuanBianJieWidget.h"
#include "DanDaoShuWidget.h"
#include "QIDongShuJuWidget.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDebug>
#include <QLabel>

class SwitchWidgetCase : public QMainWindow
{
	Q_OBJECT

public:
	SwitchWidgetCase(QWidget *parent = Q_NULLPTR);
protected slots:
	void ChangeCurModule(int index);
private:
	Ui::SwitchWidgetCaseClass ui;
	//各切换子界面
	SolverWidget*   m_solver;
	PingguWidget*	m_pinggu;
	QidongWidget*	m_qingdong;
	KuaiSuDanDaoWidget* m_KuaiSuDanDaoWidget;
	ShiShiDanDaoWidget* m_ShiShiDanDaoWidget;
	AnQuanBianJieWidget* m_AnQuanBianJieWidget;
	DanDaoShuWidget* m_DanDaoShuWidget;
	QIDongShuJuWidget* m_QIDongShuJuWidget;

	//移动切换动画操作相关
	QPropertyAnimation *animation;
	QLabel *label;
	QPropertyAnimation *animation1;
	QParallelAnimationGroup *group;
	bool is_animatinl_over = true;//当前动画是否结束
};
