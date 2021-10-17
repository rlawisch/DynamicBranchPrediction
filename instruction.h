#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QString>

#include "registerbank.h"

class Instruction
{
public:
    Instruction(QString opcode)
    {
        this->opcode = opcode;
        this->registerBank = RegisterBank::GetInstance();
    }

    virtual void runID() = 0;
    virtual void runEX() = 0;
    virtual void runWB() = 0;

protected:
    QString opcode;
    RegisterBank* registerBank;
};

#endif // INSTRUCTION_H
