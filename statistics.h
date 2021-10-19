#ifndef STATISTICS_H
#define STATISTICS_H

#include <QObject>
#include <QtConcurrent/QtConcurrent>

struct InstructionInstance
{
    QString opcode;
    bool isValid;
};

class Statistics
{
public:
    // avoid replication of an object
    Statistics(const Statistics&) = delete;
    static Statistics* GetInstance();

    void SetInstruction(QString opcode, bool isValid);

    QList<InstructionInstance> GetInstructions();
    QList<InstructionInstance> GetValidInstructions();
    QList<InstructionInstance> GetInvalidInstructions();

    int GetInstructionAmount();
    int GetValidInstructionAmount();
    int GetInvalidInstructionAmount();

    void Reset();
private:
    // private constructor to ensure singleton
    Statistics();
    static Statistics *instance;

    QList<InstructionInstance> allInstructions;
    int invalidInstructionAmount;
    int validInstructionAmount;

    void resetInstructionCounter();
};

#endif // STATISTICS_H
