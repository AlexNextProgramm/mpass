#include "MPass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::string MPass::crypt(const std::string& text, const std::string& key) const {
    std::string result = text;
    int keyLen = key.length();

    for (size_t i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % keyLen];
    }
    return result;
}

void MPass::addPassword(const std::string& service, const std::string& password, const std::string& key) {
    // Сохраняем зашифрованный пароль
    passwordStorage[service] = crypt(password, key);
    this->save();
}

bool MPass::getPassword(const std::string& service, const std::string& key, std::string& outPassword) const {
    // Ищем сервис
    auto it = passwordStorage.find(service);
    if (it == passwordStorage.end()){
        return false;
    }

    outPassword = crypt(it->second, key);
    return true;
}

void MPass::removePassword(const std::string& service) {
    passwordStorage.erase(service);
    
    this->save();
}

void MPass::save() {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }
    for (const auto& pair : passwordStorage) {
        outFile << pair.first << '\t' << pair.second << '\n';
    }
    outFile.close();
}

void MPass::load() {
    std::ifstream inFile(filename);
    if (!inFile) {
        return;
    }
    std::string service, encryptedPassword;
    while (std::getline(inFile, service, '\t') && std::getline(inFile, encryptedPassword)) {
        passwordStorage[service] = encryptedPassword;
    }
}
void MPass::list(){
     if (passwordStorage.empty()) {
        std::cout << "Список паролей пуст." << std::endl;
        return;
    }

    std::cout << "Сохранённые сервисы:" << std::endl;
    for (const auto& pair : passwordStorage) {
        std::cout << "- " << pair.first << std::endl;
    }
}