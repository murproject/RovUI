#include "RovTelimetryWidget.hpp"
#include "RovSingleton.hpp"

#include <QVBoxLayout>

RovTelimetryWidget::RovTelimetryWidget(QWidget* parent)
    : QWidget(parent)
    , m_pitch(new QLabel("Крен: -", this))
    , m_roll(new QLabel("Диффирент: -", this))
    , m_yaw(new QLabel("Курс: -", this))
    , m_depth(new QLabel("Глубина: -", this))
    , m_regulatorsFeedback(new QLabel("Регуляторы: -", this))
    , m_ammeter(new QLabel("Амперметр: - ", this))
    , m_voltmeter(new QLabel("Вльтметр: -", this))
{
    createConnections();
    createLayout();
}

void RovTelimetryWidget::createConnections()
{
    connect(RovSingleton::instance(), &RovSingleton::telimetryUpdated, this,
        &RovTelimetryWidget::onTelimetryUpdate);
}

void RovTelimetryWidget::createLayout()
{
    QVBoxLayout* layout = new QVBoxLayout;
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(m_pitch.data());
    layout->addWidget(m_roll.data());
    layout->addWidget(m_yaw.data());
    layout->addWidget(m_depth.data());
    layout->addWidget(m_regulatorsFeedback.data());
    layout->addWidget(m_ammeter.data());
    layout->addWidget(m_voltmeter.data());

    layout->addWidget(spacer);

    setLayout(layout);
}

void RovTelimetryWidget::onTelimetryUpdate()
{
    RovTelimetry& rt = RovSingleton::instance()->telimetry();
    m_pitch.data()->setText(QString(tr("Крен: %1").arg(rt.pitch)));
    m_yaw.data()->setText(QString(tr("Курс: %1").arg(rt.yaw)));
    m_roll.data()->setText(QString(tr("Диффирент: %1").arg(rt.roll)));
    m_regulatorsFeedback.data()->setText(
        QString(tr("Регуляторы: %1").arg(rt.regulatorsFeedback)));
    m_depth.data()->setText(QString(tr("Глубина: %1").arg(rt.depth)));
    m_ammeter.data()->setText(QString(tr("Амперметр: %1").arg(rt.ammeter)));
    m_voltmeter.data()->setText(QString(tr("Вольтметр: %1").arg(rt.voltmeter)));
}
