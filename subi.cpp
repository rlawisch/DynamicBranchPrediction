#include "subi.h"

SubI::SubI(QString destination, QString operator1, unsigned char integer) : Instruction("SUBI")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->integer = integer;
}

void SubI::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
}

void SubI::runEX()
{
    this->result = this->operator1Content - this->integer;
}

void SubI::runWB()
{
    registerBank->setRegister(this->destination, this->result);
}
