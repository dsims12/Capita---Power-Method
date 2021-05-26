#include "sparse.hpp"
#include "tools.hpp"

template<typename T>
std::vector<T> power_method(sparse_matrix<T> &M){
    int m = M.rows_number();
    //debug
    //std::cout << m << std::endl;   
    std::vector<double> lambda(m,0);
    std::vector<double> V(m, 1);
    //debug
    //print(lambda);
    //print(V);
    for(unsigned int n = 0; n < 1000; n++){

        lambda = M.multiply(V);                  //Matrix * vector product
       
        lambda = vec_normalize(lambda);         //Normalizes lambda

        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){   //Stopping criterion
        
            return lambda;
        }  

        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;
    }
    return lambda;
}

