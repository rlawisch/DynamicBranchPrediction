#include "statsdialog.h"

StatsDialog::StatsDialog(QWidget *parent) : QDialog(parent)
{    
    RegisterBank *rb = RegisterBank::GetInstance();
    Statistics *s = Statistics::GetInstance();

    QVBoxLayout *layout_ = new QVBoxLayout(this);

    QFormLayout *registersLayout = new QFormLayout(this);

    QFormLayout *statisticsLayout = new QFormLayout(this);

    for(int i = 0; i < 10; i++)
    {
        registersLayout->addRow("$t" + QString::number(i) + ":\t\t",
                                new QLabel(QString::number(rb->getRegister("$t" + QString::number(i))), this));
    }

    QList<InstructionInstance> instructions = s->GetInstructions();
    int instructionsAmount  = s->GetInstructionAmount();
    int invalidInstructions = s->GetInvalidInstructionAmount();

    statisticsLayout->addRow("Instructions:\t"        , new QLabel(QString::number(instructionsAmount)));
    statisticsLayout->addRow("Invalid Instructions:\t", new QLabel(QString::number(invalidInstructions)));

    layout_->addWidget(new QLabel("Registers:"));
    layout_->addLayout(registersLayout);
    layout_->addWidget(new QLabel("Statistics:"));
    layout_->addLayout(statisticsLayout);

    this->setLayout(layout_);

    this->setWindowTitle("BRTL Statistics");
}
