#ifndef FASTNCD_LIBRARY_H
#define FASTNCD_LIBRARY_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Enum representing different types of compressors.
 */
enum cmp_type {
    z_snappy_ds, // Snappy compressor with default settings
    z_gzip_bc,   // Gzip compressor with best compression
    z_zlib_bc,   // Zlib compressor with best compression
    z_zlib_fc,   // Zlib compressor with fastest compression
    z_bzip2_ds   // Bzip2 compressor with default settings
};

/**
 * Class representing a Normalized Compression Distance (NCD) calculator.
 */
class NCD {
public:
    /**
     * Compresses a given string using a specified compression algorithm.
     * @param x The string to be compressed.
     * @param t The type of compression to be used.
     * @return The size of the compressed string.
     */
    int compress(string x, cmp_type t);

    /**
     * Concatenates two given strings.
     * @param x The first string.
     * @param y The second string.
     * @return The concatenated string.
     */
    string concat_xy(string x, string y);

    /**
     * Calculates the normalized compression distance between two given strings.
     * @param x The first string.
     * @param y The second string.
     * @param t The type of compression to be used.
     * @return The calculated normalized compression distance.
     */
    float calculate_ncd(string x, string y, cmp_type t);
};

#endif //FASTNCD_LIBRARY_H
