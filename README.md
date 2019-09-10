# FastNCD

`FastNCD` is a very simple C++ library for calculating the [Normalized Compression Distance](https://en.wikipedia.org/wiki/Normalized_compression_distance)(NCD) between two strings.

### Currently supported real-world compression methods

| Compressor | Main compression algorithm | Compression level | compression flag |
|--------|--------|--------|--------|
|    [Gzip](https://en.wikipedia.org/wiki/Gzip)    |  [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  9 (best compression)     |  z_gzip_bc      |
|    [Zlib](https://en.wikipedia.org/wiki/Zlib) |  [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  9 (best compression)      |  z_zlib_bc      |
|    [Zlib](https://en.wikipedia.org/wiki/Zlib) | [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  1 (fastest compression)      |  z_zlib_fc      |
|    [Snappy](https://en.wikipedia.org/wiki/Snappy_(compression))    |  [LZ77](https://en.wikipedia.org/wiki/LZ77_and_LZ78)      |  default      |  z_snappy_ds      |
|    [Bzip2](https://en.wikipedia.org/wiki/Bzip2)    |  [Burrows–Wheeler transform](https://en.wikipedia.org/wiki/Burrows–Wheeler_transform)      |  default      |  z_bzip2_ds      |


### How to use?

You just need to include `ncd.hpp` in your source code and compile `ncd.cpp` with your code. Also don't forget to link your code with `libsnappy` and `libboost iostreams` while building your project =)

You could use the `Makefile` to build the example files in `src` folder:

	make all

If make is failing there is a big chance that something is wrong with the dependencies.

Example code for caluclating the NCD between two identical C++ strings by using different real world compressors:


```cpp

#include "ncd.hpp"

#include <iostream>
#include <string>


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
	cout << "snappy with default compression settings: " << ncd.calculate_ncd(x, y, z_snappy_ds)
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


```



### Dependencies

Don't for get to install the following libraries (headers and library files):

	- Boost iostreams library (version 1.67.0 or newer)
	- Google's Snappy compression library
	- zlib
	- libbz2

Usually on a `Debian` based operating system like `Mint` or `Ubuntu`, and of course `Debian` itself you could install these dependencies by executing the following command in your shell environment:

	sudo apt-get install libboost-iostreams-dev libsnappy-dev

### Important thing to remember
The code is developed and tested mainly using `Boost 1.67.0` on `Debian Buster` using `GCC 8.3` but I guess it should work on the other operating systems that are derivatives of Debian 10 code-base (or newer) too without any modifications.
