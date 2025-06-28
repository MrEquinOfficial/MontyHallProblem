// Monty Hall Problem by. MrEquin

// GET SOME ESSENTIAL LIBRARIES
#include <iostream>
#include <random>

// SETTING UP THE RANDOM ENGINE TO GENERATE SOME RANDOM NUMBERS
std::random_device RandomDevice; // entropy
std::mt19937 gen(RandomDevice()); // Mersenne Twister engine
std::uniform_int_distribution<> distrib(1,3); // set up the range (1-3)    

int main() {
    int win = 0, lose = 0;
    for ( int i = 1; i <= 100000; i++ ) {
        int winner = distrib(gen); // We set which door is winner
        int choose = 1; // User chooses 1 initially, always.
        int opened_door = -1; // Not opened(yet)
        if ( winner == 2 || winner == 1) { // If the winner door is 2nd or 1st one, Monty will open the 3rd door.
            opened_door = 3;
        }
        else { // If the winner door is 3rd one, Monty will open the 2nd door;
            opened_door = 2;
        }

        if ( opened_door == 2 ) {
            choose = 3;
        }
        else {
            choose = 2;
        }

        if( choose == winner ) {
            ++win;
        }
        else {
            ++lose;
        }
    }
    int winpercentage = win * 100 / (win + lose);
    int losepercentage = lose * 100 / (win + lose);
    std::cout<<"Win: "<<winpercentage<<'%';
    std::cout<<"\n";
    std::cout<<"Lose: "<<losepercentage<<'%';
}