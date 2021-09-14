#ifndef B_H
#define B_H

#include "instruction.h"

class B : public Instruction
{
public:
    B(unsigned char destination, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();
};

#endif // B_H
