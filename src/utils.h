#include <cstring>
#include <iostream>

#define MAX_BUFFER_SIZE 32768

namespace zlib_wrapper {

std::string compress_string(const std::string&, int);

}

namespace zstd_wrapper {

std::string compress_string(const std::string&, int);

}

