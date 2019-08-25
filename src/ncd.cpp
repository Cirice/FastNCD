#include "ncd.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <snappy.h>


using namespace std;

int NCD::compress(string x, cmp_type t) {
        string sink;
	switch(t) {
		case z_snappy:
			return snappy::Compress(x.data(), x.size(), &sink);	
		default:
			return -1;
};

	};

string NCD::concat_xy(string x, string y){
        //NCD::xy = (const char*)malloc((strlen(x) + strlen(y) - 1)*sizeof(char));
	//strcpy((char *)xy, x);
        //strcat((char *)xy, y);
        //std::cout << NCD::xy << std::endl;
        return "NCD::xy";
	};

float NCD::calculate_ncd(string x, string y, cmp_type t) {
  return (float)(NCD::compress(NCD::concat_xy(x, y), t) - std::min(NCD::compress(x, t), NCD::compress(y, t))) /
		 std::max(NCD::compress(x, t), NCD::compress(y, t));
	};


