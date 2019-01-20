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

double pchisq(const double& stat, const unsigned int& k) {
  return (1 / ((std::pow(2, k / 2) * std::tgamma(k / 2)))) *
         std::pow(stat, k / 2 - 1) * std::exp(-stat / 2);
}

bool jb_test(const std::vector<double>& x) {
  const unsigned long n = x.size();
  double m1 = std::accumulate(x.begin(), x.end(), 0.0) / n;
  double m2 = 0;
  double m3 = 0;
  double m4 = 0;
  for (auto xi : x) {
    m2 += std::pow(xi - m1, 2);
    m3 += std::pow(xi - m1, 3);
    m4 += std::pow(xi - m1, 4);
  }
  m2 /= n;
  m3 /= n;
  m4 /= n;

  const double S = std::pow(m3 / std::pow(m2, 3 / 2), 2);
  const double K = m4 / std::pow(m2, 2);
  const double stat = n * (S / 6 + std::pow(K - 3, 2) / 24);
  const double p_val = 1 - pchisq(stat, 2);
  if (p_val > 0.05) {
    return true;
  } else {
    return false;
  }
}
