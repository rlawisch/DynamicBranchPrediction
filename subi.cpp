#include "subi.h"

SubI::SubI(unsigned char destination, unsigned char operator1, unsigned char integer, RegisterBank* registerBank) : Instruction("SUBI", destination, registerBank)
{
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
