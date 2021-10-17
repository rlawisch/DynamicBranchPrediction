#ifndef BEQ_H
#define BEQ_H

#include "instruction.h"
#include "programcounter.h"

class Beq : public Instruction
{
public:
    Beq(QString operator1, QString operator2, int destination, uint lineNumber);

private:
    void id();
    void ex();
    void wb();

    QString operator1, operator2;
    int destination;
    unsigned char operator1Content, operator2Content;
    bool shouldBranch;
};

#endif // BEQ_H
