#include "ncd.h"

#include <iostream>
#include <string>
#include <snappy.h>


using namespace std;

int main() {

	string x = "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";
	string y = "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now, deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives every thing its value. Heaven knows how to put a proper price upon its goods; and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

	NCD ncd = NCD();
	cout << ncd.calculate_ncd(x, y, z_snappy) << endl;
        cout << ncd.concat_xy(x, y) << endl;
        cout << ncd.compress(x, z_snappy) << endl;
        cout << ncd.compress(y, z_snappy) << endl;
        cout << ncd.compress(ncd.concat_xy(x, y), z_snappy) << endl;
	return 0;
}
