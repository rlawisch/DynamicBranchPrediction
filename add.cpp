#include "add.h"

Add::Add(QString destination, QString operator1, QString operator2) : Instruction("ADD")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Add::id()
{
    this->operator1Content = this->registerBank->getRegister(operator1);
    this->operator2Content = this->registerBank->getRegister(operator2);
}

void Add::ex()
{
    this->result = this->operator1Content + this->operator2Content;
}

void Add::wb()
{
    this->registerBank->setRegister(this->destination, this->result);
}
