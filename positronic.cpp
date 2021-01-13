#include "positronic.h"
#include "input-reader.h"
#include <iostream>
#include <fstream>

DataFramePtr Positronic::read_csv(const std::string &filename,
                                  const ParseOptions& opt) {
    std::ifstream file(filename);
    DataFramePtr result = nullptr;
    if (file.is_open()) {
        file.seekg(0, std::ios_base::end);
        size_t total = file.tellg();
        file.seekg(0, std::ios_base::beg);
        Progress p = [&total](size_t current) -> bool {
            size_t progress = current*100/total;
            std::cout << "\r\033[F[" << progress << "%]\n" << std::flush;
            return false;
        };
        std::istream *stream = (reinterpret_cast<std::istream *>(&file));
        result = InputReader::read((*stream), opt, p);
        file.close();
    }
    return result;
}
