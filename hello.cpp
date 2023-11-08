#include <omp.h>
#include <iostream>

int main() 
{
    #pragma omp parallel
    {
        int thread_num = omp_get_thread_num();
        int n_threads = omp_get_num_threads();
        
        #pragma omp critical
        {
            std::cout << "Thread " << thread_num << ". Overall number of threads: " << n_threads
                      << ". Hello World!!!" << std::endl;
        }
    }
    return 0;
}