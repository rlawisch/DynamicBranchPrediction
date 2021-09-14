#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include <instruction.h>

class FileParser
{
public:
    FileParser();
    QList<Instruction*> parse(QString fileName);

private:
    bool isValidLine(QString textLine);
    Instruction* parseLine(QString textLine);

    QRegularExpressionValidator *validator;
};

#endif // FILEPARSER_H
