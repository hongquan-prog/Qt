#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>

class Battery : public QWidget
{
    Q_OBJECT

public:
    Battery(QWidget *parent = nullptr);
    void setPowerValue(int value);
    void setWarnValue(int value);
    int getPowerValue();
    int getWarnValue();
    void updateSize();
    virtual QSize sizeHint() const override;

protected:
    QColor mColorBackdrop;
    QColor mColorBorder;
    QColor mColorPower;
    QColor mColorWarning;
    int mPowerValue;
    int mWarnValue;

    quint16 mCapWidth;
    quint16 mCapHeight;
    quint16 mCapBeginX;
    quint16 mCapBeginY;
    quint16 mBatteryWidth;
    quint16 mBatteryHeight;
    quint16 mBatteryBeginX;
    quint16 mBatteryBeginY;
    quint16 mPenWidth;
    quint16 mBorderSpace;

    void paintEvent(QPaintEvent *event) override;

signals:
    void powerValueChanged(int);
};

#endif // BATTERY_H
