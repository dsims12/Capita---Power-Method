/*********************************************************************************
 * Power Method - Capita Selecta
 * Author: Diogo Simões
 * Compile:
 * g++ -Wall -std=c++17 -O3 -o main main.cpp power.hpp sparse.hpp  mmarket.hpp newmarket.hpp
 * 
 * comment sections: Ctrl+K+C
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
    std::cout << A(3,5) << std::endl;

    //Testing new Reader
    sparse_matrix<double> B(5,5);
    B = mm_read<double>("test_sym.mm");

    std::cout << B(5,3) << std::endl;
    std::cout << B(3,5) << std::endl;

    //Testing the Power Method
    std::vector<double> eig(5);

    //1 - A
    //2 - AtA
    //3 - AAt
    eig = power_method(A, 2);
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(eig);

    return 0;
}