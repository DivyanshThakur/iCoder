#ifndef SETTINGS_HPP
#define SETTINGS_HPP

/** FUNCTION PROTOTYPES **/
void show_me_first(const std::string &message, int repeatFor);
std::string state_selector(bool isTrue);
void settings();
void settings_controller(char ch);
std::vector<std::string> settings_screen_selector();
void change_text_anime_speed();
void change_lsearch_type();
void warnings();
void welcome_message();
void quit_message();
void hint_message();
void reset();

#endif