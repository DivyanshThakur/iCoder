#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include "../base/header/AbstractSaveable.hpp"

class FileHandler
{
    static std::string toString(const AbstractSaveable &iSaver);
    static std::vector<std::pair<std::string, std::string>> toVector(std::stringstream &ss);
    static std::pair<std::string, std::string> getPair(const std::string &line);
    static void updateSavedNumbers(std::string &numbers, int dig);
    static void saveDefName(std::ofstream &outFile, const AbstractSaveable &iSaver, std::stringstream &ss);

public:
    static void save(const AbstractSaveable &iSaver);
    static void load(AbstractSaveable &iSaver, const std::string &tag = "");
    static bool find(const AbstractSaveable &iSaver, const std::string &tag);
    static bool empty(const AbstractSaveable &iSaver);
    static std::vector<std::pair<std::string, std::string>> searchTag(const AbstractSaveable &iSaver);
    static void print(std::ofstream &outFile, const std::vector<std::pair<std::string, std::string>> &vec);
    static void print(std::ofstream &outFile, const std::pair<std::string, std::string> &pair);
    static std::string nameGenerator(const AbstractSaveable &iSaver, const std::string &title);
};

#endif