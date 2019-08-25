#include "ncd.h"

#include <iostream>
#include <string>
#include <snappy.h>


using namespace std;

int main() {

	string x = "I am a sentence.";
	string y = "I am also a sentence.";

	NCD ncd = NCD();
	cout << ncd.calculate_ncd(x, y, z_snappy) << endl;
        cout << (x.length()) << endl;
	return 0;
}
