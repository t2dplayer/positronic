#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <utility>
#include <bits/stdc++.h>

// Auxiliar
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Data Structures
using VectorStr = std::vector<std::string>;
//using SparseMatrix = std::unordered_map<std::pair<size_t, size_t>, std::string, hash_pair>;

// Lambdas
using Progress = std::function<bool(size_t)>;

#endif // HEADER_H
