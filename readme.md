# constantPPKNN

Source code for the research paper: **"Constant-Round Privacy-Preserving KNN Classification Based on Function Secret Sharing"**.

---

## Prerequisites & Installation

### 1. Environment & Dependencies
The project is tested on **Ubuntu 18.04 LTS** and requires the following environment:
* **Compiler**: GCC 13.1.0 (Required for OpenMP 4.5+).
* **Build System**: CMake 3.28.3.
* **Libraries**: 
    * **libfss**: Core FSS implementation (based on [frankw2/libfss](https://github.com/frankw2/libfss)).
    * **GNU GMP (v6.1.2)**: For high-precision arithmetic.
    * **OpenMP**: Integrated with GCC 13.1.0 for multi-threading.

### 2. Setup & Compilation
Run the following commands to install dependencies, build the project, and run the benchmark:

```bash
# [Step 1] Install system dependencies
sudo apt-get update
sudo apt-get install -y build-essential cmake libgmp-dev libgmpxx4ldbl libssl-dev

# [Step 2] Build the project (Release mode enabled for performance)
git clone https://github.com/fishlb/constantPP-KNN.git
cd constantPP-KNN
mkdir evalResult build
cd build
cmake ..
make

# [Step 3] Run the benchmark
./main
