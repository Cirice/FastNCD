# FastNCD

FastNCD is a simple C++ library to compute
the [Normalized Compression Distance (NCD)](https://en.wikipedia.org/wiki/Normalized_compression_distance) between two
strings.

## Supported Compression Methods

FastNCD currently supports the following compression methods:

| Compressor                                                   | Main Algorithm                                                                       | Compression Level | Flag          |
|--------------------------------------------------------------|--------------------------------------------------------------------------------------|-------------------|---------------|
| [Gzip](https://en.wikipedia.org/wiki/Gzip)                   | [DEFLATE](https://en.wikipedia.org/wiki/DEFLATE)                                     | 9 (best)          | `z_gzip_bc`   |
| [Zlib](https://en.wikipedia.org/wiki/Zlib)                   | DEFLATE                                                                              | 9 (best)          | `z_zlib_bc`   |
| [Zlib](https://en.wikipedia.org/wiki/Zlib)                   | DEFLATE                                                                              | 1 (fastest)       | `z_zlib_fc`   |
| [Snappy](https://en.wikipedia.org/wiki/Snappy_(compression)) | [LZ77](https://en.wikipedia.org/wiki/LZ77_and_LZ78)                                  | Default           | `z_snappy_ds` |
| [Bzip2](https://en.wikipedia.org/wiki/Bzip2)                 | [Burrows–Wheeler Transform](https://en.wikipedia.org/wiki/Burrows–Wheeler_transform) | Default           | `z_bzip2_ds`  |

## How to Use It

Use the following command to create a shared library:

    ```shell
    make all
    ```

Then, you can use the library in your project by including the header file `fast_ncd.h` in your source code and linking
your code with the shared library (`libnewFastNCD` file). Also, don't forget to link your
code with `libsnappy` and `libboost iostreams` while building your project.

To run the tests, use the following command:

    ```shell
    make scripts/run_tests.sh
    ```

## Example Usage

Example code for calculating the NCD between two identical C++ strings by using different compressors:

```cpp
#include "fast_ncd.h"

#include <iostream>
#include <string>


using namespace std;

int main() {

    // Two identical long (over 500 characters long) strings from The American Crisis by Thomas Paine
    string x =
            "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives everything its value. Heaven knows how to put a proper price upon its goods, and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

    string y =
            "THESE are the times that try men's souls. The summer soldier and the sunshine patriot will, in this crisis, shrink from the service of their country; but he that stands by it now deserves the love and thanks of man and woman. Tyranny, like hell, is not easily conquered; yet we have this consolation with us, that the harder the conflict, the more glorious the triumph. What we obtain too cheap, we esteem too lightly: it is dearness only that gives everything its value. Heaven knows how to put a proper price upon its goods, and it would be strange indeed if so celestial an article as FREEDOM should not be highly rated";

    // Of course, we first need to create an instance for our NCD class ;)
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

## Dependencies

If you are using a Debian-based operating system, you can install the required dependencies by using the following
command:

    ```shell
       sudo apt-get install libboost-iostreams-dev libsnappy-dev zlib1g-dev libbz2-dev
    ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
