#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class RegisterBank
{
public:
    // avoid replication of an object
    RegisterBank(const RegisterBank&) = delete;
    static RegisterBank* GetInstance();

    unsigned char getRegister(QString address);
    void setRegister(QString address, unsigned char value);
    bool isValidRegisterAddress(QString address);

private:
    // private constructor to ensure singleton
    RegisterBank();

    static RegisterBank *instance;
    QMap<QString, unsigned char> registers;
    QRegularExpressionValidator *addressValidator;
};

#endif // REGISTERBANK_H
