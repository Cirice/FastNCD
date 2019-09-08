#include "ncd.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <snappy.h>

#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/zlib.hpp>


namespace compressors {

// https://stackoverflow.com/questions/27529570/simple-zlib-c-string-compression-and-decompression
std::string compress(std::string& data, cmp_type t)
	{
		namespace bio = boost::iostreams;

		std::stringstream compressed;
		std::stringstream origin(data);

		bio::filtering_streambuf<bio::input> out;
                if (t == z_gzip_bc) {out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));}
                else if (t == z_zlib_bc) {out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_compression)));}
                else if (t == z_zlib_fc) {out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_speed)));}

		out.push(origin);
		bio::copy(out, compressed);

		return compressed.str();
}
}


int NCD::compress(std::string x, cmp_type t) {
        std::string sink;
	switch(t) {
		case z_snappy:
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
		default:
			return -1;
}
};


std::string NCD::concat_xy(std::string x, std::string y){
        return x+y;
	};


float NCD::calculate_ncd(string x, string y, cmp_type t) {
  return (float)(NCD::compress(NCD::concat_xy(x, y), t) - std::min(NCD::compress(x, t), NCD::compress(y, t))) /
		 std::max(NCD::compress(x, t), NCD::compress(y, t));
	};
