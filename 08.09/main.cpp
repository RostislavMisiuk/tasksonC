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

    cout << "\t****��������� ��� �������� ������ ��������� ���-�� ����������****" << endl;
    cout << "������� ��� ������ ��������� (TBytes, GBytes, MBytes, kBytes, Bytes): ";
    cin >> type;

    if (!strcmp(type, "TBytes"))
    {
        cout << "������� ���-�� ��������: ";
        cin >> TBytes;
        GBytes = TBytes * a;
        MBytes = GBytes * a;
        kBytes = MBytes * a;
        Bytes = kBytes * a;
        cout << "���-�� ��������: " << GBytes << endl;
        cout << "���-�� ��������: " << MBytes << endl;
        cout << "���-�� ��������: " << kBytes << endl;
        cout << "���-�� ����: " << Bytes;
    }
    else
        if (!strcmp(type, "GBytes"))
        {
            cout << "������� ���-�� ��������: ";
            cin >> GBytes;
            MBytes = GBytes * a;
            kBytes = MBytes * a;
            Bytes = kBytes * a;
            cout << "���-�� ��������: " << MBytes << endl;
            cout << "���-�� ��������: " << kBytes << endl;
            cout << "���-�� ����: " << Bytes;
        }
        else
            if (!strcmp(type, "MBytes"))
            {
                cout << "������� ���-�� ��������: ";
                cin >> MBytes;
                kBytes = MBytes * a;
                Bytes = kBytes * a;
                cout << "���-�� ��������: " << kBytes << endl;
                cout << "���-�� ����: " << Bytes;
            }
            else
                if (!strcmp(type, "kBytes"))
                {
                    cout << "������� ���-�� ��������: ";
                    cin >> kBytes;
                    Bytes = kBytes * a;
                    cout << "���-�� ����: " << Bytes;
                }
                else
                {
                    cout << "�� ���������� ����, ����� ���������!";
                }


    _getch();
    return 0;
}