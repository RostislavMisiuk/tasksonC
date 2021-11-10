#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int TBytes, GBytes;
    long long MBytes, kBytes, Bytes;
    const int a = 1024;
    char type[7];

    cout << "\t****Программа для перевода единиц измерения кол-ва информации****" << endl;
    cout << "Введите тип единиц измерения (TBytes, GBytes, MBytes, kBytes, Bytes): ";
    cin >> type;

    if (!strcmp(type, "TBytes"))
    {
        cout << "Введите кол-во Терабайт: ";
        cin >> TBytes;
        GBytes = TBytes * a;
        MBytes = GBytes * a;
        kBytes = MBytes * a;
        Bytes = kBytes * a;
        cout << "Кол-во Гигабайт: " << GBytes << endl;
        cout << "Кол-во Мегабайт: " << MBytes << endl;
        cout << "Кол-во Килобайт: " << kBytes << endl;
        cout << "Кол-во Байт: " << Bytes;
    }
    else
        if (!strcmp(type, "GBytes"))
        {
            cout << "Введите кол-во Гигабайт: ";
            cin >> GBytes;
            MBytes = GBytes * a;
            kBytes = MBytes * a;
            Bytes = kBytes * a;
            cout << "Кол-во Мегабайт: " << MBytes << endl;
            cout << "Кол-во Килобайт: " << kBytes << endl;
            cout << "Кол-во Байт: " << Bytes;
        }
        else
            if (!strcmp(type, "MBytes"))
            {
                cout << "Введите кол-во Мегабайт: ";
                cin >> MBytes;
                kBytes = MBytes * a;
                Bytes = kBytes * a;
                cout << "Кол-во Килобайт: " << kBytes << endl;
                cout << "Кол-во Байт: " << Bytes;
            }
            else
                if (!strcmp(type, "kBytes"))
                {
                    cout << "Введите кол-во Килобайт: ";
                    cin >> kBytes;
                    Bytes = kBytes * a;
                    cout << "Кол-во Байт: " << Bytes;
                }
                else
                {
                    cout << "Не правильный ввод, конец программы!";
                }


    _getch();
    return 0;
}