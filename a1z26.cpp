#include "include.h"

using namespace std;

// Функция для шифровки
string A1Z26Encryption(const string& message, int key) {
    string encrypted;
    for (char ch : message) {
        const char* it = find(alphabet, alphabet + n, ch);
        if (it != alphabet + n) {
            int index = (distance(alphabet, it) + key) % 159;
            encrypted += to_string(index) + " ";
        } else {
            encrypted += ch;
        }
    }
    return encrypted;
}

// Функция для расшифровки
string A1Z26Descryption(const string& message, int key) {
    stringstream ss(message);
    string token;
    string decrypted;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int index = (stoi(token) - key) % 159;
            if (index >= 0 && index < n) {
                decrypted += alphabet[index];
            }
        } else {
            decrypted += token;
        }
    }
    return decrypted;
}

vector<char> checkInputA1Z26(const string& message) {
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
