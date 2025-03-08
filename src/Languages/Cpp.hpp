#ifndef CPP_H
#define CPP_H

#include "Language.hpp"

class Cpp : public Language {
  const ToolMap &get_tools() const override {
    static const ToolMap tools = {{"emscripten", {ToolInfo("latest", false)}},
                                  {"cmake", {ToolInfo("latest", false)}},
                                  {"ninja", {ToolInfo("3", false)}}};
    return tools;
  }

  const std::string get_name() const override { return "Cpp"; }
};
#endif // CPP_H