#include "programmemory.h"

ProgramMemory::ProgramMemory(QList<Instruction*> instructions)
{
    this->instructions = instructions;
}

Instruction* ProgramMemory::fetch(unsigned char address)
{
    return (address < this->instructions.size() ? this->instructions.at(address) : nullptr);
}
