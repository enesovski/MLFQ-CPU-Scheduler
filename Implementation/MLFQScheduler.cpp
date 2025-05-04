// MLFQScheduler.cpp
#include "MLFQScheduler.h"
#include <iostream>

MLFQScheduler::MLFQScheduler(const int q1, const int q2)
  : q1(), q2(), q3(),
    currentProcess(nullptr),
    clk(0)
{}

MLFQScheduler::~MLFQScheduler() = default;

void MLFQScheduler::addProcess(const int pid , const int burstTime)
{
    
}

void MLFQScheduler::tick(int timeUnits) {

}

void MLFQScheduler::priorityBoost() {

}

void MLFQScheduler::run() {

}

void MLFQScheduler::printScheduler() const {
}
