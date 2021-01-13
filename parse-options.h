#ifndef PARSEOPTIONS_H
#define PARSEOPTIONS_H
#include <uchar.h>

/**
 * @brief The ParseOptions struct
 */
struct ParseOptions {
    char delimiter = ',';
    char quote = '"';
    char end_line = '\n';
    size_t skip_lines = 0;
    static ParseOptions defaults() {
        return ParseOptions();
    }
};

#endif // PARSEOPTIONS_H
