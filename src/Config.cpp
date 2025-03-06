#include <iostream>
#include <yaml-cpp/yaml.h>

#include "Config.hpp"
#include "Languages/LanguageFactory.hpp"

Config::Config(const std::string &yaml_file) {
  try {
    load_yaml_config(yaml_file);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE); // Optionally exit if exception is caught
  }
}

void Config::load_yaml_config(const std::string &yaml_file) {
  YAML::Node config = YAML::LoadFile(yaml_file);
  std::unique_ptr factory = std::make_unique<LanguageFactory>();
  // handle empty yaml?

  if (config["repositories"]) {
    auto repos_node = config["repositories"];
    if (repos_node["clone_path"]) {
      repositories.clone_path = repos_node["clone_path"].as<std::string>();
    }

    for (const auto &repo : repos_node["repos"]) {
      Repository r;
      auto _repo = repo.begin();
      r.name = _repo->first.as<std::string>();
      r.url = _repo->second.as<std::string>();
      repositories.vector.push_back(r);
    }
  }
  if (config["custom_scripts"]) {
    auto custom_scripts_node = config["custom_scripts"];

    for (const auto &script : custom_scripts_node) {
      CustomScript s;
      auto _script = script.begin();
      s.name = _script->first.as<std::string>();
      s.cmd = _script->second.as<std::string>();
      custom_scripts.push_back(s);
    }
  }
  if (config["languages"]) {
    auto languages_node = config["languages"];

    for (const auto &language_entry : languages_node) {
      for (const auto &language : language_entry) {
        std::string language_name = language.first.as<std::string>();

        std::unique_ptr<Language> lang = factory->create(language_name);

        auto tools = language.second;

        if (tools.size() == 0) {
          continue;
        }

        for (const auto &tool : tools) {
          for (const auto &tool_entry : tool) {
            std::string name = tool_entry.first.as<std::string>();
            std::string version = tool_entry.second.as<std::string>();

            lang->load_tool(name, version);
          }
        }

        languages.push_back(
            std::move(lang)); // transfer ownership to languages node
      }
    }
  }
}
