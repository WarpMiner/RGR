#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

const int n = 159;
const char alphabet[n] = {
                'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З',
                'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р',
                'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ',
                'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'A', 'B', 'C',
                'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
                'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                'w', 'x', 'y', 'z', 'а', 'б', 'в', 'г', 'д',
                'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м',
                'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х',
                'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю',
                'я', '+', '-', '*', '/', '=', ' ', '.', ',',
                '!', '?', '<', '>', ':', ';', '"', '&', '^',
                '%', '$', '#', '№', '@', '`', '~', '(', ')',
                '[', ']', '{', '}', '|', '0', '1', '2', '3',
                '4', '5', '6', '7', '8', '9'
};

const string my_password = "2453";

int genShift();
string CaesarEncryption(const string& message, const int& shift, int key);
string CaesarDescryption(const string& message, const int& shift, int key);
vector<char> checkInputCaesar(const string& message);

string A1Z26Encryption(const string& message, int key);
string A1Z26Descryption(const string& message, int key);
vector<char> checkInputA1Z26(const string& message);

int modExp(int base, int exp, int mod);
int SharedSecretKey(int a, int b);
