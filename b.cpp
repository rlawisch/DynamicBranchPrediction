#include "b.h"

B::B(int destination) : Instruction("B")
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
