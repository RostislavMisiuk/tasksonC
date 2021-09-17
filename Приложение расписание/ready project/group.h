#pragma once
class Group {
	/* ����� ������ */
private:
	int id;
	string name;

public:
	Group() {};
	Group(int id, string name) {
		this->id = id;
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string& namegroup) {
		this->name = namegroup;
	}
	void setId(int& id) {
		this->id = id;
	}
	int getId() {
		return id;
	}

	friend istream& operator >> (istream& stream, Group& obj) {
		cout << "�������� ������: ";
		stream >> obj.name;
		cout << "ID ������: ";
		stream >> obj.id;
		return stream;
	}
	friend ostream& operator<<(ostream& os, Group& obj) {
		os << "�������� ������ : " << obj.name << endl;
		os << "ID ������ : " << obj.id << endl;
		return os;
	}
};