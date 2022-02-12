#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QPushButton>

class SwitchButton : public QPushButton
{
    Q_OBJECT

public:
    explicit SwitchButton(QWidget *parent = nullptr);
    void setBottonColors(const QColor on = Qt::green, const QColor off = Qt::gray);
    void setTextColors(const QColor on = Qt::gray, const QColor off = Qt::gray);
    void setLabels(const QString on = QString(tr("ON")), const QString off = QString(tr("OFF")));

protected:
    void paintEvent(QPaintEvent *event);

    QColor mBtnColorOn;
    QColor mBtnColorOff;
    QString mBtnLabelOn;
    QString mBtnLabelOff;
    QColor mLabelColorOn;
    QColor mLabelColorOff;
};

#endif // SWITCHBUTTON_H
