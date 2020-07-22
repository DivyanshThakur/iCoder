#ifndef UI_HPP
#define UI_HPP

#include <vector>
#include <string>

class Ui
{
public:
    static void logo();
    static std::string getTip();
    static void updateLastScreen();
    static void updateScreen(const std::string &heading);
    static void header(const std::string &heading);
    static void subHeader(const std::string &heading);
    static std::vector<std::string> getHint();
    static void border();
    static void popUp(const std::string &message);
    static void animater(const std::string &anime);
    static void getchForced();
    static void print(const std::string &message);
    static void print(const std::vector<std::string> &vec);
    static void println(const std::string &message);
    static void println(const std::vector<std::string> &vec);
    static void pressKey(const std::string &message = "Press any key to continue");
    static bool isKeyPressed(const std::string &message, char c = 'i');
    static void waitMessage(const std::string &message);
    static bool confirmChange(const std::string &message = "Do you want to proceed?");
};

#endif