#include "cmp_algorithms.h"
#include "ncd.h"

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

int NCD::compress(const char* x, cmp_type t) {
	return 42;
	};

const char* NCD::concat_xy(const char* x, const char* y){
        NCD::xy = (const char*)malloc((strlen(x) + strlen(y) - 1)*sizeof(char));
	strcpy((char *)xy, x);
        strcat((char *)xy, y);
        //std::cout << NCD::xy << std::endl;
        return NCD::xy;
	};

float NCD::calculate_ncd(const char* x, const char* y, cmp_type t) {
  return (float)(NCD::compress(NCD::concat_xy(x, y), t) - std::min(NCD::compress(x, t), NCD::compress(y, t))) /
		 std::max(NCD::compress(x, t), NCD::compress(y, t));
	};


