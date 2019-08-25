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

std::string compress(std::string& data, cmp_type t)
	{
		namespace bio = boost::iostreams;

		std::stringstream compressed;
		std::stringstream origin(data);

		bio::filtering_streambuf<bio::input> out;
                if (t == z_gzip) {out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));}
                else if (t == z_zlib) {out.push(bio::zlib_compressor(bio::zlib_params(bio::zlib::best_compression)));}

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
                case z_gzip:
                        sink = compressors::compress(x, z_gzip);
                        return sink.size();
                case z_zlib:
                        sink = compressors::compress(x, z_zlib);
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


