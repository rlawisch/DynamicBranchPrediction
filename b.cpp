#include "b.h"

B::B(int destination) : Instruction("B")
{
    this->destination = destination;
}

void B::runID()
{
}

void B::runEX()
{
}

void B::runWB()
{
   ProgramCounter::GetInstance()->Set(this->destination);
}
