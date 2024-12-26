# Project Overview

This project contains three tasks related to process scheduling and management in C, each implemented in a separate directory under the `Task` folder.

## Project Structure
```
Assignment.zip
|-- Task1
| |-- banker.c
| |-- output_screenshots
| |-- explanation.pdf
|-- Task2
| |-- fcfs.c
| |-- output_screenshots
| |-- explanation.pdf
|-- Task3
| |-- fork.c
| |-- output_screenshots
| |-- explanation.pdf
|-- README.txt
```


---

## Task Details

### Task 1: Banker's Algorithm
- **File:** `banker.c`
- **Description:** Implements the Banker's Algorithm for deadlock avoidance. *(Currently incomplete.)*
- **Compilation and Execution:**
  - **Linux:**
    ```bash
    cd Task/Task1
    gcc banker.c -o banker
    ./banker
    ```
  - **Windows:**
    ```cmd
    cd Task\Task1
    gcc banker.c -o banker
    banker.exe
    ```

---

### Task 2: First-Come, First-Served (FCFS) Scheduling
- **File:** `fcfs.c`
- **Description:** Implements FCFS scheduling, including process scheduling, result display, and Gantt chart generation.
- **Compilation and Execution:**
  - **Linux:**
    ```bash
    cd Task/Task2
    gcc fcfs.c -o fcfs
    ./fcfs
    ```
  - **Windows:**
    ```cmd
    cd Task\Task2
    gcc fcfs.c -o fcfs
    fcfs.exe
    ```

---

### Task 3: Fork Example
- **File:** `fork.c`
- **Description:** Demonstrates the `fork` system call to create child processes and displays the process IDs of parent and child processes.
- **Compilation and Execution:**
  - **Linux:**
    ```bash
    cd Task/Task3
    gcc fork.c -o fork
    ./fork
    ```
  - **Windows:**
    ```cmd
    cd Task\Task3
    gcc fork.c -o fork
    fork.exe
    ```

---

## Notes
- Ensure that `gcc` is installed and added to the PATH for compilation.
- Refer to `output_screenshots/` and `explanation.pdf` in each task directory for additional context and outputs.
