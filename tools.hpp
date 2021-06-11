/**************************************
tools.hpp : This file contains several 
            functions that do vector
            operations
***************************************/
#ifndef tools
#define tools
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <math.h>

/********************************
Function: prints a vector
*********************************/
template<typename T>
inline void print(std::vector<T> const &v){
    std::cout<<"[ ";
    for(unsigned int i=0; i<v.size(); ++i) {
        std::cout<<v[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
};


/*************************************
Function: Normalizes a vector
**************************************/
template<typename T>
inline std::vector<T> vec_normalize(std::vector<T> &V){
    int m = V.size();
    std::vector<double> V_norm(m, 0);
    double norm = 0.0;

    for(unsigned int i = 0; i < V.size(); i++){ 

        norm += V[i]*V[i];
    }

    norm = sqrt(norm);

    for(unsigned int i = 0; i < V.size(); i++){

        V_norm[i] = V[i]/norm;
    }
  
    return V_norm;
}

/********************************************
Function: Compares two vectors and outputs
          the biggest distance between them
*********************************************/
template<typename T>
inline double vec_difference(std::vector<T> &v1, std::vector<T> &v2){
    assert(v1.size() == v2.size());

    int m = v1.size();
    std::vector<double> v_dif(m, 0);
    double max_dif = 0.0;

    for(unsigned int i = 0; i < v1.size(); i++){
    
        v_dif[i] =  fabs(v1[i] - v2[i]);
    }
    
    max_dif = *max_element(v_dif.begin(), v_dif.end());

    return max_dif;
}

/********************************************
Function: Computes the inner product between
          two vectors
*********************************************/
template<typename T>
inline T vec_product(std::vector<T> &v1, std::vector<T> &v2){
    assert(v1.size() == v2.size());

    T vf = 0;

    for(unsigned int i = 0; i < v1.size(); i++){ 

        vf += v1[i]*v2[i];
    }
    return vf;
}


#endif