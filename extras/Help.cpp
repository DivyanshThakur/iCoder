
void Extras::help()
{
    Ui::header(Constant::Title::HELP);

    std::cout << std::setw(Constant::Ui::INDEX_WIDTH) << std::left << " Key"
              << "    Description";

    Ui::border();

    size_t i, size{Constant::SubMenu::HELP_DATA.size()};

    for (i = 0; i < size; i++)
    {

        std::cout << " " << std::setw(Constant::Ui::INDEX_WIDTH) << std::left << Constant::SubMenu::HELP_DATA.at(i)
                  << "-> " << Constant::SubMenu::HELP_DESC.at(i);

        if (i < size - 1)
            std::cout << std::endl;
    }

    Ui::println("*Can be used only in menu screen");
}