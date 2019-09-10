#include "ncd.hpp"

#include <iostream>
#include <cstdlib>
#include <cassert>


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

return 0;
}
