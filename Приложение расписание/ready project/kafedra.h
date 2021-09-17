#pragma once

class Kafedra {
	/* ����� ������� */
private:
	string name;
	int id;
public:

	Kafedra() {};
	Kafedra(int id, string name) {
		this->id = id;
		this->name = name;
	}
	void setId(int& id) { this->id = id; }
	int getId() { return id; }
	string getName() { return name; }
	void setName(string& name_kafedra) { this->name = name_kafedra; }

	friend istream& operator >> (istream& stream, Kafedra& obj) {
		cout << "�������� �������: ";
		stream >> obj.name;
		cout << "ID �������: ";
		stream >> obj.id;
		return stream;
	}
	friend ostream& operator<<(ostream& os, Kafedra& obj) {
		os << "�������� ������� : " << obj.name << endl;
		os << "ID ������� : " << obj.id << endl;
		return os;
	}
};