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
		cout << "���: ";
		stream >> obj.firstname;
		cout << "�������: ";
		stream >> obj.lastname;
		cout << "�������� ( ��� ������� ): ";
		stream >> obj.patronymic;
		cout << "������ ���-�� ��� �������: ";
		stream >> obj.datebirth;
		cout << "ID �������: ";
		stream >> obj.kafedra_id;
		return stream;
	}

	friend ostream& operator<<(ostream& os, Teacher& obj) { // �������� ������
		os << "ID" << obj.id << endl;
		os << "��� �������: " << obj.firstname << endl;
		os << "������� �������: " << obj.lastname << endl;
		os << "�������� �������: " << obj.patronymic << endl;
		os << "������ ���-�� ��� �������: " << obj.datebirth << endl;
		os << "ID �������: " << obj.kafedra_id << endl;
		return os;
	}
};