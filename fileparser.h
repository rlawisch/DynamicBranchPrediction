#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include <registerbank.h>
#include <instruction.h>
#include <add.h>
#include <addi.h>
#include <sub.h>
#include <subi.h>
#include <b.h>
#include <beq.h>

class FileParser
{
public:
    FileParser(RegisterBank *registerBank);
    QList<Instruction*> parse(QString fileName);

private:
    bool isValidLine(QString textLine);
    Instruction* parseLine(QString textLine);

    QRegularExpressionValidator *validator;
    RegisterBank *registerBank;
};

#endif // FILEPARSER_H
