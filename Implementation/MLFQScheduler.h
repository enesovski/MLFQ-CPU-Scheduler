#ifndef MLFQSCHEDULER_H
#define MLFQSCHEDULER_H

#include "Queue.h"
#include "Process.h"

class MLFQScheduler {
    public :
        MLFQScheduler ( const int q1 , const int q2 );
        ~ MLFQScheduler ();
        
        void addProcess ( const int pid , const int burstTime );
        void tick ( const int timeUnits );
        void run ();
        void priorityBoost ();
        void printScheduler () const ;

    private:
        int quantum1, quantum2;
        Queue<Process> queue1, queue2, queue3;
        Process* currentProcess;
        int currentQueueLevel;      // 1,2 or 3 (queue numbers)
        int clk;
        Queue<Process> finished;

        void printQueue(const Queue<Process> q) const;
  
};

#endif 

