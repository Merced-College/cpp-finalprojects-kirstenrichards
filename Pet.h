// Kirsten Richards
// CPSC-25: Final Project
// Due Date: 03/13/2025

#ifndef PET_H
#define PET_H

#include <iostream>  // for standard terminal input/output
#include <queue>
#include <string>
#include <chrono>  // for time tracking CGPT

/* ChatGPT helped me set up the Clock and TimePoint functions to track the time for my
   time, action, and progression algorithms. */
using Clock = std::chrono::steady_clock; // CGPT
using TimePoint = std::chrono::time_point<Clock>; // CGPT

// 1st data structure (Pet class)
// this class will store all of the pet's data
class Pet {
    // private members to store the pet's hunger, thirst, happiness, sleepiness, and level
    // (between 0 and 100)
    private:

        // 2nd data structure (string)
        std::string name; // pet's name
        // 3rd data structure (queue)
        std::queue<std::string> actionQueue; // queue to store pet's actions
        // 4th data structure (integers)
        int hunger; // (0 = full, 100 = starving)
        int thirst; // (0 = hydrated, 100 = dehydrated)
        int happiness; // (0 = sad, 100 = happy)
        int sleepiness; // (0 = awake, 100 = asleep)
        int level; // (1 = beginner, 100 = expert)

        // 5th data structure (TimePoint)
        TimePoint lastAction;  // stores the last time an action was performed // CGPT
        TimePoint lastProgress; // stores the last time the pet's state changed // CGPT
        TimePoint lastUpdate;  // stores the last time the pet's state was updated //CGPT
    public: 
        // constructor to initialize the pet object
        Pet(); 
        void update(); // updates the pet's state

        // getter & setter methods for the pet's name
        std::string getName() const;
        void setName(const std::string& name);

        // public members to simulate interaction with the pet (actions)
        void play();
        void eat();
        void drink();
        void sleep();

        // displays the pet's status and tracks actions in the queue
        void displayStatus();

        // tracks actions by storing them in the action queue
        void enqueueAction(const std::string& action); 

        // algorithms to determine the pet's state
        void timeAlg();
        void actionAlg();
        void progressionAlg();

};

#endif // PET_H