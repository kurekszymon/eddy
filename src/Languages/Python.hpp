#ifndef PYTHON_H
#define PYTHON_H

#include "Language.hpp"

class Python : public Language {
  const ToolMap &get_tools() const override {
    static const ToolMap tools = {{"pyenv", {ToolInfo("latest", false)}},
                                  {"pip", {ToolInfo("3", false)}}};
    return tools;
  }

  constexpr std::string get_name() const override { return "Python"; }
};
#endif // PYTHON_H