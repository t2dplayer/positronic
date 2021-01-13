#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <memory>
#include "header.h"
#include "parse-options.h"
#include "data-frame.h"


/**
 * @brief The InputReader class
 */
class InputReader {
    InputReader() = delete;
    ~InputReader() = delete;
    InputReader(InputReader&) = delete;
public:
    DataFramePtr static read(std::istream& input,
                             const ParseOptions& options,
                             Progress progress = nullptr);
};

#endif // INPUTREADER_H
