#pragma once
class Teacher {
private:
	int id;
	string firstname;
	string lastname;
	string patronymic;
	unsigned int datebirth;
	int kafedra_id;
public:
	Teacher() {};
	Teacher(int id, string firstname, string lastname, string patronymic, int datebirth, int kafedra_id) {
		this->id = id;
		this->firstname = firstname;
		this->lastname = lastname;
		this->patronymic = patronymic;
		this->datebirth = datebirth;
		this->kafedra_id = kafedra_id;
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
	int getKafedraId() {
		return kafedra_id;
	}
	void setKafedraID(int& kafedra_id) {
		this->kafedra_id = kafedra_id;
	}
	int getId() {
		return id;
	}
	void setid(int& id) {
		this->id = id;
	}

	friend istream& operator >> (istream& stream, Teacher& obj) {
		cout << "ID: ";
		stream >> obj.id;
		cout << "Имя: ";
		stream >> obj.firstname;
		cout << "Фамилия: ";
		stream >> obj.lastname;
		cout << "Отчество ( при наличии ): ";
		stream >> obj.patronymic;
		cout << "Полное кол-во лет учителю: ";
		stream >> obj.datebirth;
		cout << "ID кафедры: ";
		stream >> obj.kafedra_id;
		return stream;
	}

	friend ostream& operator<<(ostream& os, Teacher& obj) { // оператор вывода
		os << "ID" << obj.id << endl;
		os << "Имя учителя: " << obj.firstname << endl;
		os << "Фамилия учителя: " << obj.lastname << endl;
		os << "Отчество учителя: " << obj.patronymic << endl;
		os << "Полное кол-во лет учителю: " << obj.datebirth << endl;
		os << "ID кафедры: " << obj.kafedra_id << endl;
		return os;
	}
};