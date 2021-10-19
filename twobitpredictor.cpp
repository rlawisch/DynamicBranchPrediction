#include "twobitpredictor.h"

TwoBitPredictor* TwoBitPredictor::instance;

TwoBitPredictor::TwoBitPredictor()
{
    this->counters.clear();
}

TwoBitPredictor* TwoBitPredictor::GetInstance()
{
    if (!instance)
        instance = new TwoBitPredictor;
    return instance;
}

void TwoBitPredictor::incrementForLine(uint lineNumber)
{
    if (this->counters[lineNumber] < 3)
        this->counters[lineNumber]++;
}

void TwoBitPredictor::decrementForLine(uint lineNumber)
{
    if (this->counters[lineNumber] > 0)
        this->counters[lineNumber]--;
}

bool TwoBitPredictor::shouldBranchForLine(uint lineNumber)
{
    return this->counters[lineNumber] >= 2;
}

void TwoBitPredictor::Reset()
{
    this->counters.clear();
}
