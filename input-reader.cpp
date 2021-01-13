#include "input-reader.h"
#include "data-frame.h"
#include "string-utils.h"
#include <iostream>

DataFramePtr InputReader::read(std::istream& input,
                               const ParseOptions& options,
                               Progress progress) {
    std::string line = "";
    DataFramePtr result = std::make_shared<DataFrame>();
    size_t skiped_lines = 0, row = 0, col = 0;
    std::getline(input, line);
    for (auto const& str: StringUtils::split(line, ',')) {
        result->header.push_back(str);
    }
    while (input) {
        col = 0;
        if (progress != nullptr) {
            bool cancel = progress(input.tellg());
            if (cancel) break;
        }        
        std::getline(input, line);
        if (++skiped_lines <= options.skip_lines) {
            continue;
        }
        for (auto const& str: StringUtils::split(line, ',')) {
            result->sparse_matrix.set({row, col++}, std::make_shared<std::string>(str));
        }
        ++row;
    }
    return result;
}
