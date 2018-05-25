#ifndef DOUBLESPINBOX_H
#define DOUBLESPINBOX_H

#include <QWidget>
#include <QDoubleSpinBox>

class DoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT

public:
    DoubleSpinBox(QWidget *parent = Q_NULLPTR);
    virtual void stepBy(int steps);
    int ind=1;

public slots:
    void changeIncrement(int, int);

};

#endif // CUSTOMDOUBLESPINBOX_H
