//
// Created by hassan on 11/17/23.
//

#include "fast_ncd.h"

#include <catch2/catch.hpp>
#include <iostream>


NCD make_ncd_instance() {
    NCD ncd = NCD();
    return ncd;
}

void destroy_ncd_instance(NCD ncd_instance) {
    delete &ncd_instance;
}

void test_compress(NCD ncd_instance) {

    ncd_instance.compress("text", z_bzip2_ds);
    ncd_instance.compress("", z_snappy_ds);

}


int main() {

    NCD ncd_instance = make_ncd_instance();


    TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( ncd_instance.compress("text", z_bzip2_ds) == 1 );
    }

    return 0;
}
