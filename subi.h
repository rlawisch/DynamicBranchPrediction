#ifndef SUBI_H
#define SUBI_H

#include "instruction.h"

class SubI : public Instruction
{
public:
    SubI(unsigned char destination, unsigned char operator1, unsigned char integer, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    unsigned char operator1, integer;
    unsigned char operator1Content;
    unsigned char result;
};

#endif // SUBI_H
