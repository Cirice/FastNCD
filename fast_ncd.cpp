#include "fast_ncd.h"

#include <algorithm>
#include <string>
#include <snappy.h> // snappy compression library

#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp> // boost iostreams library
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp> // boost iostreams library gzip filter
#include <boost/iostreams/filter/zlib.hpp> // boost iostreams library zlib filter
#include <boost/iostreams/filter/bzip2.hpp> // boost iostreams library bzip2 filter
#include <boost/iostreams/filter/lzma.hpp> // boost iostreams library lzma filter

// the namespace for the NCD library

namespace compressors {
    // https://stackoverflow.com/questions/27529570/simple-zlib-c-string-compression-and-decompression
    std::string compress(std::string &data, cmp_type t) {
        // namespace aliases
        namespace bio = boost::iostreams;

        // prepare streams for compression and output
        std::stringstream compressed;
        std::stringstream origin(data);

        // wrap origin into filtering streambuf
        bio::filtering_streambuf <bio::input> out;

        // choose compression type
        if (t == z_gzip_bc) {
            out.push(
                    // gzip compressor with the best compression (level 9)
                    bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));
        }
            // zlib compressor with the best compression (level 9)
        else if (t == z_zlib_bc) {
            out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_compression)));
        }
            // zlib compressor with the best speed (level 1)
        else if (t == z_zlib_fc) {
            out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_speed)));
        }
            // bzip2 compressor with the default compression level (level 6)
        else if (t == z_bzip2_ds) {
            out.push(bio::bzip2_compressor(bio::bzip2_params(bio::bzip2::default_block_size)));
        }

        // output goes to compressed stream
        out.push(origin);

        // copy origin to compressed stream
        bio::copy(out, compressed);

        // return compressed data as a string (not as a stream)
        return compressed.str();
    }
}

// the function to compress a string using a specific compression algorithm
int NCD::compress(std::string x, cmp_type t) {
    // the sink to store the compressed data in
    std::string sink;
    switch (t) {
        case z_snappy_ds:
            snappy::Compress(x.data(), x.size(), &sink);
            return sink.size();
        case z_gzip_bc:
            sink = compressors::compress(x, t);
            return sink.size();
        case z_zlib_bc:
            sink = compressors::compress(x, t);
            return sink.size();
        case z_zlib_fc:
            sink = compressors::compress(x, t);
            return sink.size();
        case z_bzip2_ds:
            sink = compressors::compress(x, t);
            return sink.size();
        default:
            return -1;
    }
};

// the helper function to concatenate two strings x and y
std::string NCD::concat_xy(std::string x, std::string y) {
    return x + y;
};

// the function to calculate the normalized compression distance between two strings x and y
float NCD::calculate_ncd(string x, string y, cmp_type t) {
    return (float) (NCD::compress(NCD::concat_xy(x, y), t)
                    - std::min(NCD::compress(x, t), NCD::compress(y, t)))
           / std::max(NCD::compress(x, t), NCD::compress(y, t));
};
