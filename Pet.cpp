#include "Pet.h"
// #include <Arduino.h>

// constructor initializes the pet object with default values
Pet::Pet() : hunger(100), happiness(100), sleepiness(100), 
            lastUpdate(0), lastAction(0), lastProgress(0) {

            }

//           
void Pet::begin() {
}
//
void Pet::update() {
}

// play with the pet and the pet's happiness increases by -
void Pet::play() {
}
// feed the pet and the pet's hunger decreases by -
void Pet::eat() {
}
// give the pet water and the pet's thirst decreases by -
void Pet::drink() {
}
// put the pet to bed and the pet's sleepiness decreases by -
void Pet::sleep() {
}

void Pet::displayStatus() {

}