#ifndef SUB_H
#define SUB_H

#include "instruction.h"

class Sub : public Instruction
{
public:
    Sub(unsigned char destination, unsigned char operator1, unsigned char operator2, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    unsigned char operator1, operator2;
    unsigned char operator1Content, operator2Content;
    unsigned char result;
};

#endif // SUB_H
