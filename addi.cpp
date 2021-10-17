#include "addi.h"

AddI::AddI(QString destination, QString operator1, unsigned char integer) : Instruction("ADDI")
{
    this->destination = destination;
    this->operator1 = operator1;
    this->integer = integer;
}

void AddI::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
}

void AddI::runEX()
{
    this->result = this->operator1Content + this->integer;
}

void AddI::runWB()
{
    registerBank->setRegister(this->destination, this->result);
}
