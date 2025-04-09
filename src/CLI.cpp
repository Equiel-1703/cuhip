#include <iostream>

#include "CLI.hpp"

void CLI::show_help()
{
    std::cout << "* USAGE:" << std::endl;
    std::cout << "\t" << __APP_NAME << " [OPTIONS] <cuda_file>" << std::endl;
    std::cout << "* OPTIONS:" << std::endl;
    std::cout << "\t-h, --help\tShow this help message" << std::endl;
    std::cout << "\t-v, --version\tShow version information" << std::endl;
    std::cout << "\t-V, --verbose\tEnable verbose output" << std::endl;
}

void CLI::show_version()
{
    std::cout << __APP_NAME << " v" << __APP_VERSION << " - " << __APP_DESCRIPTION << std::endl;
    std::cout << "\n© " << __APP_AUTHOR << std::endl;
    std::cout << "This program is licensed under the " << __APP_LICENSE << " license." << std::endl;
}