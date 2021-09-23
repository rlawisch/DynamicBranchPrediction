#ifndef BEQ_H
#define BEQ_H

#include "instruction.h"

class Beq : public Instruction
{
public:
    Beq(QString operator1, QString operator2, int destination, RegisterBank* registerBank);
    void runID();
    void runEX();
    void runWB();

private:
    QString operator1, operator2;
    int destination;
    unsigned char operator1Content, operator2Content;
    bool shouldBranch;
};

#endif // BEQ_H
