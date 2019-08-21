#ifndef NCD_H_
#define NCD_H_

#include "cmp_algorithms.h"


class NCD {

private:
	// given an arbitary sized byte array this method will compress it with compression algorithm t
	int compress(const char* x, cmp_type t);

        // given two byte array this method will make a new array the size of the sum of two arrays and fill it with data from x and y
	const char* concat_xy(const char* x, const char* y);

public:
	// this method will return the calculated normalized constant compression distance between x and y
	float calculate_ncd(const char* x, const char* y, cmp_type t);
};

#endif
