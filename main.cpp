#include <iostream>
#include "positronic.h"
#include "data-frame.h"

using std::cout;

std::ostream& operator<<(std::ostream& out, const Pair& p) {
    out << "("
        << p.first
        << ", "
        << p.second
        << ")";
    return out;
}


int main(int argc, char** argv) {
    DataFramePtr df = Positronic::read_csv("car_data.csv");
    if (!df) return 1;
    df->head();
    std::cout << df->sparse_matrix.shape() << '\n';
    return 0;
}
