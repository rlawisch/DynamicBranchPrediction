#include "registerbank.h"

RegisterBank* RegisterBank::instance;

RegisterBank::RegisterBank()
{
    QRegularExpression addressRegex(
        "^\\$t\\d$",
        QRegularExpression::CaseInsensitiveOption
    );
    this->addressValidator = new QRegularExpressionValidator(addressRegex, 0);
    this->registers.clear();
}

RegisterBank* RegisterBank::GetInstance()
{
    if (!instance)
        instance = new RegisterBank;
    return instance;
}

unsigned char RegisterBank::getRegister(QString address)
{
    return this->registers.value(address, 0);
}

void RegisterBank::setRegister(QString address, unsigned char value)
{
    if(this->isValidRegisterAddress(address))
    {
        this->registers[address] = value;
    }
}

bool RegisterBank::isValidRegisterAddress(QString address)
{
    int pos = 0;
    return this->addressValidator->validate(address, pos) == QValidator::Acceptable;
}
