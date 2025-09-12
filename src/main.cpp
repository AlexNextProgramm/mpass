#include "./header/autoload.h"
#include <vector>


int main() {
    MPass mp("pass");
    std::string key = "";
    while (true)
    {
        if (key == "")
        {
            key = cpass("Введите пароль шифрования: ");
            std::cout << "\n";
        }


        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::vector<std::string> args;
        std::string retrieved;
        std::string word;

        while (iss >> word) {
            args.push_back(word);
        }

        if (args.empty()) continue;

        std::string ar = args[0];
        std::string ar2 = (args.size() > 1) ? args[1] : "";
        std::string ar3 = (args.size() > 2) ? args[2] : "";

        if (ar == "a" || ar == "add")
        {
            if(ar2 == "" || ar3 == ""){
                std::cout << "Требуется название и пароль add [name] [password] \n";
            }
            mp.addPassword(ar2, ar3, key);
            std::cout << "Пароль добавлен \n";
        }

        if (ar == "g" || ar == "get"){
            if(ar2 == ""){
                std::cout << "Требуется название  get [name] \n";
            }

            if (mp.getPassword(ar2, key, retrieved))
            {
                std::cout << "Пароль: " << retrieved << "\n";
            }
            else
            {
                std::cout << "Нет такого сервиса\n";
            }
        }
        
        if (ar == "list"){
             std::cout << "===================== \n";
             mp.list();
        }

        if (ar == "r" || ar == "delete")
        {
            mp.removePassword(ar2);
        }

        if (ar == "-help" || ar == "h" || ar == "help")
        {
            std::cout << "-help | h | help - помощь \n";
            std::cout << "(g | get) [name] - получить пароль \n";
            std::cout << "(a | add) [name] [passwor] - Добавить пароль \n";
            std::cout << "(r | delete) [name]  - удалить пароль \n";
            std::cout << "list  - список \n";
            std::cout << "end | exit  - выйти из программы \n";
        }

        if(ar == "exit" || ar == "end"){
            return 0;
        }

        if (mp.getPassword(ar, key, retrieved)){
             std::cout << "Пароль: " << retrieved << "\n";
        }
    }

    return 0;
}