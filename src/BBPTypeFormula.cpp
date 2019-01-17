/*
 * BPP Type formula calculation with C++
 *
 * Formula was taken from:
 * https://bbp.carma.newcastle.edu.au/
 *
 * Author: Murat Koptur
 * GitHub: mrtkp9993
 *
 */

#include "BBPTypeFormula.h"

long double P(const int &s, const int &b, const int &n, const std::vector<int> &A, const int &n_iter) {
    assert(n == A.size());

    long double result = 0.0;

    for (int k = 0; k <= n_iter; k++) {
        auto inv_bk = 1 / std::pow(b, k);
        auto inner_sum = 0.0;
        for (int j = 1; j <= n; j++) {
            inner_sum += A.at(j - 1) / std::pow(n * k + j, s);
        }
        result += inv_bk * inner_sum;
    }

    return result;
}