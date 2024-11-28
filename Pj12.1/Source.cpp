#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

// Функція для створення вхідного файлу з числами
void CreateFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Не вдалося відкрити файл для запису: " << filename << endl;
        return;
    }

    int n;
    cout << "Введіть кількість чисел для запису у файл: ";
    cin >> n;

    cout << "Введіть " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        double num;
        cin >> num;
        outFile << num << endl;
    }

    outFile.close();
    cout << "Файл " << filename << " успішно створено!" << endl;
}

// Функція для обчислення середніх значень додатних і від'ємних компонент
void ProcessFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Не вдалося відкрити вхідний файл: " << inputFile << endl;
        return;
    }

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "Не вдалося відкрити вихідний файл: " << outputFile << endl;
        return;
    }

    double num, sumPositive = 0, sumNegative = 0;
    int countPositive = 0, countNegative = 0;

    // Читання даних з файлу
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

    // Обчислення середніх значень
    double avgPositive = (countPositive > 0) ? (sumPositive / countPositive) : 0;
    double avgNegative = (countNegative > 0) ? (sumNegative / countNegative) : 0;

    // Запис результатів у вихідний файл
    outFile << "Середнє арифметичне додатних чисел: " << avgPositive << endl;
    outFile << "Середнє арифметичне від'ємних чисел: " << avgNegative << endl;

    outFile.close();
    cout << "Результати записані у файл: " << outputFile << endl;
}

// Функція для виведення вмісту файлу на екран
void PrintFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Не вдалося відкрити файл для читання: " << filename << endl;
        return;
    }

    string line;
    cout << "Вміст файлу " << filename << ":" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFile, outputFile;

    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFile;

    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFile;

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Створити файл з числами\n";
        cout << "2. Обробити файл та записати результати\n";
        cout << "3. Вивести вміст файлу на екран\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
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
            cout << "Завершення роботи програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
