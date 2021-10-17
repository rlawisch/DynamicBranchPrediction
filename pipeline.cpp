#include "pipeline.h"

Pipeline::Pipeline(ProgramMemory* programMemory, bool usePredictions)
{
    this->programMemory = programMemory;
    this->usePredictions = usePredictions;
    this->programCounter = ProgramCounter::GetInstance();
}

void Pipeline::step()
{
    this->programCounter->Add(1);

    if(this->instructionWB)
    {
        this->instructionWB->runWB();
        if (this->instructionWB->getOpcode().startsWith("B"))
        {
            this->checkInstructionsValidity();
        }
    }
    else
        this->isRunning = false;

    this->instructionWB = this->instructionMEM;

    if(this->instructionEX)
        this->instructionEX->runEX();
    this->instructionMEM = this->instructionEX;

    if(this->instructionID)
        this->instructionID->runID();
    this->instructionEX = this->instructionID;

    this->instructionID = this->instructionIF;

    this->instructionIF = this->getNextInstruction();
}

void Pipeline::run()
{
    while(this->isRunning)
    {
        this->step();
    }
}

Instruction* Pipeline::getNextInstruction()
{
    if (this->usePredictions &&
        this->instructionID->getValidity() &&
        this->instructionID->getOpcode() == "BEQ" &&
        TwoBitPredictor::GetInstance()->shouldBranchForLine(this->instructionID->getLineNumber()))
    {
        Beq* beq = (Beq*) this->instructionID;
        beq->setAnticipatedBranch();
        programCounter->Set(beq->getDestination());
    }

    return this->programMemory->fetch(this->programCounter->Get());
}

void Pipeline::checkInstructionsValidity()
{
    Beq* beq = (Beq*) this->instructionWB;
    if (!beq->nextInstructionsAreValid())
    {
        this->instructionMEM->invalidate();
        this->instructionEX->invalidate();
        this->instructionID->invalidate();
        this->instructionIF->invalidate();
    }
}
