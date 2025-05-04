#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
        Process(int _pid, int _burstTime, int _arrivalTime);
        ~Process();

        void useCpu();            
        void resetQuantum();

        //GETTERS
        bool isFinished() const { return remainingTime == 0; }
        int getPID() const { return pid; }
        int getRemainingTime() const { return remainingTime; }
        int getUsedQuantumTime() const { return usedQuantum; }

        //SETTERS FOR START - END
        void setStart(int clock);   
        void setEnd(int clock);  

        int waitingTime() const;    
        int turnaroundTime() const;    



    private:
        int pid;
        int burstTime;

        int remainingTime;
        int usedQuantum;

        int arrivalTime;
        int start;
        int end;
};

#endif