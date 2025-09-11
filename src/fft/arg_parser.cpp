#include "arg_parser.h"
#include <unordered_set>
#include <stdexcept>
#include <iostream>
#include <optional>

std::unordered_set<char> ArgParser::parse(int argc, char **argv)
{
    std::unordered_set<char> parsed;
    std::stringstream errors;
    std::unordered_map<char, bool> hasArg;
    for (auto &option : _options)
    {
        hasArg[option.second->option] = option.second->hasArg();
    }

    for (int i = 1; i < argc; i++)
    {
        std::string option = argv[i];
        if (option.size() != 2 && option[0] == '-')
        {
            continue;
        }
        auto current = hasArg.find(option[1]);
        if (current == hasArg.end())
        {
            continue;
        }
        bool hasData = current->second;
        if (hasData && argc != i + 1)
        {
            (*_options[option[1]])(argv[i + 1]);
        }
        else
        {
            (*_options[option[1]])(option);
        }
        _required.erase(option[1]);
        parsed.insert(option[1]);
    }

    for (auto &x : _required)
    {
        errors << "Missing option " << "-" << x << "!" << std::endl;
    }

    std::string totalErrors = errors.str();

    if (!totalErrors.empty())
    {
        throw std::runtime_error(totalErrors);
    }

    return parsed;
}

ArgParser::ArgParser(int argc, char **argv)
{
}

ArgParser::~ArgParser()
{
}
