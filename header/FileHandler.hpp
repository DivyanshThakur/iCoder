#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include "Constants.hpp"
#include "../namespace/header/cod_pair.hpp"

/*********************************************** ISAVEABLE INTERFACE **********************************************/

class ISaveable
{
public:
    virtual std::vector<cod::pair<std::string, std::string>> save() const = 0;
    virtual void load(const std::vector<std::pair<std::string, std::string>> &vecData) = 0;

    virtual ~ISaveable() = default;
};

/*********************************************** FUNCTION PROTOTYPES ***********************************************/

void restore_saved_changes();
void update_stats(enum Status &stats, int c);
bool check_default_settings();
void save_active_user(const std::string &userID);

std::string get_file_str(const std::string &fileName);

template <typename T>
void save_to_file(const std::string &fileName, const std::string &title, const T &data);

void save_to_file(const std::string &fileName, const std::string &title, const ISaveable &iSave);

// Loading class data
void load_from_file(const std::string &fileName, const std::string &title, ISaveable &iSave);

template <typename T>
void print_to_file(std::ofstream &outFile, const std::string &title, const T &data);

void print_to_file(std::ofstream &outFile, const cod::pair<std::string, std::string> &pair);

#endif