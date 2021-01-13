#ifndef POSITRONIC_H
#define POSITRONIC_H
#include <memory>
#include "parse-options.h"

class DataFrame;
using DataFramePtr = std::shared_ptr<DataFrame>;

/**
 * @brief The Positronic class
 */
class Positronic {
    Positronic() = delete;
    ~Positronic() = delete;
    Positronic(Positronic&) = delete;
public:
    static DataFramePtr read_csv(const std::string& filename,
                                 const ParseOptions& opt = ParseOptions::defaults());
};

#endif // POSITRONIC_H
