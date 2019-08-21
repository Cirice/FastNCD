#include "cmp_algorithms.h"
#include "ncd.h"

#include <algorithm>


int NCD::compress(const char* x, cmp_type t) {
	return 42;
	};

const char* NCD::concat_xy(const char* x, const char* y){
	const char r[] = "lolz";
	return r;
	};

float NCD::calculate_ncd(const char* x, const char* y, cmp_type t) {
  return (float)(NCD::compress(NCD::concat_xy(x, y), t) - std::min(NCD::compress(x, t), NCD::compress(y, t)) /
		 std::max(NCD::compress(x, t), NCD::compress(y, t)));
	};
