#include "programcounter.h"

ProgramCounter::ProgramCounter()
{
    this->pc = 0;
}
ProgramCounter& ProgramCounter::GetInstance()
{
    return pc_instance;
}
int ProgramCounter::Get()
{
    return this->pc;
}

void ProgramCounter::Add(int x)
{
    this->pc += x;
}

void ProgramCounter::Set(int x)
{
    this->pc = x;
}

void ProgramCounter::Reset()
{
    this->pc = 0;
}
