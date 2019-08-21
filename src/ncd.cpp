#include "cmp_algorithms.hpp"
#include "ncd.hpp"

#include <algorithm>


int NCD::compress(const char* x, cmp_type t) {
	return 42;
	};

const char* NCD::concat_xy(const char* x, const char* y){
	const char r[] = "lolz";
	return r;
	};

float NCD::calculate_ncd(const char* x, const char* y, cmp_type t) {
	return (float)(compress(concat_xy(x, y)) - std::min(compress(x, y)) / std::max(compress(x), compress(y)))
	};
