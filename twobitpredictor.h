#ifndef TWOBITPREDICTOR_H
#define TWOBITPREDICTOR_H

#include <QMap>

class TwoBitPredictor
{
public:
    // avoid replication of an object
    TwoBitPredictor(const TwoBitPredictor&) = delete;
    static TwoBitPredictor* GetInstance();

    void incrementForLine(uint lineNumber);
    void decrementForLine(uint lineNumber);
    bool shouldBranchForLine(uint lineNumber);

    void Reset();

private:
    // private constructor to ensure singleton
    TwoBitPredictor();

    static TwoBitPredictor *instance;

    QMap<uint, unsigned char> counters;
};

#endif // TWOBITPREDICTOR_H
