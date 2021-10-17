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

    if(this->instructionWB != nullptr)
    {
        this->instructionWB->runWB();
        if (this->instructionWB->getOpcode().startsWith("B"))
        {
            this->checkInstructionsValidity();
        }
        int res = Statistics::GetInstance()->GetValidInstructionAmount();
        res++;
    }

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
    this->isRunning = true;
    while(this->isRunning)
    {
        this->step();
    }
}

Instruction* Pipeline::getNextInstruction()
{
    if (this->usePredictions &&
        this->instructionID &&
        this->instructionID->getValidity() &&
        this->instructionID->getOpcode() == "BEQ" &&
        TwoBitPredictor::GetInstance()->shouldBranchForLine(this->instructionID->getLineNumber()))
    {
        Beq* beq = (Beq*) this->instructionID;
        beq->setAnticipatedBranch();
        programCounter->Set(beq->getDestination());
    }
    Instruction* nextInstruction = this->programMemory->fetch(this->programCounter->Get());

    if (!(nextInstruction || this->instructionEX || this->instructionID || this->instructionIF ||  this->instructionMEM ||  this->instructionWB))
    {
        this->isRunning = false;
    }

    return nextInstruction;
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
