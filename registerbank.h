#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class RegisterBank
{
public:
    RegisterBank();
    unsigned char getRegister(QString address);
    void setRegister(QString address, unsigned char value);
    bool isValidRegisterAddress(QString address);

private:
    QMap<QString, unsigned char> registers;
    QRegularExpressionValidator *addressValidator;
};

#endif // REGISTERBANK_H
