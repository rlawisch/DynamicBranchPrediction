#include "pipeline.h"

Pipeline::Pipeline(ProgramMemory* programMemory)
{
    this->programMemory = programMemory;
}

void Pipeline::step()
{
    this->programCounter++;

    if(this->instructionWB)
        this->instructionWB->runWB();

    this->instructionWB = this->instructionMEM;

    if(this->instructionEX)
        this->instructionEX->runEX();
    this->instructionMEM = this->instructionEX;

    if(this->instructionID)
        this->instructionID->runID();
    this->instructionEX = this->instructionID;

    this->instructionID = this->instructionIF;

    this->instructionIF = this->programMemory->fetch(programCounter);
}

void Pipeline::run()
{
    while(this->isRunning)
    {
        this->step();
    }
}
