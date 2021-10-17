#ifndef SUBI_H
#define SUBI_H

#include "instruction.h"

class SubI : public Instruction
{
public:
    SubI(QString destination, QString operator1, unsigned char integer, uint lineNumber);

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

#endif // SUBI_H
