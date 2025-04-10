#include <iostream>
#include <filesystem>
#include <string>

#include "CLI.hpp"

namespace fs = std::filesystem;
using std::string;

bool check_hipify_hipcc()
{
    string hipify_check = "hipify-clang --version >" + NULL_PIPE + " 2>&1";
    string hipcc_check = "hipcc --version >" + NULL_PIPE + " 2>&1";

    int status_hipify = system(hipify_check.c_str());
    if (status_hipify != 0)
        throw std::runtime_error("hipify-clang is not installed or not in PATH");

    int status_hipcc = system(hipcc_check.c_str());
    if (status_hipcc != 0)
        throw std::runtime_error("hipcc is not installed or not in PATH");

    return true;
}

int main(int argc, char const *argv[])
{
    CLI cli;

    if (argc < 2 || argc > 3)
    {
        cli.show_help();
        return 1;
    }

    // Check if hipify and hipcc are available
    try
    {
        check_hipify_hipcc();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    string option = string(argv[1]);
    fs::path source_file = argc == 2 ? fs::path(argv[1]) : fs::path(argv[2]);
    bool verbose = false;

    // Processing options
    if (option == "--help" || option == "-h")
    {
        cli.show_help();
        return 0;
    }
    else if (option == "--version" || option == "-v")
    {
        cli.show_version();
        return 0;
    }
    else if (option == "--verbose" || option == "-V")
    {
        if (argc < 3)
        {
            std::cerr << "ERROR: You must provide a file to use this option!" << std::endl;
            return 1;
        }

        verbose = true;
    }

    // Check if the file exists
    if (!fs::exists(source_file))
    {
        std::cerr << "ERROR: The file " << source_file << " does not exist!" << std::endl;
        return 1;
    }

    if (verbose)
        std::cout << "File exists: " << source_file << " - OK!" << std::endl;

    // Check if the file is a valid CUDA file
    if (source_file.extension() != ".cu")
    {
        std::cerr << "ERROR: The file " << source_file << " is not a valid CUDA file!" << std::endl;
        std::cout << source_file.extension() << std::endl;
        return 1;
    }

    if (verbose)
    {
        std::cout << "File is a valid CUDA file: " << source_file << " - OK!" << std::endl;
        std::cout << "Hipifying the file..." << std::endl;
    }

    // Hipify the file
    fs::path hipified_output = source_file.parent_path() / source_file.stem() += ".hip";

    std::cout << "-- Hipify output:" << std::endl;
    int ret_hipify = system(("hipify-clang " + source_file.string() + " -o " + hipified_output.string()).c_str());
    if (ret_hipify != 0)
    {
        std::cerr << "ERROR: Failed to hipify the file " << source_file << "!" << std::endl;
        return 1;
    }
    std::cout << std::endl;

    if (verbose)
    {
        std::cout << "Hipified file successfully to: " << hipified_output << " - OK!" << std::endl;
        std::cout << "Compiling the hipified file..." << std::endl;
    }

    // Compile the hipified file
    fs::path compiled_output = source_file.parent_path() / source_file.stem() += ".out";

    std::cout << "-- Hipcc output:" << std::endl;
    int ret_compile = system(("hipcc " + hipified_output.string() + " -o " + compiled_output.string()).c_str());
    if (ret_compile != 0)
    {
        std::cerr << "ERROR: Failed to compile the hipified file " << hipified_output << "!" << std::endl;
        return 1;
    }
    std::cout << std::endl;

    if (verbose)
    {
        std::cout << "Compiled successfully to: " << compiled_output << " - OK!" << std::endl;
    }

    // Completion message
    std::cout << "Hipification and compilation completed successfully!" << std::endl;

    return 0;
}
