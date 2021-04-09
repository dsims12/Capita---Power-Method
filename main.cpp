/*********************************************************************************
 * Power Method - Capita Selecta
 * Author: Diogo Simões
 * Compile:
 * g++ -Wall -std=c++17 -O3 -o main main.cpp power.hpp sparse.hpp  mmarket.hpp
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
    M.modify_element(1,1,3.0);
    M.modify_element(1,2,5.0);
    M.modify_element(3,2,1.0);

    std::cout << "Non zeros elements:" << std::endl;
    std::cout << M(1,1) << std::endl;
    std::cout << M(1,2) << std::endl;
    std::cout << M(3,2) << std::endl;

    std::cout << "Vector X:" << std::endl;
    print(X);

    std::cout << "Vector Y:" << std::endl;
    M.multiply(X, Y);
    print(Y);

    //M.rem_element(1,1);
    //std::cout << M(1,1) << std::endl;

    std::cout << M.rows_number() << std::endl;
    std::cout << M.columns_number() << std::endl;

    //Testing matrix market reader
    sparse_matrix<double> A(7,7);

    mm_read("test.mtx", A);
    std::cout << A(5,6) << std::endl;
    
    //Testing the Power Method
    std::vector<double> eig(7);
    
    eig = power_method(A);
    std::cout << "Biggest Eigenvector:" << std::endl;
    print(eig);


    return 0;
}