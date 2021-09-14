#include "fileparser.h"

FileParser::FileParser()
{
    QRegularExpression lineRegex("\\s*((ADD|SUB)\\s+\\d{1,2}(\\s*,\\s*\\d{1,2}){2}|(ADDI|SUBI|BEQ)\\s+\\d{1,2}\\s*,\\s*\\d{1,2}\\s*,\\s*\\d{1,3}|B\\s+\\d{1,3})\\s*");
    lineRegex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    this->validator = new QRegularExpressionValidator(lineRegex, 0);
}

QList<Instruction*> FileParser::parse(QString fileName)
{
    QList<Instruction*> instructionList;
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        unsigned int lineCounter = 0;
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if((lineCounter++ < 256) && (this->isValidLine(line)))
            {
                Instruction* instructionRead = this->parseLine(line);
                instructionList.append(instructionRead);
            }
        }
        inputFile.close();
    }
    return instructionList;
}

bool FileParser::isValidLine(QString textLine)
{
    int pos = 0;
    return (this->validator->validate(textLine, pos) == QValidator::Acceptable);
}

Instruction* FileParser::parseLine(QString textLine)
{
    if(textLine.startsWith("ADDI"))
    {

    }
    else if(textLine.startsWith("ADD"))
    {

    }
    else if(textLine.startsWith("SUBI"))
    {

    }
    else if(textLine.startsWith("SUB"))
    {

    }
    else if(textLine.startsWith("BEQ"))
    {

    }
    else if(textLine.startsWith("B"))
    {

    }
}
