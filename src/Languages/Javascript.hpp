#ifndef JAVASCRIPT_H
#define JAVASCRIPT_H

#include "Language.hpp"

class Javascript : public Language {
  const ToolMap &get_tools() const override {
    static const ToolMap tools = {{"nvm", {ToolInfo("latest", false)}},
                                  {"node", {ToolInfo("21", false)}}};
    return tools;
  }

  const std::string get_name() const override { return "Javascript"; }
};
#endif // JAVASCRIPT_H