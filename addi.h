#ifndef ADDI_H
#define ADDI_H

#include "instruction.h"

class AddI : public Instruction
{
public:
    AddI(QString destination, QString operator1, unsigned char integer, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    QString destination;
    QString operator1;
    unsigned char integer;
    unsigned char operator1Content;
    unsigned char result;
};

#endif // ADDI_H
