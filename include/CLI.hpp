#pragma once

#define __APP_NAME "cuhip"
#define __APP_VERSION "0.0.1"
#define __APP_AUTHOR "Henrique Gabriel Rodrigues"
#define __APP_LICENSE "MIT"
#define __APP_DESCRIPTION "A tool to help with CUDA-HIP conversion and compilation"

#ifdef _WIN32
    #define NULL_PIPE std::string("nul")
#endif

#ifdef __linux__
    #define NULL_PIPE std::string("/dev/null")
#endif

class CLI
{
public:
    void show_help();
    void show_version();

};
