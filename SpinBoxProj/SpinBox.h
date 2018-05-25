#ifndef SPINBOX_H
#define SPINBOX_H

#include <QWidget>
#include <QComboBox>
#include <QStringList>
class DoubleSpinBox;

namespace Ui {
class SpinBox;
}

class SpinBox : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(WidgetMode m_mode READ mode WRITE setMode NOTIFY modeChanged)
public:

    explicit SpinBox(QWidget *parent = 0);
    //Metre, Kg gibi ondalik modlarla da calisabilir durumda.
    enum WidgetMode {Time, Frequency};
    Q_ENUM(WidgetMode)
    virtual ~SpinBox();
    WidgetMode mode() const;
    void setMode(const WidgetMode &mode);

signals:
    void modeChanged(WidgetMode);

public slots:
    void HertzIndexChanged(int index);
    void TimeIndexChanged(int index);

private:
    WidgetMode m_mode;
    DoubleSpinBox *doubleSpinBoxValue;
    QComboBox * comboBoxUnit;
    int ind=0;
    static std::map <int, int> m_mapTime;
    static std::map <WidgetMode,QStringList>m_mapMod;
    static QStringList list_mtr,list_time,list_hertz,list_kg;
};
#endif // RSSSPINBOX_H
