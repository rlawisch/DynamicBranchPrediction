#include "registerbank.h"

RegisterBank::RegisterBank()
{

}

unsigned char RegisterBank::getRegister(unsigned char address)
{
    if(address < 32)
        return this->registers[address];
    else
        return 0;
}

void RegisterBank::setRegister(unsigned char address, unsigned char value)
{
    if((address > 0) && (address < 32))
    {
        this->registers[address] = value;
    }
}
