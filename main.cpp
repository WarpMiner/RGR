#include "caesar.cpp"
#include "a1z26.cpp"
#include "diffiehellman.cpp"
#include "include.h"

string FileInput(string filename) { // ф-ия вывода из файла
    string str;
    ifstream input;
    input.open(filename);
    if (input.is_open()) {
        getline(input, str);
        input.close();
        return str;
    } else {
        return "Error: Unable to open the file";
    }
}

string FileOutput(string filename, string str) { // ф-ия ввода в файл
    ofstream output;
    output.open(filename);
    if (output.is_open()) {
        output << str;
        output.close();
        return "Completed";
    } else {
        return "Error: Unable to open the file";
    }
}

void input_and_check(string& message, string choice_shifr) { // ф-ия ввода сообщения с клавиатуры и его проверка
    cout << "Введите сообщение: ";
    cin.ignore();
    while (true) {
        getline(cin, message);
        vector<char> errorinput;
        if (choice_shifr == "Caesar") {
            errorinput = checkInputCaesar(message);
        } else if (choice_shifr == "A1Z26") {
            errorinput = checkInputA1Z26(message);
        }
        if (!errorinput.empty()) {
            cout << "   : ";
            for (auto elem : errorinput) {
                cout << elem << " ";
            }
            cout << endl << "Повторите попытку ввода: ";
        } else {
            cout << "Сообщение принято!" << endl;
            break;
        }
    }

}

void Crypt(string choice_shifr, int key) {
    string message, wordkey, filename;
    int shift;
    int p, g;
    
    if (choice_shifr == "Caesar") {
        input_and_check(message, "Caesar");
        shift = genShift();
    } else if (choice_shifr == "A1Z26") {
        input_and_check(message, "A1Z26");
    } else if (choice_shifr == "DiffieHellman") {
        int a, b;
        cout << "Введите секретный ключ участника A: ";
        cin >> a;
        cout << "Введите секретный ключ участника B: ";
        cin >> b;
        int K = SharedSecretKey(a, b);
        cout << "1 - шифр Цезаря\n" << "2 - шифр A1Z26\n" << "Выберите шифр, с которым использовать общий секретный ключ: ";        
        int choice;
        cin >> choice;

        if (choice == 1) {
            Crypt("Caesar", K);
        } else if (choice == 2) {
            Crypt("A1Z26", K);
        } else {
            cout << "Выбран неверный номер шифра!";
        }
        return;
    }

    cout << "Введите название файла, в который будет записано сообщение: ";
    cin >> filename;
    FileOutput(filename, message);

    // ШИФРОВКА //
    message = FileInput(filename);
    string Encrypted, Descrypted;
    if (choice_shifr == "Caesar") {
        Encrypted = CaesarEncryption(message, 17, key);
    } else if (choice_shifr == "A1Z26") {
        Encrypted = A1Z26Encryption(message, key);
    }
    else if (choice_shifr == "DiffieHellman") {
    }
    cout << "Зашифрованное сообщение: " << Encrypted << endl;
    cout << "Введите название файла, в который будет записано зашифрованное сообщение: ";
    cin >> filename;
    string check = FileOutput(filename, Encrypted); // записываем в файл
    if (check != "Completed") {
        cout << "Ошибка, невозможно открыть файл " << filename << "!" << endl;
    } else {
        cout << "Сообщение записано в файл " << filename << "!" << endl;
                
        // Расшифровка //
        cout << "Расшифровать сообщение? Для подтверждения введите /y/ или /Y/: ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            Encrypted.clear();
            cout << "Введите название файла, в котором хранится зашифрованное сообщение: ";
            cin >> filename;
            Encrypted = FileInput(filename);
            if (Encrypted != "Error: Unable to open the file") {
                if (choice_shifr == "Caesar") {
                    Descrypted = CaesarDescryption(Encrypted, -17, key);
                } else if (choice_shifr == "A1Z26") {
                    Descrypted = A1Z26Descryption(Encrypted, key);
                } else if (choice_shifr == "DiffieHellman") {
                }
                cout << "Расшифрованное сообщение: " << Descrypted << endl;
                cout << "Введите название файла, в котором будет хранится зашифрованный файл: ";
                cin >> filename;
                check = FileOutput(filename, Descrypted); // записываем в файл
                if (check != "Completed") {
                    cout << "Ошибка, невозможно открыть файл " << filename << "!" << endl;
                } else {
                    cout << "Сообщение записано в файл " << filename << "!" << endl;
                }
            } else {
                cout << "Ошибка, невозможно открыть файл " << filename << "!" << endl;
            }
        }
    }
}

int main() {
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    string password;
    cout << "Введите пароль: ";
    cin >> password;

    if (password != my_password) {
        cout << "Пароль неверный! Попробуйте ещё раз. Осталось 2 попытки: ";
        cin >> password;
        if (password != my_password) {
            cout << "Пароль неверный! Осталась 1 попытка: ";
            cin >> password;
            if (password != my_password) {
                cout << "Пароль неверный!\nВыход из программы...";
                exit(0);
            }
        }
    }

    system("cls");
    cout << "\nДобро пожаловать!\n" << "------------------------------\n" << "1 - шифр Цезаря\n" 
    << "2 - шифр A1Z26\n" << "3 - алгоритм Диффи-Хелмана\n\n" << "0 - выйти из программы\n" 
    << "------------------------------\n";

    while (true) {
        
        int choice;
        while (true) {
            try { // обработка ошибки
                cout << "\nВыберите номер шифра: ";
                cin >> choice;
                if (cin.fail()) {
                    throw invalid_argument("Вводите только число!");
                }
                break;
            } catch (invalid_argument& ex) { // ловим ошибку, выводим её пользователю и запрашиваем ввод заново
                cin.clear();
                cin.ignore();
                cout << "Ошибка: " << ex.what() << endl;
            }
        }

        if (choice == 1) {
            Crypt("Caesar", 1);
        } else if (choice == 2) {
            Crypt("A1Z26", 1);
        } else if (choice == 3) {
            Crypt("DiffieHellman", 1);
        } else if (choice == 0) {
            cout << "Выход из программы...";
            exit(0);
        } else {
            cout << "Выбран неверный номер шифра!" << endl;
        }
    }

    return 0;
}
