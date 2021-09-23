#ifndef B_H
#define B_H

#include "instruction.h"

class B : public Instruction
{
public:
    B(int destination, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    int destination;
};

#endif // B_H
