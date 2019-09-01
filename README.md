# FastNCD
FastNCD is a C++ library for caculating the normalized compression distances between arbitrary strings

### Currently supported real-world compressors:

	1. GZip
		- Best compression
	2. Snappy
	3. ZLib
		- Best compression (level 9 compression)
		- Fastest compression (level 1 compression)

### Dependencies

Dont't for get to install the following libraries (headers and library files):
	
	* Zlib compression library
	* Google Snappy

Usually on a Debian based operating system like Mint or Ubuntu, and of course Debian herself you could install these files by executing these commands:
	
	sudo apt-get install zlib1g-dev libsnappy-dev
	

