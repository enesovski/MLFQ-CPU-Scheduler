#ifndef PROCESS_H
#define PROCESS_H

//Enes Ceran 
//ID: 22302324
//Section 1

class Process
{
    public:
        Process(int _pid, int _burstTime, int _arrivalTime);
        ~Process();

        Process(const Process& other);
        Process& operator=(const Process& other);    

        void useCpu();            
        void resetQuantum();

        //GETTERS
        bool isFinished() const { return remainingTime == 0; }
        int getPID() const { return pid; }
        int getRemainingTime() const { return remainingTime; }
        int getUsedQuantumTime() const { return usedQuantum; }

        void setEnd(int clock);  

        int waitingTime() const;    
        int turnaroundTime() const;    



    private:
        int pid;
        int burstTime;

        int remainingTime;
        int usedQuantum;

        int arrivalTime;
        int end;
};

#endif