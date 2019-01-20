#include "metropolisHastings.h"

double runif(const double& a, const double& b) {
  return a + (b - a) * (rand() / ((double)RAND_MAX + 1));
}

double rnorm(const double& mean, const double& sd) {
  // Box-Muller transform
  double u = runif(0, 1);
  double v = runif(0, 1);
  return sd * (std::sqrt(-2 * std::log(u)) * std::cos(2 * M_PI * v)) + mean;
}

std::vector<double> generate(const std::function<double(double)>& target,
                             const unsigned int& count,
                             const unsigned int& burn_in_period) {
  std::srand(std::clock());

  std::vector<double> x(count + burn_in_period, 0);
  x[0] = 1;

  for (unsigned int i = 1; i < count + burn_in_period; i++) {
    double current_x = x[i - 1];
    double proposed_x = current_x + rnorm();
    double A = target(proposed_x) / target(current_x);
    if (runif() < A) {
      x[i] = proposed_x;
    } else {
      x[i] = current_x;
    }
  }

  x.erase(x.begin(), x.begin() + burn_in_period);

  return x;
};