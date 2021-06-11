/*********************************************************************************
 * Power Method - Capita Selecta
 * Author: Diogo Simões
 * Compile:
 * g++ -Wall -std=c++17 -O3 -o main main.cpp power.hpp sparse.hpp  mmarket.hpp
 * 
 * Main: Main file where the tests of the several components are carried out.
 * 
 * To comment block: Ctrl + K + C
 * To uncomment block: Ctrl + K + U
*********************************************************************************/
#include "sparse.hpp"
#include "tools.hpp"
#include "power.hpp"
#include "mmarket.hpp"
#include <iostream>
#include <vector>


int main(){
    sparse_matrix<double> M(4,4);
    std::vector<double> X = {1, 2, 3, 4}; 
    std::vector<double> Y(4);

    //Testing the Sparse Matrix Class
    // M.modify_element(1,1,3.0);
    // M.modify_element(1,2,5.0);
    // M.modify_element(3,2,1.0);
    // std::cout << "Non zeros elements:" << std::endl;
    // std::cout << M(1,1) << std::endl;
    // std::cout << M(1,2) << std::endl;
    // std::cout << M(3,2) << std::endl;
    // std::cout << "Vector X:" << std::endl;
    // print(X);
    // std::cout << "Vector Y:" << std::endl;
    // M.multiply(X, Y);
    // print(Y);
    //M.rem_element(1,1);
    //std::cout << M(1,1) << std::endl;
    //std::cout << M.rows_number() << std::endl;
    //std::cout << M.columns_number() << std::endl;

    //Testing matrix market reader
    sparse_matrix<double> A(1,1);
    A = mm_read<double>("test.mtx");
    //std::cout << A(1,1) << std::endl;
    //std::cout << A(2,2) << std::endl;
    //std::cout << A(3,3) << std::endl;
    //std::cout << A(4,4) << std::endl;
    //std::cout << A(5,5) << std::endl;
    //std::cout << A(6,6) << std::endl;
    //std::cout << A(1,2) << std::endl;
    //std::cout << A(1,3) << std::endl;
    //std::cout << A(2,3) << std::endl;
    //std::cout << A(3,5) << std::endl;
    //std::cout << A(4,6) << std::endl;
    //std::cout << A(5,6) << std::endl;

    //Testing new Reader
    sparse_matrix<double> B(1,1);
    B = mm_read<double>("test_sym.mm");
    // std::cout << B(1,5) << std::endl;
    // std::cout << B(2,3) << std::endl;
    // std::cout << B(2,4) << std::endl;
    // std::cout << B(3,5) << std::endl;
    // std::cout << B(5,1) << std::endl;
    // std::cout << B(3,2) << std::endl;
    // std::cout << B(4,2) << std::endl;
    // std::cout << B(5,3) << std::endl;

    //Testing the Power Method for A
    std::cout << "TEST A:" << std::endl;
    std::vector<double> lambda(7);
    double eig = 0;
    //1 - A
    //2 - AtA
    //3 - AAt
    eig = power_method(A, lambda, 1);
    std::cout << "Biggest Eigenvalue: " << eig <<std::endl;
    std::cout << "Biggest Eigenvector: " << std::endl;
    print(lambda);

    //Testing the Power Method for B
    std::cout << "TEST B:" << std::endl;
    std::vector<double> lambda_b(5);
    double eig_b = 0;
    //1 - A
    //2 - AtA
    //3 - AAt
    eig_b = power_method(B, lambda_b, 1);
    std::cout << "Biggest Eigenvalue: " << eig_b <<std::endl;
    std::cout << "Biggest Eigenvector: " << std::endl;
    print(lambda_b);

    //General Tests

    //Test 1
    std::cout << "TEST 1:" << std::endl;
    sparse_matrix<double> crs(1,1);
    std::vector<double> lambda1(5);
    double eig1 = 0;
    //
    crs = mm_read<double>("m_05_05_crs.mm");
    eig1 = power_method(crs, lambda1, 2);
    std::cout << "Biggest Eigenvalue: " << eig1 <<std::endl;
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(lambda1); 

    //Test 2
    std::cout << "TEST 2:" << std::endl;
    sparse_matrix<double> t2(1,1);
    std::vector<double> lambda2(5);
    double eig2 = 0;
    //
    t2 = mm_read<double>("test2.mtx");
    eig2 = power_method(t2, lambda2, 1);
    std::cout << "Biggest Eigenvalue: " << eig2 <<std::endl;
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(lambda2); 

    //Test 3
    std::cout << "TEST 3:" << std::endl;
    sparse_matrix<double> t3(1,1);
    std::vector<double> lambda3(9);
    double eig3 = 0;
    //
    t3 = mm_read<double>("test3.mm");
    eig3 = power_method(t3, lambda3, 3);
    std::cout << "Biggest Eigenvalue: " << eig3 <<std::endl;
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(lambda3);

    //Test 4
    std::cout << "TEST 4:" << std::endl;
    sparse_matrix<double> t4(1,1);
    std::vector<double> lambda4(27);
    double eig4 = 0;
    //
    t4 = mm_read<double>("ex5.mtx");
    eig4 = power_method(t4, lambda4, 1);
    std::cout << "Biggest Eigenvalue: " << eig4 <<std::endl;
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(lambda4);     

    return 0;
}