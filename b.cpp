#include "b.h"

B::B(int destination, RegisterBank* registerBank) : Instruction("B", registerBank)
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
   ProgramCounter::GetInstance().Set(this->destination);
}
