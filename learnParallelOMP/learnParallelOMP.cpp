#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // Header for output clarity
    cout << "==============================\n";
    cout << " OpenMP Demonstration Program\n";
    cout << "==============================\n\n";

    // Region 1: Basic Parallelization
    #pragma omp parallel
    {
        #pragma omp critical
        {
            cout << "[Basic Parallelization] Hello from thread "
                << omp_get_thread_num() << "!\n";
        }
    }
    cout << "\n---------------------------------\n";

    // Region 2: Setting Number of Threads
    omp_set_num_threads(4); // Set the number of threads to 4
    #pragma omp parallel
    {
        #pragma omp critical
        {
            cout << "[Set Number of Threads] Thread "
                << omp_get_thread_num() << " of " << omp_get_num_threads() << "\n";
        }
    }
    cout << "\n---------------------------------\n";

    // Region 3: Parallel For Loop
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }
    cout << "[Parallel For Loop] Sum of numbers from 1 to 10: " << sum << "\n";
    cout << "\n---------------------------------\n";

    // Region 4: Critical Sections
    int counter = 0;
    #pragma omp parallel
    {
        #pragma omp critical
        {
            ++counter;
            cout << "[Critical Section] Thread "
                << omp_get_thread_num() << " incremented counter to " << counter << "\n";
        }
    }
    cout << "[Critical Section] Final counter value: " << counter << "\n";
    cout << "\n---------------------------------\n";

    // Region 5: Shared and Private Variables
    int sharedVar = 10;
    #pragma omp parallel private(sharedVar)
    {
        sharedVar = omp_get_thread_num();
        cout << "[Shared vs Private] Thread "
            << omp_get_thread_num() << " has privateVar = " << sharedVar << "\n";
    }
    cout << "[Shared vs Private] Outside, sharedVar = " << sharedVar << "\n";
    cout << "\n---------------------------------\n";

    // Region 6: Sections for Task Division
    #pragma omp parallel sections
    {
        #pragma omp section
        cout << "[Sections] Section 1 executed by thread "
            << omp_get_thread_num() << "\n";

        #pragma omp section
        cout << "[Sections] Section 2 executed by thread "
            << omp_get_thread_num() << "\n";
    }
    cout << "\n---------------------------------\n";

    // Region 7: Barrier Synchronization
    #pragma omp parallel
    {
        cout << "[Barrier] Before barrier, thread "
            << omp_get_thread_num() << "\n";

        #pragma omp barrier

        cout << "[Barrier] After barrier, thread "
            << omp_get_thread_num() << "\n";
    }
    cout << "\n---------------------------------\n";

    // Region 8: Master Thread Section
    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            cout << "[Master Thread] Master thread executing this section\n";
        }
    }
    cout << "\n---------------------------------\n";

    // Region 9: Dynamic Scheduling
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 10; ++i) {
        cout << "[Dynamic Scheduling] Iteration " << i
            << " executed by thread " << omp_get_thread_num() << "\n";
    }

    cout << "\n==============================\n";
    cout << " End of OpenMP Demonstration\n";
    cout << "==============================\n";

    return 0;
}
