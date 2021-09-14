#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction
{
public:
    Add(unsigned char destination, unsigned char operator1, unsigned char operator2, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    unsigned char operator1, operator2;
    unsigned char operator1Content, operator2Content;
    unsigned char result;
};

#endif // ADD_H
