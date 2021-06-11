/*************************************************
sparse.hpp : This file contains the matrix market
            reader function.
*************************************************/
#include "sparse.hpp"
#include <fstream>
#include <vector>
#include <array>

template<typename T>
sparse_matrix<T> mm_read(char const *filename){
    int i, j;
    double k;
    
    std::ifstream InputFile;
    InputFile.open(filename);
    std::string line;

    std::getline(InputFile, line);
    //debug
    //std::cout << line << std::endl;

    if(line.find("symmetric") != std::string::npos){       
        while (InputFile.peek() == '%'){                // Peek checks the first character in the string
            InputFile.ignore(2024, '\n');               //Ignores the number of characters (2024) or until the end of the line
        };

        InputFile >> i >> j >> k;

        sparse_matrix<T> OutMatrix(i,j);

        while(InputFile>> i >> j >> k){
            if (i==j){
               OutMatrix.modify_element(i, j, k);       //Avoid rewriting the diagonal
            }else{
                OutMatrix.modify_element(i, j, k);
                OutMatrix.modify_element(j, i, k);
            };
        };
        return OutMatrix;
    }else {
        //debug
        //std::cout << "OI 1" << std::endl;
        //std::getline(InputFile, line);
        //std::cout << line << std::endl;
        while(InputFile.peek() == '%'){
            //debug
            //std::cout << "OI 2" << std::endl;
            InputFile.ignore(2024, '\n');
        };
        //debug
        //std::cout << "OI 3" << std::endl;
        InputFile >> i >> j >> k;
        //debug
        //std::cout << i << j << k << std::endl;
        sparse_matrix<T> OutMatrix(i,j);

        while(InputFile >> i >> j >> k){
            //debug
            //std::cout << "OI 4" << std::endl;
            OutMatrix.modify_element(i, j, k);
        }; 
        return OutMatrix;
    }
    
    InputFile.close();
}