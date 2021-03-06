#ifndef SUB_H
#define SUB_H

#include "instruction.h"

class Sub : public Instruction
{
public:
    Sub(QString destination, QString operator1, QString operator2, uint lineNumber);

private:
    void id();
    void ex();
    void wb();

    QString destination;
    QString operator1, operator2;
    unsigned char operator1Content, operator2Content;
    unsigned char result;
};

#endif // SUB_H
