#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <memory>
#include <optional>

struct BaseOption
{
    char option;
    std::string name;

    BaseOption(char option, const std::string &name) : option(option), name(name)
    {
    }
    virtual ~BaseOption() = default;

    virtual std::optional<std::string> operator()(const std::string &data) = 0;

    virtual bool hasArg() const = 0;
};

template <typename T>
struct Option : public BaseOption
{
    T *ptr;
    Option(char option, const std::string &name, T *ptr) : BaseOption(option, name), ptr(ptr)
    {
    }

    Option(const Option &option) : BaseOption(option.option, option.name), ptr(option.ptr)
    {
    }

    Option &operator=(const Option &other)
    {
        ptr = other.ptr;
        option = other.option;
        name = other.name;
        return *this;
    }

    ~Option()
    {
    }

    Option<T> &defaultValue(const T &val)
    {
        *ptr = val;
        return *this;
    }

    std::optional<std::string> operator()(const std::string &data) override
    {
        T result;
        std::stringstream stream(data);
        stream >> result;
        if (!stream)
        {
            std::stringstream error("");
            error << "Failed to parse option " << name << "!" << std::endl;
            return std::make_optional<std::string>();
        }
        *ptr = result;
        return {};
    }

    bool hasArg() const
    {
        return true;
    }
};

struct BoolSwitch : public BaseOption
{
    bool *ptr;
    BoolSwitch(char option, const std::string &name, bool *ptr) : BaseOption(option, name), ptr(ptr)
    {
        *ptr = false;
    }

    BoolSwitch(const BoolSwitch &option) : BaseOption(option.option, option.name), ptr(option.ptr)
    {
    }

    BoolSwitch &operator=(const BoolSwitch &other)
    {
        ptr = other.ptr;
        option = other.option;
        name = other.name;
        return *this;
    }

    ~BoolSwitch()
    {
    }

    std::optional<std::string> operator()(const std::string &) override
    {
        *ptr = true;
        return {};
    }

    bool hasArg() const
    {
        return false;
    }
};

class ArgParser
{
private:
    /*
    Potřebuju required argumenty
    Potřeebuju default hodnoty
    */
    std::unordered_set<char> _required;
    std::unordered_map<char, std::shared_ptr<BaseOption>> _options;

public:
    ArgParser(int argc, char **argv);
    ~ArgParser();

    std::unordered_set<char> parse(int argc, char **argv);

    template <typename T>
    void addOption(bool required, const Option<T> &option)
    {
        if (required)
            _required.insert(option.option);
        _options[option.option] = std::make_shared<Option<T>>(option);
    }

    void addOption(const BoolSwitch &boolSwitch)
    {
        char option = boolSwitch.option;
        _options[option] = std::make_shared<BoolSwitch>(boolSwitch);
    }
};
