#include "sub.h"

Sub::Sub(QString destination, QString operator1, QString operator2) : Instruction("SUB")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Sub::id()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Sub::ex()
{
    this->result = this->operator1Content - this->operator2Content;
}

void Sub::wb()
{
    registerBank->setRegister(this->destination, this->result);
}
