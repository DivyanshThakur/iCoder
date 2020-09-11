#include "../header/Start.hpp"
#include "../../main/header/Ui.hpp"
#include "../../settings/header/Settings.hpp"
#include "../../extras/Extras.hpp"
#include "../../main/header/More.hpp"
#include "../../constant/Constants.hpp"

void Exit::start() const
{
    bool toProceed = true;

    if (Global::showQuit)
        toProceed = Ui::confirmChange("Do you want to exit?");

    if (toProceed)
        exit(0);
}

void StartSettings::start() const
{
    Settings::start();
}

void StartAbout::start() const
{
    Extras::about();
}

void StartHelp::start() const
{
    Extras::help();
}

void StartUpdate::start() const
{
    Update::start();
}

void StartChangelog::start() const
{
    Changelog::start();
}

void StartMore::start() const
{
    More::start();
}

// OpenAnimeSetting::OpenAnimeSetting(size_t pos) : pos(pos)
// {
// }

// void OpenAnimeSetting::start() const noexcept
// {
//     std::string message{". Disable "};
//     message += Constant::Menu::SETTINGS.at(pos - 1);

//     Settings mySetting;
//     // mySetting.show_me_first(std::to_string(pos) + message, pos);
// }