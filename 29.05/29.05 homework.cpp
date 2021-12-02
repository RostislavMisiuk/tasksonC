#include <iostream>
#include <string>
using namespace std;

class Drob {
private:
	int numerator; //числитель
	int denominator; //знаменатель
	int NOD(int x, int y)
	{
		if (y == 0) return x;
		return NOD(y, x % y);
	}
public:
	void input(int c, int z)
	{
		numerator = c;
		denominator = z;
	}
	void mult(int x)
	{
		numerator *= x;
		cout << "fraction:  " << numerator << '/' << denominator << endl;
	}
	void div(int x)
	{
		denominator *= x;
		cout << "fraction:  " << numerator << '/' << denominator << endl;

	}

	void sum(int x)
	{
		numerator += (x * denominator);
		cout << "fraction:  " << numerator << '/' << denominator << endl;
	}
	void sub(int x)
	{
		numerator -= (x * denominator);
		cout << "fraction:  " << numerator << '/' << denominator << endl;

	}
	void show()
	{
		cout << "Your fraction:  " << numerator << '/' << denominator << endl;
	}
	int peredacha()
	{
		return NOD(numerator, denominator);
	}
	void reduct(int x)
	{
		numerator /= x;
		denominator /= x;
	}

};



int main() {
	int a, b, m;
	char c = 'y';
	cout << "Enter numerator:" << endl;
	cin >> a;
	cout << "Enter denuminator:" << endl;
	cin >> b;
	Drob obj;
	obj.input(a, b);
	do {
		obj.reduct(obj.peredacha());
		obj.show();
		cout << "1:Add number to the fraction" << endl;
		cout << "2:Deduct fraction number" << endl;
		cout << "3:Multiply fraction number" << endl;
		cout << "4:Share fraction number" << endl;
		cout << "Enter your action" << '\n';
		cin >> m;
		switch (m)
		{
		case 1:
			cout << "Enter component" << endl;
			cin >> a;
			obj.sum(a);
			break;
		case 2:
			cout << "Enter subtracked" << endl;
			cin >> a;
			obj.sub(a);
			break;
		case 3:
			cout << "Enter multiply" << endl;
			cin >> a;
			obj.mult(a);
			break;
		case 4:
			cout << "Enter demultiplier" << endl;
			cin >> a;
			obj.div(a);
			break;
		default:
			cout << "Enter right" << endl;
		}
		cout << "Continue?" << endl;
		cin >> c;
	} while (c != 'n');

	return 0;
}
