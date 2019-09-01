#include "ncd.h"

#include <iostream>
#include <string>
#include <snappy.h>
#include <zlib.h>
#include <brotli.h>

using namespace std;

int main() {

        // Two identical long (over 500 character long) string, from The American Crisis by Thomas Paine
	string x = "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";
	string y = "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

        // Of course we first need to create an instance for our NCD class ;)
	NCD ncd = NCD();

        // Snappy compression used as Z
	cout  <<  "snappy compression: " << ncd.calculate_ncd(x, y, z_snappy) << endl;
        cout << ncd.concat_xy(x, y) << endl;
        cout << ncd.compress(x, z_snappy) << endl;
        cout << ncd.compress(y, z_snappy) << endl;
        cout << ncd.compress(ncd.concat_xy(x, y), z_snappy) << endl << endl;

        // GZip with best compression used as Z
        cout << "gzip with the best compression: " << ncd.calculate_ncd(x, y, z_gzip_bc) << endl;
        cout << ncd.concat_xy(x, y) << endl;
        cout << ncd.compress(x, z_gzip_bc) << endl;
        cout << ncd.compress(y, z_gzip_bc) << endl;
        cout << ncd.compress(ncd.concat_xy(x, y), z_gzip_bc) << endl << endl;

        // ZLib with best compression used as Z
        cout << "zlib with the best compression: " << ncd.calculate_ncd(x, y, z_zlib_bc) << endl;
        cout << ncd.concat_xy(x, y) << endl;
        cout << ncd.compress(x, z_zlib_bc) << endl;
        cout << ncd.compress(y, z_zlib_bc) << endl;
        cout << ncd.compress(ncd.concat_xy(x, y), z_zlib_bc) << endl << endl;

        // ZLib with fastest compression used as Z
        cout << "zlib with fastest compression: " << ncd.calculate_ncd(x, y, z_zlib_fc) << endl;
        cout << ncd.concat_xy(x, y) << endl;
        cout << ncd.compress(x, z_zlib_fc) << endl;
        cout << ncd.compress(y, z_zlib_fc) << endl;
        cout << ncd.compress(ncd.concat_xy(x, y), z_zlib_fc) << endl << endl;

	return 0;
}
