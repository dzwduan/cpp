#include <assert.h>
#include <math.h>
#include "uwnet.h"

// Run an activation function on each element in a matrix,
// modifies the matrix in place
// matrix m: Input to activation function
// ACTIVATION a: function to run
void activate_matrix(matrix m, ACTIVATION a)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        double sum = 0;
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            if(a == LOGISTIC){
                x = logistic(x);
            } else if (a == RELU){
                x = relu(x);
            } else if (a == LRELU){
                x = lrelu(x,0.001);
            } else if (a == SOFTMAX){
                m.data[i*m.cols + j]=exp(m.data[i*m.cols + j];);
            }
            sum += m.data[i*m.cols + j];
        }
        if (a == SOFTMAX) {
            // TODO: have to normalize by sum if we are using SOFTMAX
            return m.data[i*m.cols + j]/sum;
        }
    }
}

double logistic(double x){
    return 1./(1.+exp(x));
}

double relu(double x){
    return x>0?x:0;
}

double lrelu(double x,double lambd){
    return x>0?x:(lambd*x);
}


// Calculates the gradient of an activation function and multiplies it into
// the delta for a layer
// matrix m: an activated layer output
// ACTIVATION a: activation function for a layer
// matrix d: delta before activation gradient
void gradient_matrix(matrix m, ACTIVATION a, matrix d)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            // TODO: multiply the correct element of d by the gradient
            
        }
    }
}
