#include "statistics.h"

Statistics* Statistics::instance;

Statistics::Statistics()
{
    this->resetInstructionCounter();
}

Statistics* Statistics::GetInstance()
{
    if (!instance)
        instance = new Statistics;
    return instance;
}

void Statistics::SetInstruction(QString opcode, bool isValid)
{

    InstructionInstance receivedInstruction;
    receivedInstruction.opcode = opcode;
    receivedInstruction.isValid = isValid;

    this->allInstructions << receivedInstruction;

    if(isValid)
    {
        this->validInstructionAmount++;
    }
    else
    {
        this->invalidInstructionAmount++;
    }
}

QList<InstructionInstance> Statistics::GetInstructions()
{
    return this->allInstructions;
}
QList<InstructionInstance> Statistics::GetValidInstructions()
{
    QList<InstructionInstance> validInstructions;
    int instructionAmount = this->GetInstructionAmount();

    for (int i = 0; i < instructionAmount; i++)
    {
        if(this->allInstructions[i].isValid)
        {
            validInstructions << this->allInstructions[i];
        }
    }

    return validInstructions;
}
QList<InstructionInstance> Statistics::GetInvalidInstructions()
{
    QList<InstructionInstance> invalidInstructions;
    int instructionAmount = this->GetInstructionAmount();

    for (int i = 0; i < instructionAmount; i++)
    {
        if(!this->allInstructions[i].isValid)
        {
            invalidInstructions << this->allInstructions[i];
        }
    }

    return invalidInstructions;
}

int Statistics::GetInstructionAmount()
{
    return (this->validInstructionAmount + this->invalidInstructionAmount);
}
int Statistics::GetValidInstructionAmount()
{
    return this->validInstructionAmount;
}
int Statistics::GetInvalidInstructionAmount()
{
    return this->invalidInstructionAmount;
}

void Statistics::Reset()
{
    this->allInstructions.clear();
    this->resetInstructionCounter();
}

void Statistics::resetInstructionCounter()
{
    this->validInstructionAmount = 0;
    this->invalidInstructionAmount = 0;
}
