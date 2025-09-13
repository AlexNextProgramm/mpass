
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
    fflush(stdout); 

    tcgetattr(STDIN_FILENO, &old);
    struct termios new_t = old;
    new_t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    read(STDIN_FILENO, &buf, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);

    return buf;
}

std::string cpass(const std::string& prompt){
   std::string password;
        char ch;

        std::cout << prompt;
        do {
            ch = getch_no_echo();
            if (ch != '\r' && ch != '\n') {
                password += ch;
                std::cout << '*';
            }
        } while (ch != '\r' && ch != '\n');
    return password;
}