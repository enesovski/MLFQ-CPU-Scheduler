# Multi‐Level Feedback Queue Scheduler Simulation

This repository contains a C++ implementation of the Multi-Level Feedback Queue (MLFQ) scheduling algorithm for Bilkent CS201 homework 4 assignment. Scheduler supports three priority queues, two configurable time-quantums, and periodic priority boosts.

## Repository Structure

- **`Process.h` / `Process.cpp`**  
  Defines the `Process` class (PID, burst time, start/end times, quantum tracking).

- **`Queue.h` / `Queue.cpp`**  
  A simple templated circular‐array queue used for each priority level.

- **`MLFQScheduler.h` / `MLFQScheduler.cpp`**  
  Implements the MLFQ logic:  
  - Three queues (Q1, Q2, Q3)  
  - Configurable `quantum1` and `quantum2`  
  - Preemption rules and priority boosts  
  - Per-tick simulation and final statistics output

- **`Program.cpp`**  
  A driver that  
  1. Creates an `MLFQScheduler` (e.g. `quantum1=2, quantum2=4`)  
  2. Adds a preset list of processes at specified arrival times  
  3. Runs the scheduler and prints the detailed trace and summary

## Requirements

- A C++ compiler with C++11 support (e.g. `g++`, `clang++`).
- No external libraries are needed.

## Building

From the project root:

```bash
g++ -std=c++11 \
    Program.cpp MLFQScheduler.cpp Process.cpp Queue.cpp \
    -o mlfq_scheduler
