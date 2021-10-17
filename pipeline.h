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
    void checkInstructionsValidity();

    bool isRunning = false;
    bool usePredictions;
    ProgramMemory* programMemory;
    Instruction *instructionIF = nullptr, *instructionID = nullptr, *instructionEX = nullptr, *instructionMEM = nullptr, *instructionWB = nullptr;
    ProgramCounter* programCounter;
};

#endif // PIPELINE_H
