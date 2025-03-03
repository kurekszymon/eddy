#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <variant>
#include <vector>

#include "LanguageTools.hpp"

struct Repository
{
    std::string name;
    std::string url;
};

struct CustomScript
{
    std::string name;
    std::string cmd;
};

struct Language
{
    std::string name;
    std::string download_url;
};

struct Repositories
{
    std::string clone_path;
    std::vector<Repository> vector;
};

enum ConfigItem
{
    REPOSITORIES,
    CUSTOM_SCRIPTS,
};
using MLanguage = std::variant<CPP, Python, JavaScript>;

using MItem = std::variant<ConfigItem, MLanguage>;
class Config
{
public:
    std::unordered_set<MItem> loaded_items;

    Repositories repositories;
    std::vector<CustomScript> custom_scripts;

    Config(const std::string &yaml_file);

    bool is_item_loaded(MItem item); // Generic function to check if any tool from a specific language is loaded
    // Language Enums

    // TODO MOVE all language stuff to seperate class.
    std::unordered_map<std::string, MLanguage> cpp_mapper = {
        {"emscripten", CPP::emscripten},
        {"cmake", CPP::cmake},
        {"ninja", CPP::ninja}};
    std::unordered_map<std::string, MLanguage> python_mapper = {
        {"python3", Python::PYTHON3},
        {"cpython", Python::CPYTHON}};
    std::unordered_map<std::string, MLanguage> js_mapper = {
        {"node", JavaScript::NODEJS},
        {"v8", JavaScript::V8}};

    std::unordered_map<std::string, std::unordered_map<std::string, MLanguage>> language_mapper = {
        {"cpp", cpp_mapper},
        {"python", python_mapper},
        {"js", js_mapper}};

    template <typename T>
    bool is_any_tool_from_language_loaded()
    {
        const auto &enum_values = LanguageTools<T>::values;

        for (const auto &value : enum_values)
        {
            std::cout << static_cast<int>(value) << "value.. ";
            return Config::is_item_loaded(value);
        }

        return false;
    };

private:
    void load_yaml_config(const std::string &yaml_file);
    void load_item(MItem item);
};

#endif // CONFIG_H
