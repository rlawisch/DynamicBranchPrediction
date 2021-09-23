#include "add.h"

Add::Add(QString destination, QString operator1, QString operator2, RegisterBank* registerBank) : Instruction("ADD", registerBank)
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Add::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Add::runEX()
{
    this->result = this->operator1Content + this->operator2Content;
}

void Add::runWB()
{
    registerBank->setRegister(this->destination, this->result);
}
