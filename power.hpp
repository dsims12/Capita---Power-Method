#include "sparse.hpp"
#include "tools.hpp"

template<typename T>
T power_method(sparse_matrix<T> &M, std::vector<T> &lambda,  int n){
    int m = M.rows_number();
    //debug
    //std::cout << m << std::endl;   
    //std::vector<double> lambda(m,0);
    std::vector<double> b(m,0);
    std::vector<double> V(m, 1);

    T eig = 0;
    T w1 = 0;
    T w2 = 0;
    //debug
    //print(lambda);
    //print(V);
    
    switch (n)
    {
    case 1:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_vector(V);                  //Matrix * vector product  
        b = lambda;
        //debug
        //print(lambda);
        lambda = vec_normalize(lambda);                 //Normalizes lambda

        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-8){           //Stopping criterion        
           break;
        }  
        V = lambda;
        //debug
        std::cout << "Iter: " << n << std::endl;

        w1 = vec_product(b, V);                       //Rayleigh quotient to get the Biggest Eigenvalue
        w2 = vec_product(V, V); 
        eig = w1/w2;

        //debug
        //std::cout << "Biggest Eigenvalue:" << eig <<std::endl;
        }
        break;
    case 2:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_AtA(V);                    //Matrix * vector product 
        b = lambda;
        //debug
        //print(lambda);     
        lambda = vec_normalize(lambda);                //Normalizes lambda
        
        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){          //Stopping criterion
            break;
        }  
        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;

        w1 = vec_product(b, V);                       //Rayleigh quotient to get the Biggest Eigenvalue
        w2 = vec_product(V, V); 
        eig = w1/w2;

        //debug
        //std::cout << "Biggest Eigenvalue:" << eig <<std::endl;
        }
        break;
    case 3:
        for(unsigned int n = 0; n < 1000; n++){
        lambda = M.multiply_AAt(V);                    //Matrix * vector product
        b = lambda;
        //debug
        //print(lambda);
        lambda = vec_normalize(lambda);                //Normalizes lambda

        //debug
        //print(lambda);
        //print(V);
        if(vec_difference(V, lambda) < 1e-5){          //Stopping criterion
            break;
        }  
        V = lambda;
        //debug
        //std::cout << "Iter: " << n << std::endl;

        w1 = vec_product(b, V);                       //Rayleigh quotient to get the Biggest Eigenvalue
        w2 = vec_product(V, V); 
        eig = w1/w2;

        //debug
        //std::cout << "Biggest Eigenvalue:" << eig <<std::endl;
        }
        break;
    default:
        std::cout << "Invalid Number! Please insert a number from 1 to 3." << std::endl;
        break;
    }
    return eig;
}

