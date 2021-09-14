#ifndef REGISTERBANK_H
#define REGISTERBANK_H


class RegisterBank
{
public:
    RegisterBank();
    unsigned char getRegister(unsigned char address);
    void setRegister(unsigned char address, unsigned char value);

private:
    unsigned char registers[32];
};

#endif // REGISTERBANK_H
