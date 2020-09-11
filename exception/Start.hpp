#ifndef START_HPP
#define START_HPP

class Start
{
public:
    virtual void start() const = 0;
    virtual ~Start() = default;
};

class EscPressed
{
};

class Exit : public Start
{
public:
    virtual void start() const override;
};

class StartSettings : public Start
{
public:
    virtual void start() const override;
};

class StartAbout : public Start
{
public:
    virtual void start() const override;
};

class StartHelp : public Start
{
public:
    virtual void start() const override;
};

class StartUpdate : public Start
{
public:
    virtual void start() const override;
};

class StartChangelog : public Start
{
public:
    virtual void start() const override;
};

class StartMore : public Start
{
public:
    virtual void start() const override;
};

// class OpenAnimeSetting : public Start
// {
//     size_t pos;

// public:
//     OpenAnimeSetting(size_t pos);
//     virtual void what() const noexcept override;
// };

#endif