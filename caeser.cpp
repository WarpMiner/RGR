#include "include.h"

using namespace std;

int genShift() {
    int shift = 1 + rand() % 159;
    int leftRight = rand() % 2;
    return (leftRight == 0) ? -shift : shift;
}

string CaesarEncryption(const string& message, const int& shift, int key) {
    string Encrypted;

    for (char ch : message) {
        for (int i = 0; i < n; ++i) {
            if (ch == alphabet[i]) {
                int newIndex = (i + (shift * key) % 159 + n) % n;
                Encrypted += alphabet[newIndex];
                break; // Прерываем внутренний цикл, так как символ найден
            }
        }
    }
    return Encrypted;
}

string CaesarDescryption(const string& message, const int& shift, int key) {
    string Descrypted;

    for (char ch : message) {
        for (int i = 0; i < n; ++i) {
            if (ch == alphabet[i]) {
                int newIndex = (i - (shift * key) % 159 + n) % n;
                Descrypted += alphabet[newIndex];
                break; // Прерываем внутренний цикл, так как символ найден
            }
        }
    }

    return Descrypted;
}

vector<char> checkInputCaesar(const string& message) {
    vector<char> errorInput;
    for (char ch : message) {
        bool valid = false;
        for (int i = 0; i < n; ++i) {
            if (ch == alphabet[i]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            errorInput.push_back(ch);
        }
    }
    return errorInput;
}
