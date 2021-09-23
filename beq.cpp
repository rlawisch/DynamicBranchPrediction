#include "beq.h"

Beq::Beq(QString operator1, QString operator2, int destination, RegisterBank* registerBank) : Instruction("BEQ", registerBank)
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Beq::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Beq::runEX()
{
    this->shouldBranch = this->operator1Content == this->operator2Content;
}

void Beq::runWB()
{
    //registerBank->setRegister(this->destination, this->result);
}
