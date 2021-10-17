#include "b.h"

B::B(int destination, uint lineNumber) : Instruction("B", lineNumber)
{
    this->destination = destination;
}

void B::id()
{
}

void B::ex()
{
}

void B::wb()
{
   ProgramCounter::GetInstance()->Set(this->destination);
}
