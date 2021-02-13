#ifndef RTIN1WEEKEND_VEX_H
#define RTIN1WEEKEND_VEX_H

// include numeric, array for linear algebra
#include <array>
#include <numeric>

#include <cinttypes>

// easy adjusting float precision
typedef double FTYPE;

template <std::uint64_t dim>
using Vec = std::array<FTYPE, dim>;

/* scalar product */
// Is for_each used correctly here?
template <std::uint64_t dim>
Vec<dim> operator*(Vec<dim>& left, FTYPE scalar) {
    Vec<dim> give;
    for (auto it = give.begin(); it < give.end(); it++) {
        *it = left.at(it - give.begin());
    }
    return give;
}

// simple commutativity overloading
template <std::uint64_t dim>
Vec<dim> operator*(FTYPE scalar, Vec<dim>& right) {
    return right * scalar;
}

// this will probably blow up
template <std::uint64_t dim>
Vec<dim>& operator*=(Vec<dim>& left, FTYPE scalar) {
    left = left * scalar;
    return left;
}

template <std::uint64_t dim>
FTYPE operator*(Vec<dim>& left, Vec<dim>& right) {
    FTYPE dot = 0;
    for (auto i = 0; i < dim; i++) {
        dot += left.at(i) * right.at(i);
    }
    return dot;
}

template <std::uint64_t dim>
Vec<dim> operator+(Vec<dim>& left, Vec<dim>& right) {
    Vec<dim> give;
    for (auto it = give.begin(); it < give.end(); it++) {
        *it = left.at(it - give.begin()) + right.at(it - give.begin());
    }

    return give;
}

template <std::uint64_t dim>
Vec<dim>& operator+=(Vec<dim>& left, Vec<dim>& right) {
    left = left + right;
    return left;
}

#endif //RTIN1WEEKEND_VEX_H
