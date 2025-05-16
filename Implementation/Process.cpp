#include "Process.h"

//Enes Ceran 
//ID: 22302324
//Section 1


Process::Process(int _pid, int _burst, int _arrivalTime)
{
    pid = _pid;
    burstTime = _burst;
    arrivalTime = _arrivalTime;
    remainingTime = burstTime;
    usedQuantum = 0;
    end = -1;
}

Process::~Process() = default;

Process::Process(const Process& other)
  : pid(other.pid),
    burstTime(other.burstTime),
    remainingTime(other.remainingTime),
    usedQuantum(other.usedQuantum),
    arrivalTime(other.arrivalTime),
    end(other.end)
{}


Process& Process::operator=(const Process& other) {
    if (this != &other) {
        pid = other.pid;
        burstTime = other.burstTime;
        remainingTime = other.remainingTime;
        usedQuantum = other.usedQuantum;
        arrivalTime = other.arrivalTime;
        end = other.end;
    }
    return *this;
}


void Process::useCpu()
{
    remainingTime --;
    usedQuantum ++;
}

void Process::resetQuantum()
{
    usedQuantum = 0;
}


void Process::setEnd(int clock)
{
    end = clock;
}

int Process::waitingTime() const
{
    return turnaroundTime() - burstTime;
}

int Process::turnaroundTime() const
{
    return end - arrivalTime;
}
