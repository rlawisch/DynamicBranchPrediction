#ifndef BEQ_H
#define BEQ_H

#include "instruction.h"

class Beq : public Instruction
{
public:
    Beq(unsigned char destination, unsigned char operator1, unsigned char operator2, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    unsigned char operator1, operator2;
    unsigned char operator1Content, operator2Content;
    bool shouldBranch;
};

#endif // BEQ_H
