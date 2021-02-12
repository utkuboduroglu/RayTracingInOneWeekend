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

#endif //RTIN1WEEKEND_VEX_H
