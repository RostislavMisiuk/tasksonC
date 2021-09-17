#include <iostream>
#include <windows.h>
using namespace std;

class Math
{
public:
    float root;
    float root1;
    float root2;
    Math(float t, float t1, float t2)
    {
        root = t;
        root1 = t1;
        root2 = t2;
    }
    virtual void Print() = 0;
};

class rectangle : public Math//прямоугольник
{
public:
    rectangle(float root, float root1) : Math(root, root1, root2)
    {};
    virtual void Print()
    {
        float w;
        w = root * root1;
        cout << "\n\n";
        cout << "Площадь прямоугольника со сторонами " << root << " и " << root1 << " = " << w << "\n";
        cout << "\n\n";
    }
};

class circle : public Math//круг
{
public:
    circle(float root2) : Math(root, root1, root2)
    {};
    virtual void Print()
    {
        float e;
        e = 3.14 * root2 * root2;
        cout << "\n\n";
        cout << "Площадь круга с радиусом " << root2 << " = " << e << "\n";
        cout << "\n\n";
    }
};

class right_triangle : public Math//прямоугольный трегольник
{
public:
    right_triangle(float root, float root1) : Math(root, root1, root2)
    {};
    virtual void Print()
    {
        cout << "\n\n";
        float o;
        o = root * root1 / 2;
        cout << "Площадь прямоугольного треугольника с катетами " << root << " и " << root1 << " = " << o << "\n";
        cout << "\n\n";
    }
};

class Trapeze : public Math//трапеция
{
public:
    Trapeze(float root, float root1, float root2) : Math(root, root1, root2)
    {};
    virtual void Print()
    {
        cout << "\n\n";
        float g;
        g = (root + root1) / 2 * root2;
        cout << "Площадь трапеции со основаниями " << root << " и " << root1 << " = " << g << "\n";
        cout << "\n\n";
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Создать абстрактный базовый класс с виртуальной функцией - площадь. Создать \n";
    cout << "производные классы: прямоугольник, круг, прямоугольный треугольник, \n";
    cout << "трапеция со своими функциями площади. Для проверки определить массив\n";
    cout << "ссылок на абстрактный класс, которым присваиваются адреса различных \n";
    cout << "объектов. \n";
    system("pause");
    system("cls");
    float a, a1, b, c, c1, d, d1, d2;

    cout << "Заполняем данные прямоугольника\n";
    cout << "Введите 1 сторону\n";
    cin >> a;
    cout << "Введите 2 сторону\n";
    cin >> a1;

    cout << "Заполняем данные круга\n";
    cout << "Введите радиус круга\n";
    cin >> b;

    cout << "Заполняем данные прямоугольного треугольника\n";
    cout << "Введите 1 катет\n";
    cin >> c;
    cout << "Введите 2 катет\n";
    cin >> с1;

    cout << "Заполняем данные трапеции\n";
    cout << "Введите 1 основание\n";
    cin >> d;
    cout << "Введите 2 основание\n";
    cin >> d1;
    cout << "Введите высоту трапеции\n";
    cin >> d2;
    Math* equation[4] = { new rectangle(a,a1), new circle(b),new right_triangle(c,с1),new Trapeze(d,d1,d2) };
    for (int k = 0; k < 4; k++)
        equation[k]->Print();
    system("pause");
}