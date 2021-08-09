#pragma once
#include "visa.h"
#include <string>
#include <iostream>
using namespace std;
class Passport
{
private:
    string name, lname, serial;
public:
    Passport() :name("Null"), lname("Null"), serial("Null") {}
    Passport(const string& name, const string& lname, const string& serial);
    virtual ~Passport() {}
    virtual void Show() const;
};

class ForeignPassport : public Passport
{
private:
    enum { VisaSize = 10 };
    string id;
    string visa[VisaSize];
public:
    ForeignPassport() {}
    ForeignPassport(const string& name, const string& lname, const string& serial, const string* visa, const string& id);
    ForeignPassport(const Passport& p, const string* visa, const string& id);
    virtual void Show() const;
};