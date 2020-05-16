#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include "Constants.hpp"

/*********************************************** ISAVEABLE INTERFACE **********************************************/

class ISaveable
{
public:
    virtual std::string save() const = 0;
    virtual void load(const std::string &data) = 0;

    virtual ~ISaveable() = default;
};

/*********************************************** FUNCTION PROTOTYPES ***********************************************/

void restore_saved_changes();
void update_stats(enum Status &stats, int c);
bool check_default_settings();
void save_active_user(const std::string &userID);

template <typename T>
void save_to_file(const std::string &fileName, const std::string &title, const T &data);

// Loading class data
void load_from_file(const std::string &filename, const std::string &title, ISaveable &iSave);

template <typename T>
void print_to_file(std::ofstream &outFile, const std::string &title, const T &data);

#endif