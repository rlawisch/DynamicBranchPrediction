#ifndef BEQ_H
#define BEQ_H

#include "instruction.h"
#include "programcounter.h"
#include "twobitpredictor.h"

class Beq : public Instruction
{
public:
    Beq(QString operator1, QString operator2, int destination, uint lineNumber);
    int getDestination();
    void setAnticipatedBranch();
    bool nextInstructionsAreValid();

private:
    void id();
    void ex();
    void wb();

    QString operator1, operator2;
    int destination;
    unsigned char operator1Content, operator2Content;
    bool shouldBranch;
    bool anticipatedBranch;
};

#endif // BEQ_H
