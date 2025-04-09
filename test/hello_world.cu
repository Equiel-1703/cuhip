#include <iostream>

__global__ void helloWorldKernel() {
    printf("Hello, World from GPU!\n");
}

int main() {
    // Launch the kernel with 1 block and 1 thread
    helloWorldKernel<<<1, 1>>>();

    // Wait for GPU to finish before accessing results
    cudaDeviceSynchronize();

    std::cout << "Hello, World from CPU!" << std::endl;

    return 0;
}