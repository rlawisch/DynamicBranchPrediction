#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction
{
public:
    Add(QString destination, QString operator1, QString operator2, uint lineNumber);

private:
    void id();
    void ex();
    void wb();

    QString destination;
    QString operator1, operator2;
    unsigned char operator1Content, operator2Content;
    unsigned char result;
};

#endif // ADD_H
