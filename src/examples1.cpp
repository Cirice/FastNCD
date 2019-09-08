#include "ncd.hpp"

#include <iostream>
#include <string>
#include <snappy.h>

using namespace std;

int main() {

	// Two identical long (over 500 character long) strings from The American Crisis by Thomas Paine
	string x =
			"THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

	string y =
			"THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

	// Of course we first need to create an instance for our NCD class ;)
	NCD ncd = NCD();

	cout << "string x is: " << x << endl << endl;

	cout << "string y is: " << y << endl << endl;

	// Snappy with default compression settings used as Z
	cout << "snappy compression: " << ncd.calculate_ncd(x, y, z_snappy_ds)
			<< endl;

	// GZip with best compression (level 9 compression) used as Z
	cout << "gzip with the best compression: "
			<< ncd.calculate_ncd(x, y, z_gzip_bc) << endl;

	// ZLib with best compression (level 9 compression) used as Z
	cout << "zlib with the best compression: "
			<< ncd.calculate_ncd(x, y, z_zlib_bc) << endl;

	// ZLib with fastest compression (level 1 compression) used as Z
	cout << "zlib with fastest compression: "
			<< ncd.calculate_ncd(x, y, z_zlib_fc) << endl;

	// Bzip2 with default compression settings used as Z
	cout << "bzip2 with default compression settings: "
			<< ncd.calculate_ncd(x, y, z_bzip2_ds) << endl;

	return 0;
}
