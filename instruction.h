#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QString>

#include "registerbank.h"

class Instruction
{
public:
    Instruction(QString opcode, uint lineNumber)
    {
        this->opcode = opcode;
        this->lineNumber = lineNumber;
        this->registerBank = RegisterBank::GetInstance();
        this->isValid = true;
    }

    void invalidate()
    {
        this->isValid = false;
    }

    void runID() {
        if (this->isValid)
            this->id();
    }

    void runEX()
    {
        if (this->isValid)
            this->ex();
    }

    void runWB()
    {
        if (this->isValid)
            this->wb();
    }

    QString getOpcode()
    {
        return this->opcode;
    }

    uint getLineNumber()
    {
        return this->lineNumber;
    }

protected:  
    virtual void id() = 0;
    virtual void ex() = 0;
    virtual void wb() = 0;

    QString opcode;
    bool isValid;
    uint lineNumber;
    RegisterBank* registerBank;
};

#endif // INSTRUCTION_H
