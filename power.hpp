#include "sparse.hpp"
#include "tools.hpp"

template<typename T>
std::vector<T> power_method(sparse_matrix<T> &M, int n){
    int m = M.rows_number();
    //debug
    //std::cout << m << std::endl;   
    std::vector<double> lambda(m,0);
    std::vector<double> V(m, 1);
    //debug
    //print(lambda);
    //print(V);
    
    switch (n)
    {
    case 1:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_vector(V);                  //Matrix * vector product  
        lambda = vec_normalize(lambda);                 //Normalizes lambda

        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){           //Stopping criterion        
           return lambda;
        }  
        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;
        }
        break;
    case 2:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_AtA(V);                    //Matrix * vector product      
        lambda = vec_normalize(lambda);                //Normalizes lambda
        
        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){          //Stopping criterion
            return lambda;
        }  
        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;
        }
        break;
    case 3:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_AAt(V);                    //Matrix * vector product
        std::cout << "Iter:" << n << std::endl; 
        print(lambda);
        lambda = vec_normalize(lambda);                //Normalizes lambda

        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){          //Stopping criterion
            return lambda;
        }  
        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;
        }
        break;
    default:
        std::cout << "Invalid Number! Please insert a number from 1 to 3." << std::endl;
        break;
    }
    return lambda;
}

