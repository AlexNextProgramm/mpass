
#include <fstream>
#include <filesystem>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

namespace fs = std::filesystem;
using namespace std;

char getch_no_echo() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout); // Очистить буфер вывода

    tcgetattr(STDIN_FILENO, &old); // Получить текущие настройки терминала
    struct termios new_t = old;
    new_t.c_lflag &= ~ECHO; // Отключить эхо-символов
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t); // Применить новые настройки

    read(STDIN_FILENO, &buf, 1); // Прочитать один символ
    tcsetattr(STDIN_FILENO, TCSANOW, &old); // Восстановить исходные настройки

    return buf;
}

std::string cpass(const std::string& prompt){
   std::string password;
        char ch;

        std::cout << prompt;
        do {
            ch = getch_no_echo(); // Читаем символ без эха
            if (ch != '\r' && ch != '\n') {
                password += ch;
                std::cout << '*';
            }
        } while (ch != '\r' && ch != '\n');
    return password;
}