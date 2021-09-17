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

	/* Буферные объекты */
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
	cout << "Добро пожаловать в программу 'Расписание'" << endl;
	SetColor(White, Black);
	while (select != 0) {
		cout << "Добавление кафедры - 1; Добавление дисциплины - 2; Добавление учителя - 3; \nДобавление студента - 4; Добавление группы - 5; Добавление пары - 6\n----------------------------------------------\n";
		cout << "Вывод кафедры - 7; Вывод дисциплины - 8; Вывод учителей - 9; \nВывод студента - 10; Вывод группы - 11; Вывод пары - 12; \n----------------------------------------------\n";
		cout << "Поиск учителя по имени -13; Поиск студента по имени - 14; Сохранить файл - 15; Загрузить информацию из файла - 16;\nПоиск расписания по учителю - 17; Поиск расписания по студенту - 18;\n----------------------------------------------\nВыход - 0\n\n";
		cout << "Выберете функцию: ";
		SetColor(Green, Black);
		cin >> select;
		SetColor(White, Black);
		cout << endl;
		switch (select) {
			/* Добавление */
		case 1:
			/* Кафедра */
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
				cout << "Кафедра " << kafedra.getName() << " успешно добавлена!\n";
			}
			else {
				cout << "Кафедра " << kafedra.getName() << " не может быть создана с ID: " << kafedra.getId() << endl << "Выберете другой ID.\n";
			}
			SetColor(White, Black);
			break;
		case 2:
			/* Дисциплина */
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
			// Дополнительная обработка ошибок
			if (isValid) {
				disciplines.push_back(discipline);
				/*Kafedra* k = findKafedraById(kafedras, discipline.getKafedraId());*/
				cout << "Дисциплина " << discipline.getName() << " успешно добавлена на кафедру "/* << k->getName() <<*/ "!\n";
			}
			else {
				cout << "Дисциплина " << discipline.getName() << " не может быть создана с ID несуществующей кафедры: " << discipline.getKafedraId() << endl << "Выберете другой ID.\n";
			}
			SetColor(White, Black);
			break;
		case 3:
			/* Преподаватель */
			cin >> teacher;
			isValid = false;
			/* Проверка существующего ID кафедры */
			for (Kafedra currentKafedra : kafedras) {
				if (currentKafedra.getId() == teacher.getKafedraId()) {
					isValid = true;
					break;
				}
			}
			if (!isValid) {
				cout << "Преподаватель " << teacher.getlastname() << " не может быть создана с ID несуществующей кафедры: " << teacher.getKafedraId() << endl << "Выберете другой ID.\n";
				break;
			}
			/* Проверка существующего ID */
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
				cout << "Преподаватель " << teacher.getlastname() << " успешно добавлен на кафедру " /*<< k->getName()*/ << "!\n";
			}
			else {
				cout << "Преподаватель " << teacher.getlastname() << " не может быть создана с ID: " << teacher.getId() << endl << "Выберете другой ID.\n";
			}
			SetColor(White, Black);
			break;
		case 4:
			/* Студент */
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
				cout << "Студент " << student.getlastname() << " успешно добавлен в группу" /*<< g->getName() <<*/ "!\n";
			}
			else {
				cout << "Студент " << student.getlastname() << " не может быть создан с ID группы: " << student.getGroupId() << endl << "Выберете другой ID.\n";
			}
			SetColor(White, Black);
			break;
		case 5:
			/* Группа */
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
				cout << "Группа " << group.getName() << " успешно добавлена!\n";
			}
			else {
				cout << "Группа " << group.getName() << " не может быть создана с ID: " << group.getId() << endl << "Выберете другой ID.\n";
			}
			SetColor(White, Black);
			break;
		case 6:
			/* Занятие */

			cin >> para;
			isValid = false;
			if (para.getdate() < 1 || para.getdate() > 7) {
				cout << "Занятие не создано.\nДень недели может быть от 1 до 7.\n";
				break;
			}
			if (para.getpair() < 1) {
				cout << "Занятие не создано.\nПара не может быть меньше или равно нулю.\n";
				break;
			}
			/* Проверка на существование */
			for (Discipline d : disciplines) {
				if (d.getId() == para.getDisciplineId()) {
					isValid = true;
					discipline = d;
					break;
				}
			}
			if (!isValid) {
				cout << "Занятие не создано.\nID дисциплины не найдено.\n";
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
				cout << "Занятие не создано.\nID преподавателя не найдено.\n";
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
				cout << "Занятие не создано.\nID группы не найдено.\n";
				break;
			}
			/* Проверка на занятость */
			for (Classes currentPara : classes) {
				int cdate = currentPara.getdate();
				int cpair = currentPara.getpair();
				if (cdate == para.getdate() && cpair == para.getpair() && para.getGroupId() == currentPara.getGroupId()) {
					cout << "Занятие не создано.\nВ это время группа " << group.getName() << " обучается на другом занятии.\n";
					isValid = false;
					break;
				}
				if (cdate == para.getdate() && cpair == para.getpair() && para.getTeacherId() == currentPara.getTeacherId()) {
					cout << "Занятие не создано.\nВ это время преподаватель " << teacher.getlastname() << " на другом занятии.\n";
					isValid = false;
					break;
				}
			}
			if (isValid) {
				classes.push_back(para);
				cout << "Занятие успешно создано!\n";
			}
			break;

			/* Вывод */
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
			cout << "Введите имя учителя: " << endl;
			cin >> i;
			isValid = false;
			for (Teacher t : teachers) {
				if (i == t.getfirstname())
				{
					cout << "Имя:\n " << t.getfirstname() << "Фамилия:\n " << t.getlastname() << "Отчество:\n " << t.getpatronymic() << "Полных лет:\n" << t.getdatebirth() << "ID кафедры:\n " << t.getKafedraId() << endl;
					isValid = true;
				}
				else
				{
					cout << "Учителя с таким именем нету! " << endl;
				}
				break;
			}
		case 14:
			cout << "Введите имя студента: " << endl;
			cin >> a;
			isValid = false;
			for (Student s : students)
			{
				if (a == s.getfirstname())
				{
					cout << "Имя:\n" << s.getfirstname() << "Фамилия:\n" << s.getlastname() << "Отчество:\n " << s.getpatronymic() << "Полных лет:\n" << s.getdatebirth() << "ID группы:\n " << s.getGroupId() << endl;
				}
				else
				{
					cout << "Такого студента нету! " << endl;
				}
			}
			break;
		case 15:
			/* Запись файла */

			/* Кафедры */
			count = kafedras.size();
			fout << count << endl;
			for (Kafedra k : kafedras) {
				fout << k.getId() << " " << k.getName() << endl;
			}
			/* Дисциплины */
			count = disciplines.size();
			fout << count << endl;
			for (Discipline d : disciplines) {
				fout << d.getId() << " " << d.getName() << " " << d.getDescription() << " " << d.getKafedraId() << endl;
			}
			/* Преподаватели */
			count = teachers.size();
			fout << count << endl;
			for (Teacher t : teachers) {
				fout << t.getId() << " " << t.getfirstname() << " " << t.getlastname() << " " << t.getpatronymic() << " " << t.getdatebirth() << " " << t.getKafedraId() << endl;
			}
			/* Группы */
			count = groups.size();
			fout << count << endl;
			for (Group g : groups) {
				fout << g.getId() << " " << g.getName() << endl;
			}
			/* Студенты */
			count = students.size();
			fout << count << endl;
			for (Student s : students) {
				fout << s.getfirstname() << " " << s.getlastname() << " " << s.getpatronymic() << " " << s.getdatebirth() << " " << s.getGroupId() << endl;
			}
			/* Пары */
			count = classes.size();
			fout << count << endl;
			for (Classes c : classes) {
				fout << c.getdate() << " " << c.getpair() << " " << c.getDisciplineId() << " " << c.getGroupId() << " " << c.getTeacherId() << endl;
			}

			fout.close();
			break;
		case 16:
			/* Запись из файла */

			/* Кафедры */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id;
				string name;
				fin >> id >> name;
				kafedra = Kafedra(id, name);
				kafedras.push_back(kafedra);
			}
			/* Дисциплины */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, kafid;
				string name, desc;
				fin >> id >> name >> desc >> kafid;
				discipline = Discipline(id, kafid, name, desc);
				disciplines.push_back(discipline);
			}
			/* Преподаватели */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, kafid, date;
				string name, firstname, lastname, patron, desc;
				fin >> id >> firstname >> lastname >> patron >> date >> kafid;
				teacher = Teacher(id, firstname, lastname, patron, date, kafid);
				teachers.push_back(teacher);
			}
			/* Группы */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id;
				string name;
				fin >> id >> name;
				group = Group(id, name);
				groups.push_back(group);
			}
			/* Студенты */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int id, groupid, date;
				string name, lastname, patron;
				fin >> name >> lastname >> patron >> date >> groupid;
				student = Student(name, lastname, patron, date, groupid);
				students.push_back(student);
			}
			/* Пары */
			fin >> count;
			for (int i = 0; i < count; ++i) {
				int date, pair, idd, idg, idt;
				fin >> date >> pair >> idd >> idg >> idt;
				para = Classes(date, pair, idd, idg, idt);
				classes.push_back(para);
			}
			break;
		case 17:
			cout << "Введите ID учителя: ";
			cin >> u;
			isValid = false;
			for (Teacher t : teachers)
			{
				if (u == t.getId())
				{
					cout << "Успешно ввели ID учителя: " << endl;
				}
				else
				{
					cout << "Такого ID не существует!" << endl;
				}
			}
			cout << "Введите день: ";
			cin >> d;
			isValid = false;
			for (Classes c : classes)
			{
				if (d == c.getdate())
				{
					cout << "День:" << c.getdate() << endl;
				}
				else
				{
					cout << "Такого дня недели не существует!" << endl;
				}
			}
			isValid = true;
			for (Classes c : classes)
			{
				cout << "ID группы:" << c.getGroupId() << "ID дисциплины: " << c.getDisciplineId() << "Номер пары:" << c.getpair() << endl;
			}
			break;
		case 18:
			cout << "Введите имя студента: " << endl;
			cin >> a;
			isValid = false;
			for (Student s : students)
			{
				if (a == s.getfirstname())
				{
					cout << "Имя:" << s.getfirstname() << "Фамилия:" << s.getlastname() << "Отчество: " << s.getpatronymic() << "Полных лет:" << s.getdatebirth() << "ID группы:" << s.getGroupId() << endl;
				}
				else
				{
					cout << "Такого студента нету!\n " << endl;
				}
			}
			cout << "Введите день недели:\n " << endl;
			cin >> d;
			isValid = false;
			for (Classes c : classes)
			{
				if (d == c.getdate())
				{
					cout << "День:\n" << c.getdate() << endl;
				}
				else
				{
					cout << "Такого дня недели не существует!\n" << endl;
				}
			}
			isValid = true;
			for (Classes c : classes)
			{
				cout << "День недели:" << c.getdate() << "ID Предмет:" << c.getpair() << endl;
			}
			break;
		}


	}
}
