# cuhip

**cuhip** is a easy-to-use wrapper tool designed to simplify the process of converting CUDA source code to HIP code and compiling it with HIPCC. This tool is particularly useful for learners who want to explore CUDA programming on AMD platforms, without having to manually convert and compile their code every time (this was exactly the reason for creating this tool).

## Pre-requisites

- **AMD ROCm Software Stack**: Ensure you have ROCm installed on your system (and available on your PATH). You can find information on how to download and install it on the [AMD ROCm documentation](https://rocm.docs.amd.com/en/latest/).

- **CUDA Toolkit**: Ensure you have the CUDA Toolkit installed on your system (and on your PATH). You can download it from the [NVIDIA website](https://developer.nvidia.com/cuda-downloads). Don't worry, you don't need to have an NVIDIA GPU to install it, but you do need the toolkit for the `hipify-clang` tool to work.

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/Equiel-1703/cuhip.git
    cd cuhip
    ```

2. Compile the tool:

    ```bash
    make all
    ```

3. The `cuhip` executable will be created in the `bin` directory.

    ```bash
    cd bin
    ```

4. Make the `cuhip` executable available in your PATH. Optionally, you can add the above line to your `.bashrc` or `.bash_profile` to make it permanent.

    ```bash
    export PATH=$PATH:$(pwd) # Add this line to your .bashrc or .bash_profile to make it permanent
    ```

## Usage

1. Navigate to the directory where your CUDA source file is located.

    ```bash
    cd /path/to/your/cuda/source
    ```

2. Run the `cuhip` tool to convert and compile it:

    ```bash
    cuhip <source_file.cu>
    ```

3. The binary will be generated in the same directory as the source code and will have the same name, but with a `.out` extension. Enjoy your HIP-ified code!

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to improve **cuhip**.

## License

This project is licensed under the [MIT License](LICENSE).

---
<div align="center">
What are you waiting for? Go ahead and do some CUDA programming on your AMD GPU with <strong>cuhip</strong>!
</div>
