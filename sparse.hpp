/*************************************************
sparse.hpp : This file contains the sparse matrix
            class with all its members functions.
*************************************************/
#ifndef  sparse
#define  sparse
#include <vector>
#include <cassert>
#include <iostream>
#include <cmath>

template<typename T>
class sparse_matrix{
    public:
        typedef int size_type;
        typedef T value_type;
    public:
        sparse_matrix(size_type r, size_type c)
        : r_(r)
        , c_(c)
        {}//constructor

        sparse_matrix(const sparse_matrix& that)
        : r_(that.r_)
        , c_(that.c_)
        {
            (*this) = that;
        }//copy constructor


        value_type operator() (size_type i, size_type j) const{
            assert(i <= r_ && j <= c_);
            for(unsigned int k = 0; k<values_.size(); k++){
                if(i == rows_[k] && j == columns_[k]){
                    return values_[k];
                    break;
                }
            }
            return 0;
        }//assignment operator

        inline void modify_element(size_type i, size_type j, value_type v){
            assert(i <= r_ && j <= c_);
            for(unsigned int k = 0; k<values_.size(); k++){
                if(i == rows_[k] && j == columns_[k]){
                    values_[k] = v;
                    break;
                }
            }
            rows_.push_back(i);
            columns_.push_back(j);
            values_.push_back(v);
        }//Modifies an element, or adds it if it doesn't exist

        inline void rem_element(size_type i,size_type j){
            assert(i <= r_ && j <= c_);
            for(unsigned int k = 0; k<values_.size(); k++){
                if(i == rows_[k] && j == columns_[k]){
                    values_.erase(values_.begin() + k);
                    columns_.erase(columns_.begin() + k);
                    rows_.erase(rows_.begin() + k);
                }
            }
        }//Removes an element by erasing its position from the containers


        inline std::vector<value_type> multiply_vector(std::vector<value_type> const &X){
            std::vector<value_type> Y(c_);
            assert(X.size() == Y.size());
            for(unsigned int k = 0; k < values_.size(); k++){
                Y[rows_[k]-1] += values_[k] * X[columns_[k]-1];
            }
            return Y;
        }//Multiplies the matrix by a vector

        inline std::vector<value_type> multiply_AtA(std::vector<value_type> const &X){
            std::vector<value_type> Y(c_);
            std::vector<value_type> Aux(c_);
            assert(X.size() == Y.size());
            for(unsigned int k = 0; k < values_.size(); k++){
                Aux[rows_[k]-1] += values_[k] * X[columns_[k]-1];
            }

            for(unsigned int k = 0; k < values_.size(); k++){
                Y[columns_[k]-1] += values_[k] * Aux[rows_[k]-1];
            }

            return Y;
        }//Multiplies A^t*A by vector

        inline std::vector<value_type> multiply_AAt(std::vector<value_type> const &X){
            std::vector<value_type> Y(c_);
            std::vector<value_type> Aux(c_);
            assert(X.size() == Y.size());
            for(unsigned int k = 0; k < values_.size(); k++){
                Aux[columns_[k]-1] += values_[k] * X[rows_[k]-1];
            }

            for(unsigned int k = 0; k < values_.size(); k++){
                Y[rows_[k]-1] += values_[k] * Aux[columns_[k]-1];
            }

            return Y;
        }//Multiplies A*A^t by vector

        inline int rows_number(){
            return r_;
        }//Returns the number of nonzero rows
 
        inline int columns_number(){
            return c_;
        }//Returns the number of nonzero columns

    public:
        size_type r_;
        size_type c_;
    private:
        std::vector<value_type> rows_;
        std::vector<value_type> columns_;
        std::vector<value_type> values_;

};

#endif