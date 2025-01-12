
# **OpenMP-Demonstration-parallel-basics**

### **Overview**
This repository contains examples demonstrating the **basics of parallel programming** using **OpenMP**, a widely used API for multi-threaded programming in C++. The goal of this project is to provide developers with practical examples of how to leverage OpenMP to write efficient and scalable parallel programs.

Parallel programming allows tasks to run simultaneously, making better use of multi-core processors and enhancing application performance.

---

### **Features Demonstrated**
The program covers key OpenMP features, organized into regions for clarity:

1. **Basic Parallelization**  
   - Demonstrates how to create multiple threads to execute code concurrently.

2. **Setting Number of Threads**  
   - Shows how to control the number of threads used by OpenMP to manage workloads effectively.

3. **Parallel For Loop**  
   - Splits loop iterations across threads to accelerate computations.

4. **Critical Sections**  
   - Ensures safe access to shared resources in multi-threaded environments.

5. **Shared vs. Private Variables**  
   - Explains the difference between variables shared among threads and those private to each thread.

6. **Sections for Task Division**  
   - Divides tasks into sections, allowing different threads to execute distinct code blocks.

7. **Barrier Synchronization**  
   - Ensures all threads reach a synchronization point before proceeding.

8. **Master Thread Section**  
   - Restricts certain parts of the code to execution by the master thread only.

9. **Dynamic Scheduling**  
   - Demonstrates dynamic assignment of loop iterations to threads for better load balancing.

---

### **Why OpenMP?**
OpenMP simplifies parallel programming by providing easy-to-use directives and pragmas. It is widely used for:
- **Scalability**: Efficiently utilizes multi-core processors.
- **Portability**: Works across platforms with minimal code changes.
- **Simplicity**: Reduces the complexity of writing parallel code.

---

### **How to Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/mrXrobot26/OpenMP-Demonstration-parallel-basics.git
   cd OpenMP-Demonstration-parallel-basics
   ```

2. Compile the program with a compiler that supports OpenMP (e.g., `g++` or `clang`):
   ```bash
   g++ -fopenmp openmp_demo.cpp -o openmp_demo
   ```

3. Run the program:
   ```bash
   ./openmp_demo
   ```

---

### **Example Output**
```plaintext
==============================
 OpenMP Demonstration Program
==============================

[Basic Parallelization] Hello from thread 0!
[Basic Parallelization] Hello from thread 1!
...

---------------------------------

[Parallel For Loop] Sum of numbers from 1 to 10: 55

---------------------------------

[Critical Section] Thread 0 incremented counter to 1
...
```

---

### **Contributing**
Contributions are welcome! If you have ideas to expand this demonstration or add more OpenMP features, feel free to submit a pull request.

---

### **License**
This project is licensed under the MIT License.

