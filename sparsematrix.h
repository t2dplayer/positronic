#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using Pair = std::pair<size_t, size_t>;
using VectorPair = std::vector<Pair>;
using SetPair = std::set<Pair>;
using MapIndex = std::unordered_map<size_t, VectorPair>;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

template <typename T>
class SparseMatrix {
public:
    using Ptr = std::shared_ptr<T>;
    using MapElements = std::unordered_map<Pair, Ptr, pair_hash>;
private:
    MapIndex cols, rows;
    MapElements elements;
    void find_and_erase(MapIndex& m,
                        const Pair& p,
                        size_t index) {
        auto it = m.find(index);
        if (it != m.end()) {
            auto& [key, v] = *it;
            auto itp = std::find(v.begin(), v.end(), p);
            if (itp != v.end()) v.erase(itp);
        }
    }
public:
    SparseMatrix(){}
    void set(const Pair& p, Ptr t) {
        elements[p] = t;
        auto [row, col] = p;
        if (rows.find(row) == rows.end()) {
            rows[row] = VectorPair{};
        }
        if (cols.find(col) == cols.end()) {
            cols[col] = VectorPair{};
        }
        rows[row].push_back(p);
        cols[col].push_back(p);
    }
    Ptr get(const Pair& p) {
        if (elements.find(p) != elements.end()) return elements[p];
        return nullptr;
    }
    MapIndex get_cols() {
        return cols;
    }
    MapIndex get_rows() {
        return rows;
    }
    VectorPair get_cols(size_t c) {
        if (cols.find(c) != cols.end()) return cols[c];
        return {};
    }
    VectorPair get_rows(size_t r) {
        if (rows.find(r) != rows.end()) return rows[r];
        return {};
    }
    bool erase(const Pair& p) {
        auto it = elements.find(p);
        if (it != elements.end()) {
            elements.erase(it);
            find_and_erase(cols, p, p.second);
            find_and_erase(rows, p, p.first);
            return true;
        }
        return false;
    }
    void move(const Pair& from, const Pair& to) {
        Ptr element = get(from);
        if (element) {
            erase(from);
            set(to, element);
        }
    }
    Pair shape() const {
        return {rows.size(), cols.size()};
    }
};

#endif // SPARSEMATRIX_H
