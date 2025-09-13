#ifndef MPASS_H
#define MPASS_H

#include <iostream>
#include <string>
#include <unordered_map>

class MPass {
public:
    std::string filename = "pass";
    MPass(const std::string &filename) : filename(filename)
    {
        load();
    }
    MPass(){
        
    }
    ~MPass()
    {
        save();
    }
    // Добавить пароль для сервиса (шифруется ключом)
    void addPassword(const std::string& service, const std::string& password, const std::string& key);

    // Получить пароль для сервиса (расшифровывается ключом)
    bool getPassword(const std::string& service, const std::string& key, std::string& outPassword) const;

    // Удалить пароль для сервиса
    void removePassword(const std::string& service);
    void list();

    void save();
    void load();
    void setFile(const std::string &filename){
        this->filename = filename;
    }

private:
    // XOR шифрование/расшифровка
    std::string crypt(const std::string& text, const std::string& key) const;

    // Хранилище зашифрованных паролей: сервис -> зашифрованный пароль
    std::unordered_map<std::string, std::string> passwordStorage;
};

#include "MPass.cpp"
#include "echo.cpp"
#endif // MPASS_H