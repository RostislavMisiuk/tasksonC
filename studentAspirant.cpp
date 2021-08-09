#include <iostream>
using namespace std;
class student {
private:
	string name;
	string surname;
	string group;
public:
	student();
	void setName(string name) { this->name = name; }
	void setSurname(string surname) { this->surname = surname; }
	void setGroup(string group) { this->group = group; }
	string getName() { return name; }
	string getSurname() { return surname; }
	string getGroup(){ return group; }

};
class Aspirant : public student {
private:
	string aspirant;
public:
	Aspirant();
	void workingAspirant(string aspirant) { this->aspirant = aspirant; }
	string getWorkingAspirant() { return aspirant; }

};