#include "Battery.h"
#include <QPainter>
#include <QBrush>

Battery::Battery(QWidget *parent) : QWidget(parent)
{
    mColorBorder = Qt::black;
    mColorPower = Qt::green;
    mColorWarning = Qt::red;
    mColorBackdrop = Qt::gray;
    mPowerValue = 100;
    mWarnValue = 20;
}

void Battery::updateSize()
{
    mPenWidth = 2;
    mCapWidth = width() / 30;
    mCapHeight = height() / 2;
    mBatteryBeginX = mPenWidth / 2;
    mBatteryBeginY = mPenWidth / 2;
    mBatteryWidth = width() - mCapWidth - mPenWidth * 4 / 2;
    mBatteryHeight = height() - mPenWidth * 2 / 2;
    mCapBeginX = mBatteryBeginX + mBatteryWidth + mPenWidth;
    mCapBeginY = height() / 4;
    mBorderSpace = mPenWidth * 2;
}

void Battery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPen pen;
    QBrush brush;
    QPainter painter(this);
    QRect rect(0, 0, width(), height());

    updateSize();
    brush.setStyle(Qt::SolidPattern);

    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);

    painter.setViewport(rect);
    painter.setWindow(0, 0, width(), height());
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //绘制圆角矩形边框
    pen.setWidth(mPenWidth);
    pen.setColor(mColorBackdrop);
    painter.setPen(pen);
    rect.setRect(mBatteryBeginX, mBatteryBeginY, mBatteryWidth, mBatteryHeight);
    painter.drawRoundedRect(rect, 5, 5);

    // 绘制电池正极头
    brush.setColor(mColorBackdrop);
    painter.setBrush(brush);
    rect.setRect(mCapBeginX, mCapBeginY, mCapWidth - mPenWidth, mCapHeight);
    painter.drawRect(rect);
    rect.setRect(mCapBeginX, mCapBeginY, mCapWidth, mCapHeight);
    painter.drawRoundedRect(rect, 5, 5);

    // 绘制剩余电量
    if(mPowerValue > mWarnValue)
    {
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }
    else
    {
        brush.setColor(mColorWarning);
        pen.setColor(mColorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    rect.setRect(mBorderSpace + mBatteryBeginX,
                 mBorderSpace + mBatteryBeginY,
                 mBatteryWidth - 2 * mBorderSpace,
                 mBatteryHeight - 2 * mBorderSpace);
    painter.drawRoundedRect(rect, 3, 3);
}

void Battery::setPowerValue(int value)
{
    if((value >= 0) && (value <= 100))
    {
        mPowerValue = value;
        emit powerValueChanged(mPowerValue);
        repaint();
    }
}

int Battery::getPowerValue()
{
    return mPowerValue;
}

void Battery::setWarnValue(int value)
{
    if((value >= 0) && (value <= 100))
    {
        mWarnValue = value;
        repaint();
    }
}

int Battery::getWarnValue()
{
    return mWarnValue;
}

QSize Battery::sizeHint() const
{
    return QSize(this->height(), this->height() * 12 / 5);
}
