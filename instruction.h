#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <qstring.h>

#include "registerbank.h"

class Instruction
{
public:
    Instruction(QString opcode, unsigned char destination, RegisterBank* registerBank)
    {
        this->opcode = opcode;
        this->destination = destination;
        this->registerBank = registerBank;
    }

    virtual void runID() = 0;
    virtual void runEX() = 0;
    virtual void runWB() = 0;

    unsigned char getDestination()
    {
        return this->destination;
    }

protected:
    QString opcode;
    unsigned char destination;
    RegisterBank* registerBank;
};

#endif // INSTRUCTION_H
