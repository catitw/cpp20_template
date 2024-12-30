## Getting Started

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/learning-cpp.git
   cd learning-cpp
   ```

2. Configure the project:

  ```bash
  meson setup build
  ```
  This will create a build directory with the necessary build files.

3. Build the project:

  ```bash
  meson compile -C build
  ```
  This will compile all the .cpp files in the src directory and generate corresponding executables.

4. Run the executables:

  Each .cpp file with a main function will generate an executable. You can run them individually:

  ```bash
  ./build/main1
  ./build/main2
  ./build/main3
  ```
