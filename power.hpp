#include "sparse.hpp"
#include "tools.hpp"

template<typename T>
std::vector<T> power_method(sparse_matrix<T> &M){
    int m = M.rows_number();

    std::vector<double> lambda(m,0);
    std::vector<double> V(m, 1);

    for(int n = 0; n < 10000; n++){

        M.multiply(V, lambda);                  //Matrix * vector product

        lambda = vec_normalize(lambda);         //Normalizes lambda

        if(vec_difference(V, lambda) < 1e-2){   //Stopping criterion
        
            return lambda;
            break;
        }  

        V = lambda;

    }
    return lambda;
}
