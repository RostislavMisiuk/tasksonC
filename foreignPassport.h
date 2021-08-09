#pragma once
#include "visa.h"
Passport::Passport(const string& _name, const string& _lname, const string& _serial)
{
    name = _name;
    lname = _lname;
    serial = _serial;
}
void Passport::Show() const
{
    cout << "���: " << name << endl;
    cout << "�������: " << lname << endl;
    cout << "�������� �����: " << serial << endl;
}
ForeignPassport::ForeignPassport(const string& name, const string& lname, const string& serial, const string* _visa, const string& _id)
    :Passport(name, lname, serial)
{
    for (int i = 0; i < VisaSize; ++i)
        visa[i] = _visa[i];
    id = _id;
}
ForeignPassport::ForeignPassport(const Passport& p, const string* _visa, const string& _id)
    :Passport(p)
{
    for (int i = 0; i < VisaSize; ++i)
        visa[i] = _visa[i];
    id = _id;
}
void ForeignPassport::Show() const
{
    Passport::Show();
    cout << "����� ������. ��������: " << id << endl;
    cout << "��������� ����: " << endl;
    for (int i = 0; i < VisaSize; ++i)
        if (visa[i] != "")
            cout << visa[i] << endl;
}