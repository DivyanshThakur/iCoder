#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include "ISaveable.hpp"
#include "../constant/enum.hpp"

class FileHandler
{
    static std::string toString(const ISaveable &iSaver);
    static std::pair<std::string, std::string> getPair(const std::string &line);

public:
    static void save(const ISaveable &iSaver);
    static void load(ISaveable &iSaver, const std::string &tag = "");
    static bool find(const ISaveable &iSaver, const std::string &tag);
    static bool empty(const ISaveable &iSaver);
    static std::vector<std::pair<std::string, std::string>> searchAll(const ISaveable &iSaver);
    static void print(std::ofstream &outFile, const std::vector<std::pair<std::string, std::string>> &vec);
    static void print(std::ofstream &outFile, const std::pair<std::string, std::string> &pair);
    static std::string nameGenerator(const ISaveable &iSaver, const std::string &title);
    static void saveActiveUser(const std::string &userID);
    static void updateStats(enum Status &stats, int c);
};

#endif