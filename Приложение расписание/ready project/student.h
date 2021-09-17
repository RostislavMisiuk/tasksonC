#pragma once
class Student {
private:
	string firstname;
	string lastname;
	string patronymic;
	unsigned int datebirth;
	unsigned int group_id;

public:
	Student() {};
	Student(string firstname, string lastname, string patronymic, int datebirth, int group_id) {
		this->firstname = firstname;
		this->lastname = lastname;
		this->patronymic = patronymic;
		this->datebirth = datebirth;
		this->group_id = group_id;
	}

	string getfirstname() {
		return firstname;
	}
	string getlastname() {
		return lastname;
	}
	string getpatronymic() {
		return patronymic;
	}
	unsigned int getdatebirth() {
		return datebirth;
	}
	void setfirstname(string& firstname) {
		this->firstname = firstname;
	}
	void setlastname(string& lastname) {
		this->lastname = lastname;
	}
	void setpatronymic(string& patronymic) {
		this->patronymic = patronymic;
	}
	void setdatebirth(unsigned int& datebirth) {
		this->datebirth = datebirth;
	}
	void setgroupid(unsigned int& group_id) {
		this->group_id = group_id;
	}
	unsigned int getGroupId() {
		return group_id;
	}

	friend istream& operator >> (istream& stream, Student& obj) {
		cout << "Имя: ";
		stream >> obj.firstname;
		cout << "Фамилия: ";
		stream >> obj.lastname;
		cout << "Отчество: ";
		stream >> obj.patronymic;
		cout << "Полное кол-во лет студенту: ";
		stream >> obj.datebirth;
		cout << "ID группы: ";
		stream >> obj.group_id;
		return stream;
	}

	friend ostream& operator<<(ostream& os, Student& obj) {
		os << "Имя студента : " << obj.firstname << endl;
		os << "Фамилия студента : " << obj.lastname << endl;
		os << "Отчество студента : " << obj.patronymic << endl;
		os << "Полное кол-во лет студенту : " << obj.datebirth << endl;
		os << "ID его группы : " << obj.group_id << endl;
		return os;
	}

};