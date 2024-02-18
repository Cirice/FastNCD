#include "fast_ncd.h"

#include <catch2/catch.hpp>
#include <iostream>


TEST_CASE("Testing compression flags", "[NCD.compress]")
{
    NCD ncd_instance = NCD();
    REQUIRE(ncd_instance.compress("text", cmp_type::z_bzip2_ds) == 1);
    REQUIRE(ncd_instance.compress("text", cmp_type::z_gzip_bc) == 1);
    REQUIRE(ncd_instance.compress("text", cmp_type::z_zlib_bc) == 1);
    REQUIRE(ncd_instance.compress("text", cmp_type::z_zlib_fc) == 1);
    REQUIRE(ncd_instance.compress("text", cmp_type::z_snappy_ds) == 1);
}
