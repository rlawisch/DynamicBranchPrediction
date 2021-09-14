#include "addi.h"

AddI::AddI(unsigned char destination, unsigned char operator1, unsigned char integer, RegisterBank* registerBank) : Instruction("ADDI", destination, registerBank)
{
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
