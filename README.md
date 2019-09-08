# FastNCD

FastNCD is a C++ library for caculating the normalized compression distances between two strings.

### Currently supported real-world compression methods

| Compressor | Main compression algorithm | Compression level | compression flag |
|--------|--------|--------|--------|
|    [Gzip](https://en.wikipedia.org/wiki/Gzip)    |  [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  9 (best)     |  z_gzip_bc      |
|    [Zlib](https://en.wikipedia.org/wiki/Zlib) |  [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  9 (best)      |  z_zlib_bc      |
|    [Zlib](https://en.wikipedia.org/wiki/Zlib) | [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)      |  1 (fastest)      |  z_zlib_fc      |
|    [Snappy](https://en.wikipedia.org/wiki/Snappy_(compression))    |  [LZ77](https://en.wikipedia.org/wiki/LZ77_and_LZ78)      |  default      |  z_snappy      |
|    [Bzip2](https://en.wikipedia.org/wiki/Bzip2)    |  [Burrows–Wheeler transform](https://en.wikipedia.org/wiki/Burrows–Wheeler_transform)      |  default      |  z_bzip2_ds      |

### Dependencies

Dont't for get to install the following libraries (headers and library files):

	* Boost iostreams library (version 1.67 and above)
	* Google's Snappy compression library
	* Zlib development files
	* Bzip2 development files

Usually on a Debian based operating system like Mint or Ubuntu, and of course Debian herself you could install these files by executing these commands:

	sudo apt-get install libboost-iostreams-dev libsnappy-dev

Note that other dependencies like zlib, bzip2 and lzma should be installed automatically on Debian when you install libboost-iostreams-dev

### Important thing to remember
The code is developed and tested on using Boost 1.67 on Debian Buster using GCC 8.3 but I guess it should work on the other operting systems that are derivatives of Debian 10 codebase too without any modifications.