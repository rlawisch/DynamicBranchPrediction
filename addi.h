#ifndef ADDI_H
#define ADDI_H

#include "instruction.h"

class AddI : public Instruction
{
public:
    AddI(QString destination, QString operator1, unsigned char integer);
    void id();
    void ex();
    void wb();

private:
    QString destination;
    QString operator1;
    unsigned char integer;
    unsigned char operator1Content;
    unsigned char result;
};

#endif // ADDI_H
