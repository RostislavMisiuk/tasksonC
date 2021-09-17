#pragma once
class Classes {
private:
	int date;
	int pair;
	int id_discipline;
	int id_teacher;
	int id_group;
public:
	Classes() {};
	Classes(int date, int pair, int id_discipline, int id_teacher, int id_group) {
		this->date = date;
		this->pair = pair;
		this->id_discipline = id_discipline;
		this->id_teacher = id_teacher;
		this->id_group = id_group;
	}

	void setdate(int& date) {
		this->date = date;
	}

	void setpair(int& pair) {
		this->pair = pair;
	}

	int getdate() {
		return date;
	}

	int getpair() {
		return pair;
	}

	int getDisciplineId() {
		return id_discipline;
	}

	int getTeacherId() {
		return id_teacher;
	}

	int getGroupId() {
		return id_group;
	}

	friend istream& operator >> (istream& stream, Classes& obj) {
		cout << "���� ������ ( Mon-1, Sun-7 ): ";
		stream >> obj.date;
		cout << "����� ����: ";
		stream >> obj.pair;
		cout << "ID ����������: ";
		stream >> obj.id_discipline;
		cout << "ID �������������: ";
		stream >> obj.id_teacher;
		cout << "ID ������: ";
		stream >> obj.id_group;
		return stream;
	}
	friend ostream& operator<<(ostream& os, Classes& obj) {
		os << "���� ������: " << obj.date << endl;
		os << "�������� ����: " << obj.pair << endl;
		os << "ID ����������: " << obj.id_discipline << endl;
		os << "ID �������: " << obj.id_teacher << endl;
		os << "ID ������: " << obj.id_group << endl;
		return os;
	}
};