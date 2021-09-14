#include "add.h"

Add::Add(unsigned char destination, unsigned char operator1, unsigned char operator2, RegisterBank* registerBank) : Instruction("ADD", destination, registerBank)
{
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
