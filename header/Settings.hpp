#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <vector>
#include "ISaveable.hpp"
#include "../namespace/header/cod_pair.hpp"

void settings();

class Settings : public ISaveable
{
public:
    /************************************ ISAVEABLE PURE VIRTUAL FUNCTION ****************************************/

    virtual std::vector<std::pair<std::string, std::string>> save() const override;
    virtual void load(const std::vector<std::pair<std::string, std::string>> &vecData) override;
    virtual std::string getPath() const override;
    virtual bool generate() const override;

    /******************************************* MEMBER FUNCTIONS ***********************************************/

    void start();
    bool isDefault() const;
    void save(const std::pair<std::string, std::string> &pair);
    void show_me_first(const std::string &message, int repeatFor);

    virtual ~Settings() = default;

private:
    std::pair<std::string, std::string> pairBuffer;

    std::string state_selector(bool isTrue);
    void settings_controller(char ch);
    std::vector<std::string> settings_screen_selector();
    void change_text_anime_speed();
    void change_lsearch_type();
    void change_shortcuts_type();
    void change_home_screen();
    void change_theme_type();
    void change_anime_style();
    void change_display_style();
    void welcome_message();
    void quit_message();
    void hint_message();
    void reset();
};

#endif