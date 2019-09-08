#include "ncd.hpp"

#include <iostream>
#include <cstdlib>
#include <cassert>

NCD make_ncd_instance() {
	NCD ncd = NCD();
return ncd
}
;

void destroy_ncd_instance(NCD ncd_instance) {
delete ncd_instance;
}
;

void test_compress(NCD ncd_instance) {
NCD ncd = NCD();

ncd.compress("text", 0);
ncd.compress("", 0);

}
;

int main() {

return 0;
}
