
void Extras::about()
{
    Ui::header(Constant::Title::ABOUT);

    std::vector<std::string> aboutVec;
    aboutVec.emplace_back("Developer: " + Constant::iCoder::DEV);
    aboutVec.emplace_back("Version:   " + Constant::iCoder::VERSION);
    Ui::print(aboutVec);

    Ui::subHeader(Constant::Title::LINKS);

    std::cout << "Source code:" << std::endl
              << Constant::Url::SRC.substr(8);

    if (Ui::isKeyPressed("Press i to open URL"))
        system(("start " + Constant::Url::SRC).c_str());
}