#include "SpinBox.h"
#include <QHBoxLayout>
#include "DoubleSpinBox.h"

//QStringList SpinBox::list_mtr= {QT_TR_NOOP("m") ,QT_TR_NOOP("km")};
QStringList SpinBox::list_time={QT_TR_NOOP("ms"),QT_TR_NOOP("s"),QT_TR_NOOP("min"),QT_TR_NOOP("hour"),QT_TR_NOOP("day")};
QStringList SpinBox::list_hertz={QT_TR_NOOP("Hz") ,QT_TR_NOOP("kHz"),QT_TR_NOOP("MHz"),QT_TR_NOOP("GHZ"),QT_TR_NOOP("THz")};
//QStringList SpinBox::list_kg ={QT_TR_NOOP("gr"), QT_TR_NOOP("kg"),QT_TR_NOOP("ton")};

std::map <int, int> SpinBox::m_mapTime ={
    {1,1000},{2,60},{3,60},{4,24}
};

std::map <SpinBox::WidgetMode,QStringList> SpinBox::m_mapMod = {
    {Frequency,list_hertz},{Time,list_time}
};

SpinBox::SpinBox(QWidget *parent)
    :QWidget(parent)
    ,doubleSpinBoxValue(new DoubleSpinBox())
    ,comboBoxUnit(new QComboBox())
{
    this->setMode(Frequency);
    this->setLayout(new QHBoxLayout());
    doubleSpinBoxValue->setFixedWidth(131);
    doubleSpinBoxValue->setDecimals(9);
    doubleSpinBoxValue->setMaximum(9999999999999999.999999999);
    doubleSpinBoxValue->setFixedHeight(20);
    this->layout()->addWidget(doubleSpinBoxValue);
    this->layout()->addWidget(comboBoxUnit);
}

SpinBox::~SpinBox()
{

}
void SpinBox::HertzIndexChanged(int index)
{
    doubleSpinBoxValue->setValue(doubleSpinBoxValue->value()*(pow(1000,(ind-index))));
    ind=index;
}

void SpinBox::TimeIndexChanged(int index)
{
    if(ind-index>0){
        while(ind>index){
            doubleSpinBoxValue->setValue(doubleSpinBoxValue->value()*m_mapTime[ind]);
                ind--;
            }
    }
     else if(ind-index<0){
        while(ind<index){
            doubleSpinBoxValue->setValue(doubleSpinBoxValue->value()/m_mapTime[ind+1]);
                ind++;
            }
     }
    ind=index;
}

SpinBox::WidgetMode SpinBox::mode() const
{
    return m_mode;
}

void SpinBox::setMode(const WidgetMode &mode)
{
    m_mode = mode;
    doubleSpinBoxValue->setValue(0.000000000);
    disconnect(comboBoxUnit,SIGNAL(currentIndexChanged(int)),this,SLOT(HertzIndexChanged(int)));
    if(m_mode == Time){
            comboBoxUnit->clear();
            this->comboBoxUnit->addItems(m_mapMod[m_mode]);
            connect(comboBoxUnit,SIGNAL(currentIndexChanged(int)),this,SLOT(TimeIndexChanged(int)));
            }
    else{
            disconnect(comboBoxUnit,SIGNAL(currentIndexChanged(int)),this,SLOT(TimeIndexChanged(int)));
            comboBoxUnit->clear();
            this->comboBoxUnit->addItems(m_mapMod[m_mode]);
            connect(comboBoxUnit,SIGNAL(currentIndexChanged(int)),this,SLOT(HertzIndexChanged(int)));
    }
}
