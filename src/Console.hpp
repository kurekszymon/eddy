#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "boost/process.hpp"
#include "boost/filesystem.hpp"

#include "Config.hpp"
namespace bp = boost::process;
namespace bfs = boost::filesystem;

class Console
{
public:
    inline static std::string retrieve_std_out(bp::ipstream &pipe_stream)
    {
        std::string output;

        std::string line;
        while (std::getline(pipe_stream, line))
        {
            output += line + "\n \t"; // Append each line of output to the string
        }

        pipe_stream.close();
        return output;
    };
    inline static std::string parse_home_dir(std::string input_path)
    {
        if (input_path.empty() || input_path[0] != '~')
        {
            return input_path;
        }

        const char *env_home = std::getenv("HOME");               // Unix-like systems (Linux/macOS)
        const char *env_userprofile = std::getenv("USERPROFILE"); // Windows

        bfs::path home_dir = env_home ? env_home : env_userprofile;

        // handle home not found - decide for try catch / throwing

        bfs::path result = home_dir / input_path.substr(1);
        return result.string();
    };
    inline static std::string execute_custom_command(CustomScript command, std::string messages)
    {
        try
        {
            bp::ipstream std_out;
            bp::ipstream std_err;

            std::vector<std::string> args = {"-c", command.cmd};

            bp::child c(bp::search_path("sh"), args, bp::std_out > std_out, bp::std_err > std_err);

            c.wait();

            std::string output = retrieve_std_out(std_out);
            std::string err_output = retrieve_std_out(std_err);

            if (!err_output.empty())
            {
                return err_output;
            }

            return output;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error during custom command execution: " << e.what() << "\n";
            std::string error_message = e.what();
            return error_message;
        }
    }
    inline static std::string execute_git_clone(const std::string &repo_url, const std::string &clone_dir)
    {
        try
        {
            bp::ipstream std_out;
            bp::ipstream std_err;
            std::vector<std::string> args = {"clone", repo_url, parse_home_dir(clone_dir)};

            bp::child c(bp::search_path("git"), args, bp::std_out > std_out, bp::std_err > std_err);

            c.wait();

            std::string output = retrieve_std_out(std_out);
            std::string err_output = retrieve_std_out(std_err);

            if (!err_output.empty())
            {
                return err_output;
            }

            return output;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error during git clone: " << e.what() << "\n";
            std::string error_message = e.what();
            return error_message;
        }
    };
};

#endif // CONSOLE_H
