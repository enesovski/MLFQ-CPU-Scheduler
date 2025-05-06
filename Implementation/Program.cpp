#include <iostream>
#include "MLFQScheduler.h"

using namespace std;

int main() {
    MLFQScheduler scheduler(4, 8);
    scheduler.printScheduler();
    cout << endl;

    scheduler.addProcess(1, 2);
    scheduler.addProcess(2, 18);
    cout << endl;

    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.addProcess(3, 5);
    cout << endl;

    scheduler.tick(3);
    scheduler.printScheduler();
    cout << endl;

    scheduler.addProcess(4, 20);
    scheduler.addProcess(5, 1);
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(3);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(4);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.addProcess(6, 3);
    cout << endl;

    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();
    cout << endl;

    scheduler.priorityBoost();
    cout << endl;

    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(4);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(8);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(8);
    scheduler.printScheduler();
    cout << endl;

    scheduler.tick(8);
    scheduler.printScheduler();
    cout << endl;

    scheduler.run();
    cout << endl;

    scheduler.tick(1);
    scheduler.printScheduler();

    return 0;
}
