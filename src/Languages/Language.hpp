#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "string"
#include "unordered_map"
#include "vector"
#include <iostream>
#include <memory>

struct ToolInfo {
  std::string version;
  bool loaded;

  ToolInfo(const std::string &ver, bool load) : version(ver), loaded(load) {}

  void set_version(const std::string &ver) { version = ver; }
  void set_loaded(bool load) { loaded = load; }
};

using ToolMap = std::unordered_map<std::string, std::vector<ToolInfo>>;
using LoadedTool = std::pair<std::string, std::string>;

class Language {
public:
  virtual const ToolMap &get_tools() const = 0;
  virtual constexpr std::string get_name() const = 0;

  virtual std::vector<LoadedTool> get_loaded_tools() {
    const auto &tools = get_tools();
    std::vector<LoadedTool> loaded_tools = {};

    for (const auto &tool : tools) {
      std::string name = tool.first;
      for (auto &tool_info : tool.second) {
        if (!tool_info.loaded) {
          std::cout << "Skipping " << name << " - not loaded" << std::endl;
          continue;
        }
        loaded_tools.push_back({name, tool_info.version});
      };
    }

    return loaded_tools;
  }

  virtual void load_tool(const std::string &name, const std::string &version) {
    auto &tools = const_cast<ToolMap &>(get_tools());

    for (auto &tool : tools) {
      if (tool.first != name) {
        continue;
      }
      for (auto &tool_info : tool.second) {
        std::cout << "Loading - " << name << ": ";
        tool_info.set_loaded(true);
        tool_info.set_version(version);
      };
    }
  }

  virtual ~Language() = default;
};

#endif // LANGUAGE_H
