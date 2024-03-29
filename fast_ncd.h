#ifndef FASTNCD_LIBRARY_H
#define FASTNCD_LIBRARY_H


#include <string>
#include <iostream>

using namespace std;

// a flag for each different type of compressors
enum cmp_type
{
    z_snappy_ds, z_gzip_bc, z_zlib_bc, z_zlib_fc, z_bzip2_ds
};

class NCD
{
public:
    // given an arbitary sized byte array this method will compress it with compression algorithm t
    int compress(string x, cmp_type t);

    // given two byte array this method will make a new array the size of the sum of two arrays and fill it with data from x and y
    string concat_xy(string x, string y);

public:
    // this method will return the calculated normalized constant compression distance between x and y
    float calculate_ncd(string x, string y, cmp_type t);
};

#endif

