class MLFQScheduler {
    public :
        MLFQScheduler ( const int q1 , const int q2 );
        ~ MLFQScheduler ();
        
        void addProcess ( const int pid , const int burstTime );
        void tick ( const int timeUnits );
        void run ();
        void priorityBoost ();
        void printScheduler () const ;
};