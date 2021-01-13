#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <iostream>
#include "header.h"
#include "sparsematrix.h"

/**
 * @brief The DataFrame class
 */
class DataFrame {
public:
    VectorStr header;
    SparseMatrix<std::string> sparse_matrix;
    void head(size_t size = 5) {
        std::string out = "";
        size_t index = 0;
        for (const auto& str: header) {
            out += str;
            if (index++ < header.size() - 1) out += " ";
        }
        out += '\n';
        index = 0;
        for (const auto& [row, cols]: sparse_matrix.get_rows()) {
            size_t counter = 0;
            out += std::to_string(index) + " ";
            for (const auto& p: cols) {
                out += *sparse_matrix.get(p);
                if (counter < cols.size() - 1) out += " ";
                ++counter;
            }
            out += '\n';
            ++index;
            if (index > size) break;
        }
        std::cout << out << '\n';
    }
};

using DataFramePtr = std::shared_ptr<DataFrame>;

#endif // DATAFRAME_H
