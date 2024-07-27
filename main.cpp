/* 
 * File:   main.cpp
 * Author: Lancelote Chang
 * Created on July 20, 2024, 09:30 PM
 * Purpose:  Project 1: The War card game final version
 */

// System libraries
#include <iostream> 
#include <fstream>  // For file
#include <ctime>    // For seeding the random number generator
#include <cstdlib>  // Provide "rand()" function to generate random card numbers
#include <cmath>    // Math library
#include <iomanip>  // For formatting outputs

using namespace std;

// Constants for card values
const int MIN_CARD = 2; // The smallest card is 2
const int MAX_CARD = 14; // The largest card is Ace

// Function to get card name from value
string cardNam(int cardValue) {
    switch (cardValue) { // Switch statement
        case 11: return "Jack"; // 11 = Jack
        case 12: return "Queen"; // 12 = Queen
        case 13: return "King"; // 13 = King
        case 14: return "Ace"; // 14 = Ace
        default: return to_string(cardValue);
    }
}

// Function to validate integer input
int valid(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. " << prompt;
    }
    return value;
}

//Execution begins here
int main(int argc, char** argv) {
    // Files input and output
    ofstream outFile("game_results.txt");

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Welcome message
    cout << "Welcome to the War card game!\n" << endl;
    outFile << "Welcome to the War card game!" << endl;

    // Get player names
    string p1Name, p2Name;
    cout << "Enter name for Player 1: \n ";
    cin >> p1Name;
    cout << "Enter name for Player 2: \n ";
    cin >> p2Name;

    // Get number of rounds
    int rounds = valid("Enter the number of rounds: ");
    
    //Game start message
    cout << "Start!" << endl;
    
    // Variables to hold the card values and scores for each player
    int p1Card, p2Card; // Integers
    int p1Score = 0, p2Score = 0; // Integers

    // To track whether Player 1 or Player 2 wins a round
    bool isP1Winner = false, isP2Winner = false;
    float p1Percent = 0.0f, p2Percent = 0.0f; // winning percentage of player 1 and player 2
    
    // Main game loop
    for (int round = 1; round <= rounds; ++round) { 
        cout << "\nRound " << round << endl;
        cout << "\nPlease draw a card" << endl;
        outFile << "\nRound " << round << endl;

        // Draw random cards for each player
        p1Card = rand() % (MAX_CARD - MIN_CARD + 1) + MIN_CARD;
        p2Card = rand() % (MAX_CARD - MIN_CARD + 1) + MIN_CARD;

        // Display the drawn cards
        cout << p1Name << " draws: " << cardNam(p1Card) << endl;
        outFile << p1Name << " draws: " << cardNam(p1Card) << endl;
        cout << p2Name << " draws: " << cardNam(p2Card) << endl;
        outFile << p2Name << " draws: " << cardNam(p2Card) << endl;

        // Determine the winner of the round using conditional operators
        isP1Winner = (p1Card > p2Card) ? true : false;
        isP2Winner = (p2Card > p1Card) ? true : false;

        // Update scores based on the round winner
        if (isP1Winner) { 
            cout << p1Name << " wins the round!" << endl;
            outFile << p1Name << " wins the round!" << endl;
            ++p1Score; 
        } else if (isP2Winner) { 
            cout << p2Name << " wins the round!" << endl;
            outFile << p2Name << " wins the round!" << endl;
            ++p2Score; // Increment operator
        } else {
            cout << "It's a tie!" << endl;
            outFile << "It's a tie!" << endl;
        }
    }
    
    // Game over message
    cout << "\nGame over!" << endl;
    
    // Calculate winning percentages
    p1Percent = (static_cast<float>(p1Score) / rounds) * 100; 
    p2Percent = (static_cast<float>(p2Score) / rounds) * 100;

    // Determine the overall winner
    cout << "\nFinal Scores:\n" << p1Name << ": " << p1Score << "\n" << p2Name << ": " << p2Score << endl;
    outFile << "\nFinal Scores:\n" << p1Name << ": " << p1Score << "\n" << p2Name << ": " << p2Score << endl;
    
    // Determine the winning percentage
    cout << setprecision(2); // Formatting outputs
    cout << p1Name << "'s win percentage: " << p1Percent << "%" << endl;
    outFile << p1Name << "'s win percentage: " << p1Percent << "%" << endl;
    cout << p2Name << "'s win percentage: " << p2Percent << "%" << endl;
    outFile << p2Name << "'s win percentage: " << p2Percent << "%" << endl;

    // Determine who wins the game
    if (p1Score > p2Score) {
        cout << p1Name << " wins the game!" << endl;
        outFile << p1Name << " wins the game!" << endl;
    } else if (p2Score > p1Score) {
        cout << p2Name << " wins the game!" << endl;
        outFile << p2Name << " wins the game!" << endl;
    } else {
        cout << "The game is a draw!" << endl;
        outFile << "The game is a draw!" << endl;
    }

    // Close the file
    outFile.close();

    // Demonstrating a do-while loop for an exit confirmation
    char exitChoice;
    do {
        cout << "Do you want to exit the game?"; << endl;
        cout << "Enter y to exit the game. Enter n to stay in the game."<< endl;
        cin >> exitChoice;
        if (exitChoice == 'y' || exitChoice == 'Y') {
            cout << "Exiting the game. Goodbye!" << endl;
        } else if (exitChoice == 'n' || exitChoice == 'N') {
            cout << "Returning to the game summary." << endl;
        } else {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        }
    } while (exitChoice != 'y' && exitChoice != 'Y' && exitChoice != 'n' && exitChoice != 'N'); 
    
    // Exit the program 
    return 0;
}