#include "sparse.hpp"
#include <fstream>
#include <vector>
#include <array>

template<typename T>
sparse_matrix<T> new_mm_read(char *filename){
    int i, j;
    double k;
    
    std::ifstream InputFile;
    InputFile.open(filename);
    std::string line;

    std::getline(InputFile, line);
    InputFile.ignore();                 //getline changes the input stream, ignore to be able to use >> operator later

    sparse_matrix<T> OutMatrix(1,1);   //No need to input a specific size, modify will add accordingly, although had to deactivate the assertions on the class
    
    if(line.find("symmetric") != std::string::npos){       //getline is working fine, problem is here!
        while (InputFile.peek() == '%'){
            InputFile.ignore(100, '\n');
        };
        
        InputFile >> i >> j >> k;

        while(InputFile>> i >> j >> k){
            OutMatrix.modify_element(i, j, k);
            OutMatrix.modify_element(j, i, k);
        };
    }
    else{
        while (InputFile.peek() == '%'){
            InputFile.ignore(100, '\n');
        };

        InputFile >> i >> j >> k;
        std::cout << "OI 3" << std::endl;
        while(InputFile >> i >> j >> k){
            std::cout << "OI 4" << std::endl;
            OutMatrix.modify_element(i, j, k);
        }; 
    }
    
    InputFile.close();

    return OutMatrix;
}