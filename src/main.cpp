#include "cmp_algorithms.hpp"
#include "ncd.hpp"

#include<iostream>

using namespace std;

int main() {
	
	const char x[] = "I am a sentence.";
	const char y[] = "I am also a sentence.";
	
	NCD ncd = NCD();
	cout << ncd.calculate_ncd(x, y, zlib) << endl;
	
	return 0;
}