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
        //Highest priority
        Queue<Process> q1;
        
        //Medium priority
        Queue<Process> q2;
        
        //Lowest priority
        Queue<Process> q3;                

        Process* currentProcess;    
        int clk;   

};

#endif 

