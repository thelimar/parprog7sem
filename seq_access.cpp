#include <omp.h>
#include <iostream>

int main(int argc, char *argv[]) 
{
    int common_mem = 0;

    if (argc != 2) 
    {
        std::cout << "Enter total number of threads." << std::endl;
        return 1;
    }

    const int n_threads = std::atoi(argv[1]);

    #pragma omp parallel num_threads(n_threads)
    {
        int thread_num = omp_get_thread_num();

        #pragma omp critical
        {
            common_mem++;
            std::cout << "Thread " << thread_num << " : Common memory unit = " << common_mem << std::endl;
        }
    }

    return 0;
}