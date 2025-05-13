// Kirsten Richards
// CPSC-25: Final Project
// Due Date: 03/13/2025

#include <iostream>
#include "Pet.h"

int main() {
    // introduce the game
    std::cout << "welcome to the pet simulator!" << std::endl;
    // create a new pet object
    Pet myPet;

    // allow the user to name their pet
    std::string name;
    std::cout << "enter a name for your pet: ";
    std::getline(std::cin, name);
    std::cout << std::endl;
    // set the pet's name
    myPet.setName(name);
    std::cout << "your pet's name is " << myPet.getName() << ". great choice!" << std::endl;

    char choice;
    // main game loop, offers the user a menu of options to interact with the pet
    while (true) {
        std::cout << "choose from the following actions: \n";
        std::cout << "1. play with your pet\n";
        std::cout << "2. feed your pet\n";
        std::cout << "3. give your pet water\n";
        std::cout << "4. put your pet to sleep\n";
        std::cout << "5. check your pet's status\n";
        std::cout << "6. exit the game\n";

        // prompt the user to input their choice
        std::cout << "enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        // proccess the user's choice
        switch (choice) {
            case '1': myPet.play(); break; 
            case '2': myPet.eat(); break;
            case '3': myPet.drink(); break;
            case '4': myPet.sleep(); break;
            case '5': myPet.displayStatus(); break;
            case '6': std::cout << "thank you for playing! goodbye :) " << std::endl; return 0;
            default: std::cout << "invalid choice. please try again." << std::endl; break;
        }

        // processes and displays the pet's chosen action
        myPet.actionAlg();
        
        
        myPet.progressionAlg();

        // update after each action
        myPet.update();

    
    }
    return 0;
}