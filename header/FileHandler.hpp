#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include "ISaveable.hpp"

class FileHandler
{
    static std::string toString(const ISaveable &iSaver);
    static std::vector<std::pair<std::string, std::string>> toVector(std::stringstream &ss);
    static std::pair<std::string, std::string> getPair(const std::string &line);
    static void print(std::ofstream &outFile, const std::vector<std::pair<std::string, std::string>> &vec);

public:
    static void save(const ISaveable &iSaver);
    static void load(ISaveable &iSaver, const std::string &tag = "");
    static bool find(const ISaveable &iSaver, const std::string &tag);
    static bool empty(const ISaveable &iSaver);
    static std::vector<std::pair<std::string, std::string>> searchTag(const ISaveable &iSaver);
    static void print(std::ofstream &outFile, const std::pair<std::string, std::string> &pair);
    static std::string nameGenerator(const ISaveable &iSaver, const std::string &title);
};

#endif