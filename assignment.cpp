#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct flights {
    char pilot[100];
    char  destination[50];
    char passenger[100];
    double price = 0;
    bool firstClass;
    int  date = 0;
    int number = 0;
};

void enterFlight(flights flight[], int n, int& m);
void printFlight(flights flight[], int size);
void printPilot(flights flight[], int size);
void leastExpensive(flights flight[], int size);
void file_out(flights flight[], int size, int& m);
void file_in(flights flight[]);
void destinationAlph(flights flight[], int size);
void classPriceAsc(const flights flight[], int size);
void searchByDateDestin(flights flight[], int size);
void currentPrice(flights flight[], int size);
void cancelFlight(flights flight[], int size);
void switchClass(flights flight[], int size);

int main()
{
    setlocale(LC_ALL, "BG");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int size = 50;
    flights flight[size];
    int n = 0, m = 0;
    unsigned short userChoice2 = 0, userChoice = 0;
    file_in(flight);
    do {
        cout << "\n�������� ����� �� ������\n";
        cout << "1.�������� �� ���� �����\n";
        cout << "2.�������� �� n ������\n";
        cout << "3.��������� �� ��������\n";
        cout << "4.������ � ���-����� ����\n";
        cout << "5.��������� �� ������ �� ����� �����\n";
        cout << "6.��������� ��� ����\n";
        cout << "7.���������� �� �������� � �������� ��� �� ������� ��� �� ������������\n";
        cout << "8.�������\n";
        cout << "9.�����\n";
        cout << "�����:";
        cin >> userChoice;
        switch (userChoice) {
        case 1:
            enterFlight(flight, 1, m);
            break;
        case 2:
            enterFlight(flight, n, m);
            break;
        case 3:
            printFlight(flight, size);
            break;
        case 4:
            leastExpensive(flight, size);
            break;
        case 5:
            printPilot(flight, size);
            break;
        case 6:
            file_out(flight, size, m);
            break;
        case 7:
            destinationAlph(flight, size);
            break;
        case 8:
            do {
                cout << "\n�������� ����� �� ������ ";
                cout << "\n1.��������� ��� �������� ��� �� ������ �� ������ � ������� �� ������";
                cout << "\n2.������� �� �������� ���� � ���������� ����������";
                cout << "\n3.���� �� �����: ";
                cout << "\n4.������ �� ����� �� ����� �����";
                cout << "\n5.����� �� �����";

                cout << "\n6.����� ";
                cout << "\n�����:";
                cin >> userChoice2;
                switch (userChoice2) {
                case 1:
                    classPriceAsc(flight, size);
                    break;
                case 2:
                    searchByDateDestin(flight, size);
                    break;
                case 3:
                    currentPrice(flight, size);
                    break;
                case 4:
                    switchClass(flight, size);
                    break;
                case 5:
                    cancelFlight(flight, size);
                    break;
                case 6:
                    file_out(flight, size, m);
                    break;
                default:
                    cout << "�������� ������� ����� �� ��������:" << endl;
                    break;
                }
            } while (userChoice2 != 6);
            break;
        case 9:
            file_out(flight, size, m);
            break;
        default:
            cout << "�������� ������� ����� �� �������� : " << endl;
            break;
        }
    } while (userChoice != 9);
    return 0;
}

void enterFlight(flights flight[], int n, int& m) {
    if (n != 1) {
        cout << "\n�������� ���� ������ : ";
        cin >> n;
    }
    if (n + m < 50) {
        for (int i = m; i < m + n; i++) {
            cout << "\n�������� �����:\n\n�����: ";
            cin >> flight[i].number;
            cout << "����: ";
            cin >> flight[i].date;
            cout << "����: ";
            cin >> flight[i].price;
            cout << "�����: ";
            cin.ignore();
            cin.getline(flight[i].pilot, 100);
            cout << "�����(1)/�����(0) �����: ";
            cin >> flight[i].firstClass;
            cin.ignore();
            cout << "��� �� ������: ";
            cin.getline(flight[i].passenger, 100);
            cout << "����������: ";
            cin.getline(flight[i].destination, 50);

        }
        m += n;
        n = 0;
    }
    else
        cout << "��������� ���� ��������" << endl;

}
void printFlight(flights flight[], int size) {
    cout << setfill(' ') << setw(10) << left << "�����" << setw(15) << "����" << setw(12) << left << "����" << setw(25) << left << "�����";
    cout << setfill(' ') << setw(15) << left << "����������" << setw(18) << left << "��� �� ������" << setw(15) << left << "�����/����� ����� " << endl;

    for (int i = 0; i < size; i++) {
        if (flight[i].number == 0)
            continue;
        cout << setfill(' ') << setw(10) << left << flight[i].number;
        cout << setw(15) << left << flight[i].date;
        cout << setw(12) << left << flight[i].price;
        cout << setfill(' ') << setw(25) << left
            << flight[i].pilot << setw(15) << left << flight[i].destination << setw(25) << left << flight[i].passenger << setw(15) << left << flight[i].firstClass << endl;
    }
}
void printPilot(flights flight[], int size) {
    char pilot[100];

    cout << "�������� ��� �� ����� : ";
    cin.ignore();
    cin.getline(pilot, 100);
    cout << setfill(' ') << setw(10) << left << "�����" << setw(15) << "����" << setw(12) << left << "����" << setw(25) << left << "�����";
    cout << setfill(' ') << setw(15) << left << "����������" << setw(18) << left << "��� �� ������" << setw(15) << left << "�����/����� ����� " << endl;

    for (int i = 0; i < size; i++) {
        if (flight[i].number == 0)
            break;
        else if (strcmp(flight[i].pilot, pilot) == 0) {
            cout << setfill(' ') << setw(10) << left << flight[i].number;
            cout << setw(15) << left << flight[i].date;
            cout << setw(12) << left << flight[i].price;
            cout << setfill(' ') << setw(25) << left << flight[i].pilot << setw(15) << left << flight[i].destination << setw(25) << left << flight[i].passenger << setw(15) << left << flight[i].firstClass << endl;

        }

    }
}

