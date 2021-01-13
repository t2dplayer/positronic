#include "string-utils.h"

VectorStr StringUtils::split(const std::string& str,
                             char delimiter) {
    VectorStr result;
    result.reserve(str.size());
    size_t s = 0, e = str.find(delimiter);
    while (e != std::string::npos) {
        result.push_back(str.substr(s, e - s));
        s = e + 1;
        e = str.find(delimiter, s);
    }
    result.push_back(str.substr(s, e - s));
    return result;
}
