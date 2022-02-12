#include "SwitchButton.h"
#include <QPainter>
#include <QDebug>
#include <QPaintEvent>
#include <QFontMetrics>

SwitchButton::SwitchButton(QWidget *parent) : QPushButton(parent)
{
    setCheckable(true);
    setBottonColors();
    setTextColors();
    setLabels();
}

void SwitchButton::setBottonColors(const QColor on, const QColor off)
{
    mBtnColorOn = on;
    mBtnColorOff = off;
}

void SwitchButton::setTextColors(const QColor on, const QColor off)
{
    mLabelColorOn = on;
    mLabelColorOff = off;
}

void SwitchButton::setLabels(const QString on, const QString off)
{
    mBtnLabelOn = on;
    mBtnLabelOff = off;
    setMinimumWidth(fontMetrics().boundingRect(mBtnLabelOff).width() + fontMetrics().boundingRect(mBtnLabelOff).width() + fontMetrics().boundingRect(mBtnLabelOff).height() * 2);
}

void SwitchButton::paintEvent(QPaintEvent *event)
{
    QPen pen;
    QString label;
    QColor btnColor;
    QColor labelColor;
    QBrush brush;
    QPoint textPosition;
    quint16 margin = 1;
    QPainter painter(this);
    QRect rect(0, 0, width(), height());

    Q_UNUSED(event);
    painter.setViewport(rect);
    painter.setWindow(0, 0, width(), height());
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    (isChecked()) ? (label = mBtnLabelOn, btnColor = mBtnColorOn, labelColor = mLabelColorOn) : (label = mBtnLabelOff, btnColor = mBtnColorOff, labelColor = mLabelColorOff);
    rect.setRect(margin, margin, width() - 2 * margin, height() - 2 * margin);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    pen.setWidth(2);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRoundedRect(rect, height() / 2, height() / 2);

    rect.setRect(margin * 3, margin * 3, width() - 6 * margin, height() - 6 * margin);
    brush.setColor(btnColor);
    painter.setBrush(brush);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.drawRoundedRect(rect, (height() - 6 * margin) / 2, (height() - 6 * margin) / 2);

    pen.setWidth(4);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    brush.setColor(Qt::white);
    painter.setBrush(brush);
    if (isChecked())
    {
        rect.setRect(width() + margin * 3 - height(), margin * 3, height() - 6 * margin, height() - 6 * margin);
    }
    else
    {
        rect.setRect(margin * 3, margin * 3, height() - 6 * margin, height() - 6 * margin);
    }
    painter.drawEllipse(rect);

    painter.setPen(labelColor);
    textPosition = rect.center() - QPoint(fontMetrics().boundingRect(label).width() / 2, 1 - fontMetrics().ascent() / 2);
    painter.drawText(textPosition, label);
}
