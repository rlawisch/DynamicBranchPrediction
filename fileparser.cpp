#include "fileparser.h"

FileParser::FileParser()
{
    QRegularExpression lineRegex(
        "\\s*((ADD|SUB)\\s+\\$t\\d(\\s*,\\s*\\$t\\d){2}|(ADDI|SUBI|BEQ)\\s+\\$t\\d\\s*,\\s*\\$t\\d\\s*,\\s*\\d|B\\s+-?\\d)\\s*[^\\n]*",
        QRegularExpression::CaseInsensitiveOption
    );
    this->validator = new QRegularExpressionValidator(lineRegex, 0);
}

QList<Instruction*> FileParser::parse(QString code)
{
    QList<Instruction*> instructionList;

    uint lineCounter = 0;

    QStringList splited = code.split('\n');
    QStringListIterator it(splited);

    while(it.hasNext())
    {
        QString line = it.next();
        if((lineCounter++ < 256) && (this->isValidLine(line)))
        {
            Instruction* instructionRead = this->parseLine(line);
            instructionList.append(instructionRead);
        }
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
    QStringList tokens = textLine.replace(QRegularExpression("\\s+"), " ").remove(',').split(" ");

    if(tokens[0].toUpper().startsWith("ADDI"))
    {
        return new AddI(tokens[1], tokens[2], tokens[3].toInt());
    }
    else if(tokens[0].toUpper().startsWith("ADD"))
    {
        return new Add(tokens[1], tokens[2], tokens[3]);
    }
    else if(tokens[0].toUpper().startsWith("SUBI"))
    {
        return new SubI(tokens[1], tokens[2], tokens[3].toInt());
    }
    else if(tokens[0].toUpper().startsWith("SUB"))
    {
        return new Sub(tokens[1], tokens[2], tokens[3]);
    }
    else if(tokens[0].toUpper().startsWith("BEQ"))
    {
        return new Beq(tokens[1], tokens[2], tokens[3].toInt());
    }
    else if(tokens[0].toUpper().startsWith("B"))
    {
        return new B(tokens[1].toInt());
    }

    return nullptr;
}
