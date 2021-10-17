#include "beq.h"

Beq::Beq(QString operator1, QString operator2, int destination, uint lineNumber) : Instruction("BEQ", lineNumber)
{
    this->destination = destination;
    this->operator1 = operator1;
    this->operator2 = operator2;
}

void Beq::id()
{
    this->operator1Content = registerBank->getRegister(operator1);
    this->operator2Content = registerBank->getRegister(operator2);
}

void Beq::ex()
{
    this->shouldBranch = this->operator1Content == this->operator2Content;
}

void Beq::wb()
{
    if (this->shouldBranch)
        ProgramCounter::GetInstance()->Set(this->destination);
}

int Beq::getDestination()
{
    return this->destination;
}
