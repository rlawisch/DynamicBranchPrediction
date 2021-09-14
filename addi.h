#ifndef ADDI_H
#define ADDI_H

#include "instruction.h"

class AddI : public Instruction
{
public:
    AddI(unsigned char destination, unsigned char operator1, unsigned char integer, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    unsigned char operator1, integer;
    unsigned char operator1Content;
    unsigned char result;
};

#endif // ADDI_H
