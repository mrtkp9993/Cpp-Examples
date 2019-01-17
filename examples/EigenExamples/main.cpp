//
//  main.cpp
//  EigenExamples
//
//

#include <iostream>
#include "Eigen/Dense"

int main(int argc, const char* argv[]) {
  // Define two vectors
  Eigen::Vector3d u(1, 2, 3);
  Eigen::Vector3d v(4, 5, 6);

  // Print vectors
  std::cout << "u = " << std::endl << u << std::endl;
  std::cout << "v = " << std::endl << v << std::endl;

  // Dot product
  std::cout << "Dot product of u and v = " << std::endl
            << u.dot(v) << std::endl;

  // Cross product
  std::cout << "Cross product of u and v = " << std::endl
            << u.cross(v) << std::endl;

  // L2 Norm
  std::cout << "L2 Norm of u = " << std::endl << u.norm() << std::endl;

  // Define a matrix
  Eigen::MatrixXd A(3, 3);
  A << 1, 0, 2, 0, 2, 1, 3, 0, 1;

  // Print Matrix
  std::cout << "A = " << std::endl << A << std::endl;

  // Transpose
  std::cout << "Transpose of A = " << std::endl << A.transpose() << std::endl;

  // Inverse
  std::cout << "Inverse of A = " << std::endl << A.inverse() << std::endl;

  // Frobenius norm
  std::cout << "Frobenius Norm of A = " << std::endl << A.norm() << std::endl;

  // Determinant
  std::cout << "Determinant of A = " << std::endl
            << A.determinant() << std::endl;

  // Eigenvalues
  std::cout << "Eigenvalues of A = " << std::endl
            << A.eigenvalues() << std::endl;

  // Eigenvectors
  Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(A);
  std::cout << "Eigenvectors of A = " << std::endl
            << eigensolver.eigenvectors() << std::endl;

  // Trace
  std::cout << "Trace of A = " << std::endl << A.trace() << std::endl;

  // QR Decomposition
  Eigen::FullPivHouseholderQR<Eigen::MatrixXd> qr_decomp(A);
  Eigen::MatrixXd qr_Q = qr_decomp.matrixQ();
  Eigen::MatrixXd qr_R = qr_decomp.matrixQR();
  std::cout << "QR Decomposition of A " << std::endl;
  std::cout << "Q = " << std::endl << qr_Q << std::endl;
  std::cout << "R = " << std::endl << qr_R << std::endl;

  // LU Decomposition
  Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(A);
  Eigen::MatrixXd lu_P = lu_decomp.matrixLU();
  Eigen::MatrixXd lu_L = lu_decomp.permutationP();
  Eigen::MatrixXd lu_U = lu_decomp.permutationQ();
  std::cout << "LU Decomposition of A " << std::endl;
  std::cout << "P = " << std::endl << lu_P << std::endl;
  std::cout << "L = " << std::endl << lu_L << std::endl;
  std::cout << "U = " << std::endl << lu_U << std::endl;

  // Singular Value Decomposition
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(
      A, Eigen::ComputeFullU | Eigen::ComputeFullV);
  Eigen::MatrixXd svd_U = svd.matrixU();
  Eigen::MatrixXd svd_S = svd.singularValues().asDiagonal();
  Eigen::MatrixXd svd_V = svd.matrixV().transpose();
  std::cout << "SVD  of A " << std::endl;
  std::cout << "U = " << std::endl << svd_U << std::endl;
  std::cout << "S = " << std::endl << svd_S << std::endl;
  std::cout << "V = " << std::endl << svd_V << std::endl;

  return 0;
}
