#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

bool loadEnvFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        if (setenv(key.c_str(), value.c_str(), 1) != 0) {
            std::cerr << "Не удалось установить переменную окружения: " << key << std::endl;
            return false;
        }
    }
    return true;
}