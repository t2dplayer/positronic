#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include "header.h"

/**
 * @brief The StringUtils class
 */
class StringUtils {
    StringUtils() = delete;
    ~StringUtils() = delete;
    StringUtils(StringUtils&) = delete;
public:
    static VectorStr split(const std::string& str,
                           char delimiter = ' ');
};

#endif // STRINGUTILS_H
