#include <omp.h>
#include <iostream>

int main(int argc, char *argv[]) 
{

    if (argc != 2) 
    {
        std::cout << "Enter N" << std::endl;
        return 1;
    }

    int N = std::atoi(argv[1]);
    long double res = 0.0;
    int num_threads_to_print = 0;

    #pragma omp parallel
    {
        int n_threads = omp_get_num_threads(); 
        int thread_num = omp_get_thread_num();
        double thread_sum = 0.0;

        num_threads_to_print = n_threads;

        for (int i = thread_num + 1; i <= N; i += n_threads) 
        {
            thread_sum += 1.0 / i;
        }

        #pragma omp critical
        {
            res += thread_sum;
        }
    }

    std::cout << "Sum is " << res << std::endl;

    return 0;
}