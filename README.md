# FastNCD

FastNCD is a C++ library for caculating the normalized compression distances between two strings

### Currently supported real-world compression methods

| Compressor | Main compression method | Compression level | compression flag |
|--------|--------|--------|--------|
|    GZip    |  Deflate      |  9      |  z_gzip_bc      |
|    Zlib    |  Deflate      |  9      |  z_zlib_bc      |
|    GZip    |  Deflate      |  1      |  z_zlib_fc      |
|    Snappy    |  Snappy      |  default      |  z_snappy      |

### Dependencies

Dont't for get to install the following libraries (headers and library files):

	* Boost iostreams library
	* Google's Snappy compression library

Usually on a Debian based operating system like Mint or Ubuntu, and of course Debian herself you could install these files by executing these commands:

	sudo apt-get install libboost-iostreams-dev libsnappy-dev

