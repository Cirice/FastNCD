#include "utils.h"
#include "ncd.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <snappy.h>
#include <zlib.h>


int NCD::compress(std::string x, cmp_type t) {
        std::string sink;
	switch(t) {
		case z_snappy:
			snappy::Compress(x.data(), x.size(), &sink);
                        return sink.size();
                case z_gzip_bc:
                        sink = zlib_wrapper::compress_string(x, Z_BEST_COMPRESSION);
                        return sink.size();
                case z_zlib_bc:
                        sink = zlib_wrapper::compress_string(x, Z_BEST_COMPRESSION); // Z_BEST_SPEED is equal to compression level 1
                        return sink.size();
                case z_zlib_fc:
                        sink = zlib_wrapper::compress_string(x, Z_BEST_SPEED); // Z_BEST_SPEED is equal to compression level 1
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


