#include "sparse.hpp"
#include <fstream>
#include <vector>
#include <array>

template<typename T>
void mm_read(char *filename, sparse_matrix<T> &OutMatrix){
    int i, j;
    double k;
    
    std::ifstream InputFile;
    InputFile.open(filename);
    //To scrap and read the first line to check if it's symmetric
    while (InputFile.peek() == '%') InputFile.ignore(100, '\n');  //ignore -> first parameter max # char to ignore, \n ignores until the end of the line

    InputFile >> i >> j >> k; //First 3 are the information (rows, columns, nonzeros)-(Still have to decide what to do with it)

    while(InputFile>> i >> j >> k){
        OutMatrix.modify_element(i, j, k);
    };

    InputFile.close();
}