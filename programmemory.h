#ifndef PROGRAMMEMORY_H
#define PROGRAMMEMORY_H

#include<QList>

#include<instruction.h>

class ProgramMemory
{
public:
    ProgramMemory(QList<Instruction*> instructions);

    Instruction* fetch(unsigned char address);

private:
    QList<Instruction*> instructions;
};

#endif // PROGRAMMEMORY_H
