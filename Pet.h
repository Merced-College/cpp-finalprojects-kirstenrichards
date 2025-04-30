#ifndef PET_H
#define PET_H

// #include "LiquidCrystal.h"  // Use quotes if the library is in the project directory
#include <queue>

// 1st data structure (Pet class)
// this class will store all of the pet's data
class Pet {
    // private members to store the pet's hunger, thirst, happiness, and sleepiness levels
    // (between 0 and 100)
    private:
        int hunger;
        int thirst;
        int happiness;
        int sleepiness;

        unsigned long lastAction;  // stores the last time an action was performed
        unsigned long lastProgress; // stores the last time the pet's state changed
        unsigned long lastUpdate;  // stores the last time the pet's state was updated

    public: 
        // constructor to initialize the pet object
        Pet(); 
        void begin();
        void update(); // updates the pet's state

        // public members to simulate interaction with the pet (actions)
        void play();
        void eat();
        void drink();
        void sleep();

        // displays the pet's status and tracks actions in the queue
        void displayStatus();
        void enqueueAction(const std::string& action); 
        void processActions(); 

        // algorithms to determine the pet's state
        void timeAlg();
        void actionAlg();
        void progressionAlg();

};