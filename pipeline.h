#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"
#include "programmemory.h"

class Pipeline
{
public:
    Pipeline(ProgramMemory* programMemory);
    void step();
    void run();

private:
    bool isRunning = false;
    unsigned char programCounter = 0;
    ProgramMemory* programMemory;
    Instruction *instructionIF, *instructionID, *instructionEX, *instructionMEM, *instructionWB;
};

#endif // PIPELINE_H
