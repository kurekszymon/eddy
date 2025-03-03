#include <array>
#include <iostream>

#ifndef LANGUAGETOOLS_H
#define LANGUAGETOOLS_H

enum class CPP
{
    emscripten,
    cmake,
    ninja
};

enum class Python
{
    CPYTHON,
    PYTHON3
};

enum class JavaScript
{
    NODEJS,
    V8
};

template <typename T>
struct LanguageTools;

template <>
struct LanguageTools<CPP>
{
    static constexpr std::array<CPP, 3> values = {
        CPP::emscripten,
        CPP::cmake,
        CPP::ninja};
};

template <>
struct LanguageTools<Python>
{
    static constexpr std::array<Python, 2> values = {
        Python::CPYTHON,
        Python::PYTHON3};
};

template <>
struct LanguageTools<JavaScript>
{
    static constexpr std::array<JavaScript, 2> values = {
        JavaScript::NODEJS,
        JavaScript::V8};
};

#endif // LANGUAGETOOLS_H