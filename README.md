# TestTask

## Description

This is a test project written in C++. The code implements the execution of test tasks Test 1 and Test 2. The project has two main functionalities:
1. Multithreaded file processing (Search for unique values of flight codes and record them in a separate file).
2. Comparison of two flight codes entered from the keyboard or standardised for the test .

## Requirements

- C++ Compiler (C++11 or later)
- UNIX-based operating system

## Compilation and Execution

To compile and run this project on a UNIX-based system, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone [URL to your repository]
   cd [your project directory]
   ```

2. **Compiling the Project**:
   The project uses `g++` for compilation. Ensure you have `g++` installed. You can check by running `g++ --version` in your terminal. If not installed, you can install it using your package manager. For example, on Ubuntu:
   ```bash
   sudo apt-get install g++
   ```

   To compile the project, run in the project directory:
   ```bash
   $ make
   ```
   
3. **Running the Program**:
   To run the compiled program, execute:
   ```bash
   ./TestTaskProgram
   ```

## Project Structure

Below is an overview of the key files of the project:

- `main.cpp`: The main entry point to the application.
- `FilterUniqFlightCode.cpp`: Implements the logic for processing files.
- `CompareFlightCode.cpp`: Contains logic for comparing flight codes.
- `GanearateFlightCodes.cpp`: Contains logic for generating flight codes.
- `FilterUniqFlightCode.h`: Header for file processing functionality.
- `CompareFlightCode.h`: Header for flight code comparison functionality.
- `GanearateFlightCodes.h`: Header for flight code generation functions.
- `1_in.txt`: Sample input file for processing.
- `2_in.txt`: Another example input file for processing.
- `1_out.txt`: The result of the programme for the first file 
- `2_out.txt`: The result of the programme for the second file.
- `README.md`: A file containing detailed information about the project.
- `Makefile`: Makefile for compiling the project.

## Program Menu and Options

Upon execution, the program presents a menu with the following options:

```
Menu:
1. Process Files
2. Compare Flight Codes
3. Exit
Enter your choice: 
```

- **Option 1**: This initiates multithreaded processing of specified input files.
At the first run, the program will detect the presence of files `1_in.txt` and `2_in.txt`. If the files are not found, a message will be displayed:
- `Error open file 1_in.txt`
- `Error open file 2_in.txt`

After that, the automatic generation of input files will be performed. Duplicate emulation is done by duplicating each line

- **Option 2**: This option allows users to compare flight codes. Users can input two flight codes manually, or choose a default set of codes for comparison enter "S".
- **Option 3**: Exits the program.

## Output

The program outputs the results directly to the terminal. For file processing, it indicates completion. For flight code comparison, it displays whether the entered or default codes are 'Equal' or 'Not Equal'."
