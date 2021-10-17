#ifndef B_H
#define B_H

#include "instruction.h"
#include "programcounter.h"

class B : public Instruction
{
public:
    B(int destination);
    void id();
    void ex();
    void wb();

private:
    int destination;
};

#endif // B_H
