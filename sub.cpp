#include "sub.h"

Sub::Sub(QString destination, QString operator1, QString operator2, RegisterBank* registerBank) : Instruction("SUB", registerBank)
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Sub::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Sub::runEX()
{
    this->result = this->operator1Content - this->operator2Content;
}

void Sub::runWB()
{
    registerBank->setRegister(this->destination, this->result);
}
