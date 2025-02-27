#include "include.h"

using namespace std;

// Функция для вычисления (base^exp) % mod
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int SharedSecretKey(int a, int b) {
    int p = 23;
    int g = 5;

    // Публичные ключи участников
    int A = modExp(g, a, p);
    int B = modExp(g, b, p);

    // Обмен публичными ключами и вычисление общего секрета
    int secretA = modExp(B, a, p);
    int secretB = modExp(A, b, p);

    // Общий секрет должен совпадать
    if (secretA == secretB) {
        cout << "Общий секретный ключ: " << secretA << endl;
    } else {
        cout << "Ошибка в вычислении общего секрета." << endl;
    }

    return secretA;
}
