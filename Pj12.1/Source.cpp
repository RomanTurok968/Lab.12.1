#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

// ������� ��� ��������� �������� ����� � �������
void CreateFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "�� ������� ������� ���� ��� ������: " << filename << endl;
        return;
    }

    int n;
    cout << "������ ������� ����� ��� ������ � ����: ";
    cin >> n;

    cout << "������ " << n << " �����:" << endl;
    for (int i = 0; i < n; ++i) {
        double num;
        cin >> num;
        outFile << num << endl;
    }

    outFile.close();
    cout << "���� " << filename << " ������ ��������!" << endl;
}

// ������� ��� ���������� ������� ������� �������� � ��'����� ���������
void ProcessFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "�� ������� ������� ������� ����: " << inputFile << endl;
        return;
    }

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "�� ������� ������� �������� ����: " << outputFile << endl;
        return;
    }

    double num, sumPositive = 0, sumNegative = 0;
    int countPositive = 0, countNegative = 0;

    // ������� ����� � �����
    while (inFile >> num) {
        if (num > 0) {
            sumPositive += num;
            countPositive++;
        }
        else if (num < 0) {
            sumNegative += num;
            countNegative++;
        }
    }

    inFile.close();

    // ���������� ������� �������
    double avgPositive = (countPositive > 0) ? (sumPositive / countPositive) : 0;
    double avgNegative = (countNegative > 0) ? (sumNegative / countNegative) : 0;

    // ����� ���������� � �������� ����
    outFile << "������ ����������� �������� �����: " << avgPositive << endl;
    outFile << "������ ����������� ��'����� �����: " << avgNegative << endl;

    outFile.close();
    cout << "���������� ������� � ����: " << outputFile << endl;
}

// ������� ��� ��������� ����� ����� �� �����
void PrintFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�� ������� ������� ���� ��� �������: " << filename << endl;
        return;
    }

    string line;
    cout << "���� ����� " << filename << ":" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFile, outputFile;

    cout << "������ ��'� �������� �����: ";
    cin >> inputFile;

    cout << "������ ��'� ��������� �����: ";
    cin >> outputFile;

    int choice;
    do {
        cout << "\n����:\n";
        cout << "1. �������� ���� � �������\n";
        cout << "2. �������� ���� �� �������� ����������\n";
        cout << "3. ������� ���� ����� �� �����\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateFile(inputFile);
            break;
        case 2:
            ProcessFile(inputFile, outputFile);
            break;
        case 3:
            PrintFile(outputFile);
            break;
        case 0:
            cout << "���������� ������ ��������." << endl;
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
