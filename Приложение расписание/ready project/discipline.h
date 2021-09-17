#pragma once
class Discipline {
private:
	unsigned int id;
	unsigned int kafedra_id;
	string name;
	string description;
public:
	Discipline() {};
	Discipline(int id, int kafedra_id, string name, string description) {
		this->id = id;
		this->kafedra_id = kafedra_id;
		this->name = name;
		this->description = description;
	}
	string getDescription() {
		return description;
	}

	void setDescription(string& description) {
		this->description = description;
	}

	string getName() {
		return name;
	}

	void setName(string& name_discipline) {
		this->name = name_discipline;
	}

	int getKafedraId() {
		return kafedra_id;
	}

	int getId() {
		return id;
	}
	void setId(unsigned int& id)
	{
		this->id = id;
	}
	void setKafedraID(unsigned int& kafedra_id)
	{
		this->kafedra_id = kafedra_id;
	}

	friend istream& operator >> (istream& stream, Discipline& obj) {
		cout << "ID: ";
		stream >> obj.id;
		cout << "Название дисциплины: ";
		stream >> obj.name;
		cout << "Описание: ";
		stream >> obj.description;
		cout << "ID кафедры: ";
		stream >> obj.kafedra_id;
		return stream;
	}
	friend ostream& operator<<(ostream& os, Discipline& obj) {
		os << "Название дисциплины: " << obj.name << endl;
		os << "Описание: " << obj.description << endl;
		os << "ID кафедры: " << obj.kafedra_id << endl;
		os << "ID дисциплины" << obj.id << endl;
		return os;
	}
};