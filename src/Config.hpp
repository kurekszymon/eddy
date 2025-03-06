#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

#include "Languages/LanguageFactory.hpp"

struct Repository {
  std::string name;
  std::string url;
};

struct CustomScript {
  std::string name;
  std::string cmd;
};

struct Repositories {
  std::string clone_path;
  std::vector<Repository> vector;
};

enum ConfigItem {
  REPOSITORIES,
  CUSTOM_SCRIPTS,
};

class Config {
public:
  Repositories repositories;
  std::vector<CustomScript> custom_scripts;
  std::vector<std::unique_ptr<Language>> languages;

  Config(const std::string &yaml_file);

private:
  void load_yaml_config(const std::string &yaml_file);
};

#endif // CONFIG_H
