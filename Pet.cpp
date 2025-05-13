// Kirsten Richards
// CPSC-25: Final Project
// Due Date: 03/13/2025

#include "Pet.h"
#include <iostream> // standard input/ output
#include <chrono> // CGPT

/* ChatGPT helped me set up the Clock and TimePoint functions to track the time for my
   time, action, and progression algorithms. */
using Clock = std::chrono::steady_clock; // CGPT
using TimePoint = std::chrono::time_point<Clock>; // CGPT

// constructor initializes the pet object with default values
Pet::Pet() : hunger(0), thirst(0), happiness(100), sleepiness(0), level(1) {
                auto now = Clock::now(); // CGPT
                lastUpdate = now;
                lastAction = now;
                lastProgress = now;
            }

// update the pet's state
void Pet::update() {
    auto now = Clock::now(); // CGPT
    std::chrono::duration<double> elapsed = now - lastUpdate; // CGPT
    if (elapsed.count() >= 1.0) { // update every second
        timeAlg(); // call the time algorithm
        lastUpdate = now; // update the last update time
    }
}

// sets the pet's name
void Pet::setName(const std::string& name) {
    this->name = name;

}
// gets the pet's name
std::string Pet::getName() const {
    return name;
}

// adds an action to the action queue
void Pet::enqueueAction(const std::string& action) {
    actionQueue.push(action);
}

/* PLAY with the pet and the pet's happiness increases by 10, 
   the pet's hunger and thirst each increase by 20,
   and the pet's sleepiness increases by 5. (each maxing at 100)*/
void Pet::play() {
    happiness = std::min(happiness + 10, 100); 
    hunger = std::min(hunger + 20, 100); 
    thirst = std::min(thirst + 20, 100); 
    sleepiness = std::min(sleepiness + 5, 100); 
    enqueueAction( name + " has played!  (^_^) "); // add action to queue
}
/* FEED the pet and the pet's hunger decreases by 20,
   the pet's thirst increases by 10,
   and the pet's happiness increases by 5,
   and the pet's sleepiness increases by 10. (min at 0 & max at 100)*/
void Pet::eat() {
    hunger = std::max(hunger - 20, 0);
    thirst = std::min(thirst + 10, 100); 
    happiness = std::min(happiness + 5, 100);
    sleepiness = std::min(sleepiness + 10, 100);
    enqueueAction( name + " has eaten!  (•w•) "); // add action to queue
}
/* GIVE THE PET WATER and the pet's thirst decreases by 20, 
   and the pet's happiness increases by 5. (min at 0 & max at 100)*/
void Pet::drink() {
    thirst = std::max(thirst - 20, 0);
    happiness = std::min(happiness + 5, 100);
    enqueueAction( name + " had a drink!  (•ᴥ•) "); // add action to queue
}
/* PUT THE PET TO BED and the pet's sleepiness decreases by 100,
   the pet's happiness increases by 20,
   the pet's hunger increases by 20, 
   the pet's thirst increases by 20. (min at 0 & max at 100)*/
void Pet::sleep() {
    sleepiness = std::max(sleepiness - 100, 0); 
    happiness = std::min(happiness + 20, 100); 
    hunger = std::min(hunger + 20, 100); 
    thirst = std::min(thirst + 20, 100); 
    enqueueAction( name + " has gone to bed!  (-.-) zzZ "); // add action to queue
}

// ouputs the pet's status to the LCD or serial monitor
void Pet::displayStatus() {
    std::cout << name + "'s Status: " << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Hunger: " << hunger << std::endl;
    std::cout << "Thirst: " << thirst << std::endl;
    std::cout << "Happiness: " << happiness << std::endl;
    std::cout << "Sleepiness: " << sleepiness << std::endl;
} 

// tracks the time, affecting the pet's state
void Pet::timeAlg() {
    auto now = Clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate).count();

    // increase hunger, thirst, sleepiness, and decrease happiness every 5 seconds
    if (elapsed >= 5) {  
        hunger = std::min(hunger + 2, 100);
        thirst = std::min(thirst + 2, 100);
        sleepiness = std::min(sleepiness + 1, 100);
        happiness = std::max(happiness - 1, 0);
        lastUpdate = now;
    }
}

// processes the pet's actions
void Pet::actionAlg() {
    while (!actionQueue.empty()) {
        std::string action = actionQueue.front ();
        actionQueue.pop();
        // announces the action
        std::cout << "[action]:" << action << std::endl;
    }
}

// tracks the pet's progress through the game via a level system
void Pet::progressionAlg() {

    auto now = Clock::now(); // gets the current time
    std::chrono::duration<double> elapsed = now - lastProgress; 
    // checks if 30 seconds have passed since the last level-up
    if (elapsed.count() >= 30.0) { // 30 second cooldown required to level up (increasing difficulty)
        // sets more specific conditions for the pet to level up (increasing difficulty)
        // the pet's happiness must be above 90, and the hunger, thirst, and sleepiness must be below 15
        // max level is 100
        if (happiness > 90 && hunger < 15 && thirst < 15 && sleepiness < 15 && level < 100) {
            level++;
            std::cout << name + " has leveled up to level " << level << "!\n" << std::endl;
            lastProgress = now; // reset the cooldown timer
        }
    }
}
