#include "DoubleSpinBox.h"
#include <QLineEdit>
DoubleSpinBox::DoubleSpinBox(QWidget *parent)
    :QDoubleSpinBox(parent)
{
    QObject::connect(this->lineEdit(), SIGNAL(cursorPositionChanged(int, int)), this, SLOT(changeIncrement(int, int)));
}

void DoubleSpinBox::stepBy(int steps)
{
    QLineEdit *lEdit = this->lineEdit();
    int position = lEdit->cursorPosition() ;
    QDoubleSpinBox::stepBy(steps);
    lEdit->deselect();
    lEdit->setCursorPosition(position);
    int idx = lEdit->text().indexOf(",");
    if(position==0)
       position=1;
    if(ind<idx&&steps==1){
       position++;
       lEdit->setCursorPosition(position);
    }
    else if(ind>idx&&steps==-1){
       position--;
       lEdit->setCursorPosition(position);
    }
       ind=idx;
}

void DoubleSpinBox::changeIncrement(int oldV, int newV)
{
    Q_UNUSED(oldV)
    int idx = this->lineEdit()->text().indexOf(",");
    if(idx < newV)
        --newV;
    if(newV==0)
        newV=1;
    this->setSingleStep(std::pow(10, idx - newV ));
}
