#include "subi.h"

SubI::SubI(QString destination, QString operator1, unsigned char integer) : Instruction("SUBI")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->integer = integer;
}

void SubI::id()
{
    this->operator1Content = registerBank->getRegister(operator1);
}

void SubI::ex()
{
    this->result = this->operator1Content - this->integer;
}

void SubI::wb()
{
    registerBank->setRegister(this->destination, this->result);
}
