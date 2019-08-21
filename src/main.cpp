#include "cmp_algorithms.h"
#include "ncd.h"

#include<iostream>

using namespace std;

int main() {

	const char *x = "I am a sentence.";
	const char *y = "I am also a sentence.";

	NCD ncd = NCD();
	cout << ncd.calculate_ncd(x, y, zlib) << endl;

	return 0;
}
