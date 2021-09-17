#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>
#include <clocale>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
#include "student.h"
#include "group.h"
#include "teacher.h"
#include "kafedra.h"
#include "discipline.h"
#include "classes.h"

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
Group* findGroupById(vector<Group> groups, int id) {
	Group* res = NULL;
	for (Group g : groups) {
		if (g.getId() == id) {
			res = &g;
			break;
		}
	}
	return res;
}
int main() {

	setlocale(LC_ALL, "rus");
	vector<Classes> classes;
	vector<Student> students;
	vector<Discipline> disciplines;
	vector<Kafedra> kafedras;
	vector<Teacher> teachers;
	vector<Group> groups;

	/* �������� ������� */
	Discipline discipline;
	Kafedra kafedra;
	Teacher teacher;
	Student student;
	Group group;
	Classes para;
	int select = -1;
	int d;
	int u;
	bool isValid;
	int count = 0;
	string i;
	string a;
	ofstream fout("data.txt");
	ifstream fin("dataload.txt");
	SetColor(LightGreen, Black);
	cout << "����� ���������� � ��������� '����������'" << endl;
	SetColor(White, Black);
	while (select != 0) {
		cout << "���������� ������� - 1; ���������� ���������� - 2; ���������� ������� - 3; \n���������� �������� - 4; ���������� ������ - 5; ���������� ���� - 6\n----------------------------------------------\n";
		cout << "����� ������� - 7; ����� ���������� - 8; ����� �������� - 9; \n����� �������� - 10; ����� ������ - 11; ����� ���� - 12; \n----------------------------------------------\n";
		cout << "����� ������� �� ����� -13; ����� �������� �� ����� - 14; ��������� ���� - 15; ��������� ���������� �� ����� - 16;\n����� ���������� �� ������� - 17; ����� ���������� �� �������� - 18;\n----------------------------------------------\n����� - 0\n\n";
		cout << "�������� �������: ";
		SetColor(Green, Black);
		cin >> select;
		SetColor(White, Black);
		cout << endl;
		switch (select) {
			/* ���������� */
		case 1:
			/* ������� */
			cin >> kafedra;
			isValid = true;
			for (Kafedra currentKafedra : kafedras) {
				if (currentKafedra.getId() == kafedra.getId()) {
					isValid = false;
					break;
				}
			}
			SetColor(Cyan, Black);
			if (isValid) {
				kafedras.push_back(kafedra);
				cout << "������� " << kafedra.getName() << " ������� ���������!\n";
			}
			else {
				cout << "������� " << kafedra.getName() << " �� ����� ���� ������� � ID: " << kafedra.getId() << endl << "�������� ������ ID.\n";
			}
			SetColor(White, Black);
			break;
		case 2:
			/* ���������� */
			cin >> discipline;
			isValid = false;
			for (Kafedra currentKafedra : kafedras) {
				if (currentKafedra.getId() == discipline.getKafedraId()) {
					isValid = true;
					break;
				}
			}
			for (Discipline d : disciplines) {
				if (d.getId() == discipline.getId()) {
					isValid = false;
					break;
				}
			}
			SetColor(Cyan, Black);
			// �������������� ��������� ������
			if (isValid) {
				disciplines.push_back(discipline);
				/*Kafedra* k = findKafedraById(kafedras, discipline.getKafedraId());*/
				cout << "���������� " << discipline.getName() << " ������� ��������� �� ������� "/* << k->getName() <<*/ "!\n";
			}
			else {
				cout << "���������� " << discipline.getName() << " �� ����� ���� ������� � ID �������������� �������: " << discipline.getKafedraId() << endl << "�������� ������ ID.\n";
			}
			SetColor(White, Black);
			break;
		case 3:
			/* ������������� */
			cin >> teacher;
			isValid = false;
			/* �������� ������������� ID ������� */
			for (Kafedra currentKafedra : kafedras) {
				if (currentKafedra.getId() == teacher.getKafedraId()) {
					isValid = true;
					break;
				}
			}
			if (!isValid) {
				cout << "������������� " << teacher.getlastname() << " �� ����� ���� ������� � ID �������������� �������: " << teacher.getKafedraId() << endl << "�������� ������ ID.\n";
				break;
			}
			/* �������� ������������� ID */
			for (Teacher t : teachers) {
				if (t.getId() == teacher.getId()) {
					isValid = false;
					break;
				}
			}
			SetColor(Cyan, Black);
			if (isValid) {
				teachers.push_back(teacher);
				/*Kafedra* k = findKafedraById(kafedras, discipline.getKafedraId());*/
				cout << "������������� " << teacher.getlastname() << " ������� �������� �� ������� " /*<< k->getName()*/ << "!\n";
			}
			else {
				cout << "������������� " << teacher.getlastname() << " �� ����� ���� ������� � ID: " << teacher.getId() << endl << "�������� ������ ID.\n";
			}
			SetColor(White, Black);
			break;
		case 4:
			/* ������� */
			cin >> student;
			isValid = false;
			for (Group currentGroup : groups) {
				if (currentGroup.getId() == student.getGroupId()) {
					isValid = true;
					break;
				}
			}
			SetColor(Cyan, Black);
			if (isValid) {
				students.push_back(student);
				/*Group* g = findGroupById(groups, student.getGroupId());*/
				cout << "������� " << student.getlastname() << " ������� �������� � ������" /*<< g->getName() <<*/ "!\n";
			}
			else {
				cout << "������� " << student.getlastname() << " �� ����� ���� ������ � ID ������: " << student.getGroupId() << endl << "�������� ������ ID.\n";
			}
			SetColor(White, Black);
			break;
		case 5:
			/* ������ */
			cin >> group;
			isValid = true;
			for (Group currentGroup : groups) {
				if (currentGroup.getId() == group.getId()) {
					isValid = false;
					break;
				}
			}
			SetColor(Cyan, Black);
			if (isValid) {
				groups.push_back(group);
				cout << "������ " << group.getName() << " ������� ���������!\n";
			}
			else {
				cout << "������ " << group.getName() << " �� ����� ���� ������� � ID: " << group.getId() << endl << "�������� ������ ID.\n";
			}
			SetColor(White, Black);
			break;
		case 6:
			/* ������� */

			cin >> para;
			isValid = false;
			if (para.getdate() < 1 || para.getdate() > 7) {
				cout << "������� �� �������.\n���� ������ ����� ���� �� 1 �� 7.\n";
				break;
			}
			if (para.getpair() < 1) {
				cout << "������� �� �������.\n���� �� ����� ���� ������ ��� ����� ����.\n";
				break;
			}
			/* �������� �� ������������� */
			for (Discipline d : disciplines) {
				if (d.getId() == para.getDisciplineId()) {
					isValid = true;
					discipline = d;
					break;
				}
			}
			if (!isValid) {
				cout << "������� �� �������.\nID ���������� �� �������.\n";
				break;
			}
			isValid = false;
			for (Teacher t : teachers) {
				if (t.getId() == para.getTeacherId()) {
					isValid = true;
					teacher = t;
					break;
				}
			}
			if (!isValid) {
				cout << "������� �� �������.\nID ������������� �� �������.\n";
				break;
			}
			isValid = false;
			for (Group g : groups) {
				if (g.getId() == para.getGroupId()) {
					isValid = true;
					group = g;
					break;
				}
			}
			if (!isValid) {
				cout << "������� �� �������.\nID ������ �� �������.\n";
				break;
			}
			/* �������� �� ��������� */
			for (Classes currentPara : classes) {
				int cdate = currentPara.getdate();
				int cpair = currentPara.getpair();
				if (cdate == para.getdate() && cpair == para.getpair() && para.getGroupId() == currentPara.getGroupId()) {
					cout << "������� �� �������.\n� ��� ����� ������ " << group.getName() << " ��������� �� ������ �������.\n";
					isValid = false;
					break;
				}
				if (cdate == para.getdate() && cpair == para.getpair() && para.getTeacherId() == currentPara.getTeacherId()) {
					cout << "������� �� �������.\n� ��� ����� ������������� " << teacher.getlastname() << " �� ������ �������.\n";
					isValid = false;
					break;
				}
			}
			if (isValid) {
				classes.push_back(para);
				cout << "������� ������� �������!\n";
			}
			break;

			/* ����� */
		case 7:
			for (int i = 0; i < kafedras.size(); i++)
				cout << kafedras[i] << ' ';
			break;
		case 8:
			for (int i = 0; i < disciplines.size(); i++)
				cout << disciplines[i] << ' ';
			break;
		case 9:
			for (int i = 0; i < teachers.size(); i++)
				cout << teachers[i] << ' ';
			break;
		case 10:
			for (int i = 0; i < students.size(); i++)
				cout << students[i] << ' ';
			break;
		case 11:
			for (int i = 0; i < groups.size(); i++)
				cout << groups[i] << ' ';
			break;
		case 12:
			for (int i = 0; i < kafedras.size(); i++) {
				cout << kafedras[i] << ' ';
			}
			for (int i = 0; i < disciplines.size(); i++) {
				cout << disciplines[i] << ' ';
			}
			for (int i = 0; i < teachers.size(); i++) {
				cout << teachers[i] << ' ';
			}
			for (int i = 0; i < students.size(); i++) {
				cout << students[i] << ' ';
			}
			for (int i = 0; i < groups.size(); i++) {
				cout << groups[i] << ' ';
			}
			for (int i = 0; i < classes.size(); i++) {
				cout << classes[i] << ' ';
			}
			break;
		case 13:
			cout << "������� ��� �������: " << endl;
			cin >> i;
			isValid = false;
			for (Teacher t : teachers) {
				if (i == t.getfirstname())
				{
					cout << "���:\n " << t.getfirstname() << "�������:\n " << t.getlastname() << "��������:\n " << t.getpatronymic() << "������ ���:\n" << t.getdatebirth() << "ID �������:\n " << t.getKafedraId() << endl;
					isValid = true;
				}
				else
				{
					cout << "������� � ����� ������ ����! " << endl;
				}
				break;
			}
		case 14:
			cout << "������� ��� ��������: " << endl;
			cin >> a;
			isValid = false;
			for (Student s : students)
			{
				if (a == s.getfirstname())
				{
					cout << "���:\n" << s.getfirstname() << "�������:\n" << s.getlastname() << "��������:\n " << s.getpatronymic() << "������ ���:\n" << s.getdatebirth() << "ID ������:\n " << s.getGroupId() << endl;
				}
				else
				{
					cout << "������ �������� ����! " << endl;
				}
			}
			break;
		case 15:
			/* ������ ����� */

			/* ������� */
			count = kafedras.size();
			fout << count << endl;
			for (Kafedra k : kafedras) {
				fout << k.getId() << " " << k.getName() << endl;
			}
			/* ���������� */
			count = disciplines.size();
			fout << count << endl;
			for (Discipline d : disciplines) {
				fout << d.getId() << " " << d.getName() << " " << d.getDescription() << " " << d.getKafedraId() << endl;
			}
			/* ������������� */
			count = teachers.size();
			fout << count << endl;
			for (Teacher t : teachers) {
				fout << t.getId() << " " << t.getfirstname() << " " << t.getlastname() << " " << t.getpatronymic() << " " << t.getdatebirth() << " " << t.getKafedraId() << endl;
			}
			/* ������ */
			count = groups.size();
			fout << count << endl;
			for (Group g : groups) {
				fout << g.getId() << " " << g.getName() << endl;
			}
			/* �������� */
			count = students.size();
			fout << count << endl;
			for (Student s : students) {
				fout << s.getfirstname() << " " << s.getlastname() << " " << s.getpatronymic() << " " << s.getdatebirth() << " " << s.getGroupId() << endl;
			}
			/* ���� */
			count = classes.size();
			fout << count << endl;
			for (Classes c : classes) {
				fout << c.getdate() << " " << c.getpair() << " " << c.getDisciplineId() << " " << c.getGroupId() << " " << c.getTeacherId() << endl;
			}

			fout.close();
			break;
		case 16:
			/* ������ �� ����� */

			/* ������� */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id;
				string name;
				fin >> id >> name;
				kafedra = Kafedra(id, name);
				kafedras.push_back(kafedra);
			}
			/* ���������� */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, kafid;
				string name, desc;
				fin >> id >> name >> desc >> kafid;
				discipline = Discipline(id, kafid, name, desc);
				disciplines.push_back(discipline);
			}
			/* ������������� */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, kafid, date;
				string name, firstname, lastname, patron, desc;
				fin >> id >> firstname >> lastname >> patron >> date >> kafid;
				teacher = Teacher(id, firstname, lastname, patron, date, kafid);
				teachers.push_back(teacher);
			}
			/* ������ */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id;
				string name;
				fin >> id >> name;
				group = Group(id, name);
				groups.push_back(group);
			}
			/* �������� */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, groupid, date;
				string name, lastname, patron;
				fin >> name >> lastname >> patron >> date >> groupid;
				student = Student(name, lastname, patron, date, groupid);
				students.push_back(student);
			}
			/* ���� */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int date, pair, idd, idg, idt;
				fin >> date >> pair >> idd >> idg >> idt;
				para = Classes(date, pair, idd, idg, idt);
				classes.push_back(para);
			}
			break;
		case 17:
			cout << "������� ID �������: ";
			cin >> u;
			isValid = false;
			for (Teacher t : teachers)
			{
				if (u == t.getId())
				{
					cout << "������� ����� ID �������: " << endl;
				}
				else
				{
					cout << "������ ID �� ����������!" << endl;
				}
			}
			cout << "������� ����: ";
			cin >> d;
			isValid = false;
			for (Classes c : classes)
			{
				if (d == c.getdate())
				{
					cout << "����:" << c.getdate() << endl;
				}
				else
				{
					cout << "������ ��� ������ �� ����������!" << endl;
				}
			}
			isValid = true;
			for (Classes c : classes)
			{
				cout << "ID ������:" << c.getGroupId() << "ID ����������: " << c.getDisciplineId() << "����� ����:" << c.getpair() << endl;
			}
			break;
		case 18:
			cout << "������� ��� ��������: " << endl;
			cin >> a;
			isValid = false;
			for (Student s : students)
			{
				if (a == s.getfirstname())
				{
					cout << "���:" << s.getfirstname() << "�������:" << s.getlastname() << "��������: " << s.getpatronymic() << "������ ���:" << s.getdatebirth() << "ID ������:" << s.getGroupId() << endl;
				}
				else
				{
					cout << "������ �������� ����!\n " << endl;
				}
			}
			cout << "������� ���� ������:\n " << endl;
			cin >> d;
			isValid = false;
			for (Classes c : classes)
			{
				if (d == c.getdate())
				{
					cout << "����:\n" << c.getdate() << endl;
				}
				else
				{
					cout << "������ ��� ������ �� ����������!\n" << endl;
				}
			}
			isValid = true;
			for (Classes c : classes)
			{
				cout << "���� ������:" << c.getdate() << "ID �������:" << c.getpair() << endl;
			}
			break;
		}


	}
}
