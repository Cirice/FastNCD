#include "fast_ncd.h"

#include <algorithm>
#include <snappy.h> // snappy compression library

#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp> // boost iostreams library
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp> // boost iostreams library gzip filter
#include <boost/iostreams/filter/zlib.hpp> // boost iostreams library zlib filter
#include <boost/iostreams/filter/bzip2.hpp> // boost iostreams library bzip2 filter
#include <boost/iostreams/filter/lzma.hpp> // boost iostreams library lzma filter

// The namespace for the NCD library
namespace compressors {
    std::string compress(std::string &data, cmp_type t) {
        namespace bio = boost::iostreams;
        std::stringstream compressed;
        std::stringstream origin(data);
        bio::filtering_streambuf <bio::input> out;

        if (t == z_gzip_bc) {
            out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));
        } else if (t == z_zlib_bc) {
            out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_compression)));
        } else if (t == z_zlib_fc) {
            out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_speed)));
        } else if (t == z_bzip2_ds) {
            out.push(bio::bzip2_compressor(bio::bzip2_params(bio::bzip2::default_block_size)));
        }

        out.push(origin);
        bio::copy(out, compressed);
        return compressed.str();
    }
}

int NCD::compress(std::string x, cmp_type t) {
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
}

std::string NCD::concat_xy(std::string x, std::string y) {
    return x + y;
}

float NCD::calculate_ncd(string x, string y, cmp_type t) {
    return (float) (compress(concat_xy(x, y), t)
                    - std::min(compress(x, t), compress(y, t)))
           / std::max(compress(x, t), compress(y, t));
}
