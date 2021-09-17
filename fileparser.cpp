#include "fileparser.h"

FileParser::FileParser(RegisterBank *registerBank)
{
    QRegularExpression lineRegex(
        "\\s*((ADD|SUB)\\s+\\$t\\d{1,2}(\\s*,\\s*\\$t\\d{1,2}){2}|(ADDI|SUBI|BEQ)\\s+\\$t\\d{1,2}\\s*,\\s*\\$t\\d{1,2}\\s*,\\s*\\d{1,3}|B\\s+-?\\d{1,3})\\s*[^\\n]*",
        QRegularExpression::CaseInsensitiveOption
    );
    this->validator = new QRegularExpressionValidator(lineRegex, 0);
    this->registerBank = registerBank;
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
    QStringList tokens = textLine.replace(QRegularExpression("\\s+"), " ").split(" ");

    if(tokens[0].toUpper().startsWith("ADDI"))
    {
        return new AddI(tokens[1].at(2).digitValue(), tokens[2].at(2).digitValue(), tokens[3].toInt(), this->registerBank);
    }
    else if(tokens[0].toUpper().startsWith("ADD"))
    {
        return new Add(tokens[1].at(2).digitValue(), tokens[2].at(2).digitValue(), tokens[3].at(2).digitValue(), this->registerBank);
    }
    else if(tokens[0].toUpper().startsWith("SUBI"))
    {
        return new SubI(tokens[1].at(2).digitValue(), tokens[2].at(2).digitValue(), tokens[3].toInt(), this->registerBank);
    }
    else if(tokens[0].toUpper().startsWith("SUB"))
    {
        return new Sub(tokens[1].at(2).digitValue(), tokens[2].at(2).digitValue(), tokens[3].at(2).digitValue(), this->registerBank);
    }
    else if(tokens[0].toUpper().startsWith("BEQ"))
    {
        return new Beq(tokens[1].at(2).digitValue(), tokens[2].at(2).digitValue(), tokens[3].toInt(), this->registerBank);
    }
    else if(tokens[0].toUpper().startsWith("B"))
    {
        return new B(tokens[1].toInt(), this->registerBank);
    }
}
