#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include "ISaveable.hpp"
#include "../namespace/header/cod_pair.hpp"

class FileHandler
{
    static std::string file_str(const ISaveable &iSaver);
    static cod::pair<std::string, std::string> get_pair(const std::string &line);

public:
    static void save(const ISaveable &iSaver);
    static void load(ISaveable &iSaver, const std::string &tag = "");
    static bool find(const ISaveable &iSaver, const std::string &tag);
    static bool is_empty(const ISaveable &iSaver);
    static std::vector<cod::pair<std::string, std::string>> search_all(const ISaveable &iSaver);
    static void print(std::ofstream &outFile, const std::vector<cod::pair<std::string, std::string>> &vec);
    static void print(std::ofstream &outFile, const cod::pair<std::string, std::string> &pair);
    static std::string name_generator(const ISaveable &iSaver, const std::string &title);
    static void save_active_user(const std::string &userID);
    static void update_stats(enum Status &stats, int c);
};

#endif