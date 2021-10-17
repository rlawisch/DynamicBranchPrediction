#ifndef B_H
#define B_H

#include "instruction.h"
#include "programcounter.h"

class B : public Instruction
{
public:
    B(int destination, uint lineNumber);
    bool nextInstructionsAreValid();

private:
    void id();
    void ex();
    void wb();

    int destination;
};

#endif // B_H
