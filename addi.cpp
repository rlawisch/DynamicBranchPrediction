#include "addi.h"

AddI::AddI(QString destination, QString operator1, unsigned char integer) : Instruction("ADDI")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->integer = integer;
}

void AddI::id()
{
    this->operator1Content = registerBank->getRegister(operator1);
}

void AddI::ex()
{
    this->result = this->operator1Content + this->integer;
}

void AddI::wb()
{
    registerBank->setRegister(this->destination, this->result);
}
