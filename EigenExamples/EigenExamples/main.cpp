//
//  main.cpp
//  EigenExamples
//
//

#include <iostream>
#include "Eigen/Dense"

int main(int argc, const char * argv[]) {
    // Define two vectors
    Eigen::Vector3d u(1,2,3);
    Eigen::Vector3d v(4,5,6);
    
    // Print vectors
    std::cout << "u = " << std::endl << u << std::endl;
    std::cout << "v = " << std::endl << v << std::endl;
    
    // Dot product
    std::cout << "Dot product of u and v = " << std::endl << u.dot(v) << std::endl;
    
    // Cross product
    std::cout << "Cross product of u and v = " << std::endl << u.cross(v) << std::endl;
    
    // L2 Norm
    std::cout << "L2 Norm of u = " << std::endl << u.norm() << std::endl;
    
    // Define a matrix
    Eigen::MatrixXd A(3, 3);
    A << 1, 0, 2,
         0, 2, 1,
         3, 0, 1;
    
    // Print Matrix
    std::cout << "A = " << std::endl << A << std::endl;
    
    // Transpose
    std::cout << "Transpose of A = " << std::endl << A.transpose() << std::endl;
    
    // Inverse
    std::cout << "Inverse of A = " << std::endl << A.inverse() << std::endl;
    
    // Frobenius norm
    std::cout << "Frobenius Norm of A = " << std::endl << A.norm() << std::endl;
    
    // Determinant
    std::cout << "Determinant of A = " << std::endl << A.determinant() << std::endl;
    
    // Eigenvalues
    std::cout << "Eigenvalues of A = " << std::endl << A.eigenvalues() << std::endl;
    
    // Eigenvectors
    Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(A);
    std::cout << "Eigenvectors of A = " << std::endl << eigensolver.eigenvectors() << std::endl;
    
    // Trace
    std::cout << "Trace of A = " << std::endl << A.trace() << std::endl;
    
    return 0;
}
