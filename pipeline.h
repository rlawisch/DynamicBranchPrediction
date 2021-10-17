#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"
#include "beq.h"
#include "programmemory.h"
#include "programcounter.h"
#include "twobitpredictor.h"

class Pipeline
{
public:
    Pipeline(ProgramMemory* programMemory, bool usePredictions);
    void step();
    void run();

private:
    Instruction* getNextInstruction();

    bool isRunning = false;
    bool usePredictions;
    ProgramMemory* programMemory;
    Instruction *instructionIF, *instructionID, *instructionEX, *instructionMEM, *instructionWB;
    ProgramCounter* programCounter;
};

#endif // PIPELINE_H
