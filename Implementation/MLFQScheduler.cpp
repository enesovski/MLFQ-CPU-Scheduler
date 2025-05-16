//Enes Ceran 
//ID: 22302324
//Section 1

#include "MLFQScheduler.h"
#include <iostream>

using namespace std;

MLFQScheduler::MLFQScheduler(const int q1, const int q2)
  : quantum1(q1), quantum2(q2),
    queue1(), queue2(), queue3(),
    currentProcess(nullptr),
    currentQueueLevel(0),
    clk(0),
    finished()
{}


MLFQScheduler::~MLFQScheduler() {
  delete currentProcess;
}

void MLFQScheduler::addProcess(const int pid , const int burstTime)
{
  if(burstTime <= 0)
  {
    return;
  }

  Process newProcess(pid, burstTime, clk);
  queue1.enqueue(newProcess);

  cout << "[INFO] Process P" << pid
    << " with burst time " << burstTime
    << " arrived at clock " << clk << ".\n";

}


void MLFQScheduler::tick(int timeUnits) {
  if (timeUnits <= 0) return;

  for(int i = 0; i < timeUnits; i++)
  {
    //select process
   if(currentProcess && currentProcess->isFinished())
    {
        currentProcess->setEnd(clk);
        finished.enqueue(*currentProcess);
        delete currentProcess;
        currentProcess = nullptr;
    }
    else
    {
      if(currentQueueLevel == 1 && currentProcess->getUsedQuantumTime() >= quantum1)
      {
        currentProcess->resetQuantum();
        queue2.enqueue(*currentProcess);
        delete currentProcess;
        currentProcess = nullptr;
      }
      if(currentQueueLevel == 2 && currentProcess->getUsedQuantumTime() >= quantum2)
      {
        currentProcess->resetQuantum();
        queue3.enqueue(*currentProcess); 
      
        delete currentProcess;
        currentProcess = nullptr;

      }
    }
    if(!currentProcess)
    {
      //select a process level
      if(!queue1.isEmpty())
      {
        currentProcess = new Process(queue1.peek());
        currentQueueLevel = 1;
        queue1.dequeue();
      }
      else if(!queue2.isEmpty())
      {
        currentProcess = new Process(queue2.peek());
        currentQueueLevel = 2;
        queue2.dequeue();
      }
      else if(!queue3.isEmpty())
      {
        currentProcess = new Process(queue3.peek());
        currentQueueLevel = 3;
        queue3.dequeue();
      }

    }else
    { 
      //if queue1 is not empty and current level is 2 or 3, preempty it without resetting quantum
      
      if((currentQueueLevel == 2 || currentQueueLevel == 3) && !queue1.isEmpty())
      {
        if(currentQueueLevel == 2)
        {
          queue2.enqueue(*currentProcess);
          delete currentProcess;
          currentProcess = nullptr;

        }

        if(currentQueueLevel == 3)
        {
          queue3.enqueue(*currentProcess);
          delete currentProcess;
          currentProcess = nullptr;
        }

        currentProcess = new Process(queue1.peek());
        currentQueueLevel = 1;
        queue1.dequeue();
      }
    }

    //run selected
    if(currentProcess)
    {
      currentProcess->useCpu();
    }
    clk++;

  }
}

void MLFQScheduler::run() {
  while (!queue1.isEmpty() || !queue2.isEmpty() || !queue3.isEmpty() || currentProcess)
  {
    tick(1);
  }

  if(clk > 0)
  {
    clk--;
  }

  Queue<Process> tmp(finished);
  int n = tmp.size();
  double totalWait = 0, totalTurn = 0;
  while (!tmp.isEmpty()) {
    Process p = tmp.peek();
    totalWait += p.waitingTime();
    totalTurn += p.turnaroundTime();
    tmp.dequeue();
  }
  double avgWait = n ? totalWait / n : 0.0;
  double avgTurn = n ? totalTurn / n : 0.0;

  cout << "--- Final Statistics ---\n"
    << "Average Waiting Time: "    << avgWait  << "\n"
    << "Average Turnaround Time: " << avgTurn  << "\n"
    << "Total Runtime: "           << clk       << "\n"
    << "[INFO] All processes have completed execution.\n";
}


void MLFQScheduler::priorityBoost() {

  int count = 0;

  while (!queue2.isEmpty())
  {
    Process p = queue2.peek();
    p.resetQuantum();
    queue2.dequeue();
    queue1.enqueue(p);
    count ++;
  }

  while (!queue3.isEmpty())
  {
    Process p = queue3.peek();
    p.resetQuantum();
    queue3.dequeue();
    queue1.enqueue(p);
    count ++;
  }

  cout
    << "[INFO] Priority boost performed at clock " << clk
    << ". " << count << " processes boosted to Q1.\n";

}

void MLFQScheduler::printScheduler() const {
  cout << "--- Clock: " << clk << " ---\n";

  cout << "Q1:";
  printQueue(queue1);
  cout << "\n";

  cout << "Q2:";
  printQueue(queue2);
  cout << "\n";

  cout << "Q3:";
  printQueue(queue3);
  cout << "\n";


  cout << "Running: ";
  if (currentProcess) {
    cout
      << "P" << currentProcess->getPID()
      << " (Remaining Time: "
      << currentProcess->getRemainingTime()
      << ")";
  }
  else {
    cout << "None";
  }
  cout << "\n";

}

void MLFQScheduler::printQueue(Queue<Process> q) const
{
  Queue<Process> temp(q);

  while (!temp.isEmpty())
  {
    Process p = temp.peek();
    temp.dequeue();
    cout << " P" << p.getPID();
  }
}

