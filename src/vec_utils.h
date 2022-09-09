#ifndef RTIN1WEEKEND_VEC_UTILS_H
#define RTIN1WEEKEND_VEC_UTILS_H

#include <armadillo>
#include <iostream>

inline std::ostream& operator<<(std::ostream& out, const arma::vec& v) {
  return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline arma::vec operator*(const arma::vec &u, const arma::vec &v) {
  return arma::vec({u[0] * v[0], u[1] * v[1], u[2] * v[2]});
}

using point = arma::vec;

#endif // RTIN1WEEKEND_VEC_UTILS_H
