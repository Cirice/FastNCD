// Copyright 2007 Timo Bingmann <tb@panthema.net>
// Distributed under the Boost Software License, Version 1.0.
// (See http://www.boost.org/LICENSE_1_0.txt)

// Original link http://panthema.net/2007/0328-ZLibString.html WITH A FEW MODIFICATIONS
// For zlib's internal detail please see its documentations at https://www.zlib.net/manual.html

#include "utils.h"

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <zlib.h>
#include <zstd.h>


/** Compress a STL string using zlib with given compression level and return
  * the binary data. */
std::string zlib_wrapper::compress_string(const std::string& str,
                            int compressionlevel = Z_BEST_COMPRESSION)
{
    z_stream zs;                        // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (deflateInit(&zs, compressionlevel) != Z_OK)
        throw(std::runtime_error("deflateInit failed while compressing."));

    zs.next_in = (Bytef*)str.data();
    zs.avail_in = str.size();           // set the z_stream's input

    int ret;
    char outbuffer[MAX_BUFFER_SIZE];
    std::string outstring;

    // retrieve the compressed bytes blockwise
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = deflate(&zs, Z_FINISH);

        if (outstring.size() < zs.total_out) {
            // append the block to the output string
            outstring.append(outbuffer,
                             zs.total_out - outstring.size());
        }
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) {          // an error occurred that was not EOF
        std::ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(std::runtime_error(oss.str()));
    }

    return outstring;
}


std::string zstd_wrapper::compress_string(const std::string& str,
                            int compressionlevel = ZSTD_maxCLevel())
{


std::string outstring;

size_t x = ZSTD_compress(outstring.c_str(), outstring.size(),
                str.c_str(), str.size(), compressionlevel);

/*
  Compresses `src` content as a single zstd compressed frame into already allocated `dst`.
  Hint : compression runs faster if `dstCapacity` >=  `ZSTD_compressBound(srcSize)`.
  @return : compressed size written into `dst` (<= `dstCapacity),
            or an error code if it fails (which can be tested using ZSTD_isError()). 
*/

return outstring;

}
