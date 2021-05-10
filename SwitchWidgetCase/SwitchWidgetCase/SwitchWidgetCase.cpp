#include "SwitchWidgetCase.h"

SwitchWidgetCase::SwitchWidgetCase(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_solver = new SolverWidget();
	m_pinggu = new PingguWidget();
	m_qingdong = new QidongWidget();
	m_KuaiSuDanDaoWidget = new KuaiSuDanDaoWidget();
	m_ShiShiDanDaoWidget = new ShiShiDanDaoWidget();
	m_AnQuanBianJieWidget = new AnQuanBianJieWidget();
	m_DanDaoShuWidget = new DanDaoShuWidget();
	m_QIDongShuJuWidget = new QIDongShuJuWidget();

	ui.stackedWidget->addWidget(m_solver);
	ui.stackedWidget->addWidget(m_pinggu);
	ui.stackedWidget->addWidget(m_qingdong);
	ui.stackedWidget->addWidget(m_KuaiSuDanDaoWidget);
	ui.stackedWidget->addWidget(m_ShiShiDanDaoWidget);
	ui.stackedWidget->addWidget(m_AnQuanBianJieWidget);
	ui.stackedWidget->addWidget(m_DanDaoShuWidget);
	ui.stackedWidget->addWidget(m_QIDongShuJuWidget);

	ui.stackedWidget->setCurrentWidget(m_solver);

	
	QList<CustomButton *> childButtons = ui.widget->findChildren<CustomButton *>(QString(), Qt::FindDirectChildrenOnly);

	for each (CustomButton* btn in childButtons)
	{
		/*qDebug() << "btn name: " << btn->objectName() << "\n";*/
		connect(btn, &CustomButton::CustomClickSignal, this, [=](int index) {ChangeCurModule(index);});
	}
}

void SwitchWidgetCase::ChangeCurModule(int index)
{
	if (is_animatinl_over == false) {
		return;
	}
	//qDebug() << "btn index:   " << index << "\n";
	//��ȡ��ǰ��ʾҵ��ģ�����
	int cur_show_index = ui.stackedWidget->currentIndex();

	int cur_page_x_start, cur_page_y_start, cur_page_x_end, cur_page_y_end = 0;
	int next_page_x_start, next_page_y_start, next_page_x_end, next_page_y_end = 0;
	if (index == cur_show_index) {
		//���ǵ�ǰҳ�����л�
		return;
	}
	else if (index < cur_show_index) {
		//�����ǰҳ֮ǰ��ҳ,��ǰҳ�����ƶ�
		cur_page_x_start = 0;
		cur_page_y_start = 0;

		cur_page_x_end = m_solver->width();
		cur_page_y_end = 0;

		next_page_x_start = -m_solver->width();
		next_page_y_start = 0;

		next_page_x_end = 0;
		next_page_y_end = 0;
	}
	else if (index > cur_show_index) {
		//�����ǰҳ֮���ҳ,��ǰҳ�����ƶ�
		cur_page_x_start = 0;
		cur_page_y_start = 0;

		cur_page_x_end = -m_solver->width();
		cur_page_y_end = 0;

		next_page_x_start = m_solver->width();
		next_page_y_start = 0;

		next_page_x_end = 0;
		next_page_y_end = 0;
	}

	is_animatinl_over = false;

	QWidget*  cur_widget = ui.stackedWidget->currentWidget();

	//�Ե�ǰҳ���ö���Ч��
	/*QPropertyAnimation **/animation = new QPropertyAnimation(cur_widget, "geometry");
	animation->setDuration(1300);
	animation->setStartValue(QRect(cur_page_x_start, cur_page_y_start, m_solver->width(), m_solver->height()));
	animation->setEndValue(QRect(cur_page_x_end, cur_page_y_end, m_solver->width(), m_solver->height()));


	//��ȡ��һҳ�����ö���Ч��
	/*QLabel **/label = new QLabel(ui.stackedWidget);
	label->resize(m_solver->size());

	ui.stackedWidget->widget(index)->resize(m_solver->size());

	//m_pinggu->resize(m_solver->size());
	label->setPixmap(ui.stackedWidget->widget(index)->grab());
	label->show();

	/*QPropertyAnimation **/animation1 = new QPropertyAnimation(label, "geometry");
	animation1->setDuration(1300);
	animation1->setStartValue(QRect(next_page_x_start, next_page_y_start, m_solver->width(), m_solver->height()));
	animation1->setEndValue(QRect(next_page_x_end, next_page_y_end, m_solver->width(), m_solver->height()));

	/*QParallelAnimationGroup **/group = new QParallelAnimationGroup;
	group->addAnimation(animation);
	group->addAnimation(animation1);
	group->start(QAbstractAnimation::DeleteWhenStopped);

	connect(animation, &QPropertyAnimation::valueChanged, this, [=](const QVariant &value) {
		QRect GemetryValue = value.value<QRect>();
		//qDebug() << "iconValue:" << iconValue << "\n";
		if (GemetryValue == QRect(cur_page_x_end, cur_page_y_end, m_solver->width(), m_solver->height())) {

			ui.stackedWidget->setCurrentIndex(index);
			//�ƶ�����ͷ���ʱ��Դ
			delete label; label = nullptr;
			is_animatinl_over = true;
		}
	});
}
