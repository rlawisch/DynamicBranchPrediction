#ifndef ADDI_H
#define ADDI_H

#include "instruction.h"

class AddI : public Instruction
{
public:
    AddI(QString destination, QString operator1, unsigned char integer, uint lineNumber);

private:
    void id();
    void ex();
    void wb();

    QString destination;
    QString operator1;
    unsigned char integer;
    unsigned char operator1Content;
    unsigned char result;
};

#endif // ADDI_H