void leastExpensive(flights flight[], int size) {
    double min = flight[0].price;
    for (int i = 0; i < size; i++) {
        if (flight[i].number == 0)
            continue;
        else if (flight[i].price < min)
            min = flight[i].price;
    }
    cout << setfill(' ') << setw(10) << left << "�����" << setw(15) << "����" << setw(12) << left << "����" << setw(25) << left << "�����";
    cout << setfill(' ') << setw(15) << left << "����������" << setw(18) << left << "��� �� ������" << setw(15) << left << "�����/����� ����� " << endl;

    for (int i = 0; i < size; i++) {
        if (flight[i].number == 0)
            continue;
        else  if (flight[i].price == min) {
            cout << setfill(' ') << setw(10) << left << flight[i].number << setw(15) << left << flight[i].date << setw(12) << left << flight[i].price;
            cout << setfill(' ') << setw(25) << left << flight[i].pilot << setw(15) << left << flight[i].destination << setw(25) << left << flight[i].passenger << setw(15) << left << flight[i].firstClass << endl;
        }
    }
}

void destinationAlph(flights flight[], int size) {
    bool flag;

    for (int i = 0; i < size - 1; i++) {
        flag = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(flight[j].destination, flight[j + 1].destination) == -1) {
                flights temp = flight[j];
                flight[j] = flight[j + 1];
                flight[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
    printFlight(flight, size);
}
void classPriceAsc(const flights flight[], int size) {
    flights tempArr[50];
    bool flag;

    for (int i = 0; i < size; i++) {
        tempArr[i] = flight[i];
    }

    cout << "\n������ ���  �������� ��� �� ������:\n";

    for (int i = 0; i < size - 1; i++) {
        flag = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (tempArr[j].price > tempArr[j + 1].price) {
                flights temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false) break;
    }

    printFlight(tempArr, size);

    cout << "\n ������ ��� �������� ��� �� ����� �� ������ \n";

    for (int i = 0; i < size - 1; i++) {
        flag = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (tempArr[j].firstClass > tempArr[j + 1].firstClass) {
                flights temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
    printFlight(tempArr, size);
}


void searchByDateDestin(flights flight[], int size) {
    char destination[50];
    int  date;

    cout << "\n�������� ����:";
    cin >> date;
    cin.ignore();
    cout << "�������� ����������:";
    cin.getline(destination, 100);
    cout << setfill(' ') << setw(10) << left << "�����" << setw(15) << "����" << setw(12) << left << "����" << setw(25) << left << "�����";
    cout << setfill(' ') << setw(15) << left << "����������" << setw(18) << left << "��� �� ������" << setw(15) << left << "�����/����� ����� " << endl;


    for (int i = 0; i < size; i++) {
        if (flight[i].number == 0)
            continue;
        else if ((flight[i].date == date) && (strcmp(flight[i].destination, destination) == 0))
        {
            cout << setfill(' ') << setw(10) << left << flight[i].number << setw(15) << left << flight[i].date << setw(12) << left << flight[i].price;
            cout << setfill(' ') << setw(25) << left << flight[i].pilot << setw(15) << left << flight[i].destination << setw(25) << left << flight[i].passenger << setw(15) << left << flight[i].firstClass << endl;
        }

    }
}
void currentPrice(flights flight[], int size) {
    int number, cdate = 0, date = 0;
    char name[100];
    double price = 0;
    cout << "\n�������� ����� :";
    cin >> number;
    cout << "\n�������� ��� �� ������:";
    cin.ignore();
    cin.getline(name, 100);
    cout << "\n�������� ������ ����:";
    cin >> cdate;

    for (int i = 0; i < size; i++) {
        if (flight[i].number == number && (strcmp(flight[i].passenger, name) == 0)) {
            date = flight[i].date;
        }
    }

    int day1 = cdate / 1000000;
    int month1 = (cdate / 10000) % 100;
    int years1 = cdate % 10000;

    int day2 = date / 1000000;
    int month2 = (date / 10000) % 100;
    int years2 = date % 10000;

    int totaldays1 = 0;
    for (int i = 0; i < month1 - 1; i++) {
        totaldays1 += 30;
    }
    totaldays1 += day1; //current date in days

    int totaldays2 = 0;
    for (int i = 0; i < month2 - 1; i++) {
        totaldays2 += 30;
    }
    totaldays2 += day2;

    int totalyears = years2 - years1;//difference in years

    int days = totaldays2 - totaldays1 + 356 * totalyears; //difference in days
    printFlight(flight, size);

    for (int i = 0; i < size; i++) {
        if (date == flight[i].date && number == flight[i].number) {
            if (days == 0) {
                price = flight[i].price + (20.0 / 100 * flight[i].price);
                flight[i].price = price;
            }
            else if (days < 20 && days > 5) {
                price = 75.0 / 100 * flight[i].price;
                flight[i].price = price;
            }
            else if (days < 5) {
                price = flight[i].price;
                flight[i].price = price;
            }
            else {
                price = 50.0 / 100 * flight[i].price;
                flight[i].price = price;
            }

        }
    } cout << "\n������ �� ������ � " << price << "��.";

}
void file_out(flights flight[], int size, int& m) {
    fstream myFile;
    int count = 0;
    myFile.open("flights.bin", ios::binary | ios::out | ios::app);
    if (myFile.fail())
        cout << "������" << endl;

    for (int i = 0; i < m; i++) {
        if (flight[i].number == 0)
            continue;
        else count++;
    }
    myFile.write((char*)flight, count * (sizeof(flights)));
    myFile.close();
}

void file_in(flights flight[]) {
    fstream myFile;
    myFile.open("flights.bin", ios::binary | ios::in);
    if (myFile.fail())
        cout << "������" << endl;
    myFile.seekg(0L, ios::end);
    long pos = (long)myFile.tellg();
    myFile.close();
    myFile.open("flights.bin", ios::binary | ios::in);
    int n = pos / (sizeof(flights));
    myFile.read((char*)flight, n * sizeof(flights));
    myFile.close();
}

void cancelFlight(flights flight[], int size) {
    double price = 0;
    int number, cdate = 0, date = 0;
    char name[100];
    cout << "\n�������� ����� :";
    cin >> number;
    cout << "\n�������� ��� �� ������:";
    cin.ignore();
    cin.getline(name, 100);
    cout << "\n�������� ������ ����:";
    cin >> cdate;

    for (int i = 0; i < size; i++) {
        if (flight[i].number == number && (strcmp(flight[i].passenger, name) == 0)) {
            date = flight[i].date;
        }
    }

    int day1 = cdate / 1000000;
    int month1 = (cdate / 10000) % 100;
    int years1 = cdate % 10000;

    int day2 = date / 1000000;
    int month2 = (date / 10000) % 100;
    int years2 = date % 10000;

    int totaldays1 = 0;
    for (int i = 0; i < month1 - 1; i++) {
        totaldays1 += 30;
    }
    totaldays1 += day1;

    int totaldays2 = 0;
    for (int i = 0; i < month2 - 1; i++) {
        totaldays2 += 30;
    }
    totaldays2 += day2;

    int totalyears = years2 - years1;

    int days = totaldays2 - totaldays1 + 356 * totalyears;
    cout << days << endl;

    for (int i = 0; i < size; i++) {
        if ((strcmp(name, flight[i].passenger) == 0) && number == flight[i].number) {
            if (days < 5)
                price = 50.0 / 100 * flight[i].price;
            else if (days < 20 && days > 5)
                price = 75.0 / 100 * flight[i].price;
            else
                price = flight[i].price;
        }

    }
    cout << "\n������ �� ������� � " << price << "��.";
}

void switchClass(flights flight[], int size) {
    int number;
    char name[100];
    cout << "\n�������� ����� :";
    cin >> number;
    cout << "\n�������� ��� �� ������:";
    cin.ignore();
    cin.getline(name, 100);
    for (int i = 0; i < size; i++)
        if (flight[i].number == number && (strcmp(flight[i].passenger, name) == 0))
            flight[i].firstClass = true;
    printFlight(flight, size);
}

