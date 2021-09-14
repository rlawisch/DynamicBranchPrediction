#include "beq.h"

Beq::Beq(unsigned char destination, unsigned char operator1, unsigned char operator2, RegisterBank* registerBank) : Instruction("BEQ", destination, registerBank)
{
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Beq::runID()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Beq::runEX()
{
    this->shouldBranch = this->operator1Content == this->operator2Content;
}

void Beq::runWB()
{
    //registerBank->setRegister(this->destination, this->result);
}
