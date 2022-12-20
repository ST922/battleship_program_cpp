//<multipleArrays.cpp> -- Using a two-dimensional array, you will create the game battleship using a text file that contains 
// the board. The user will enter coordinates to try and find ships and sink them.
// CSIS 111-D02

// Include statements 
#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

// Global declarations: Constants and type definitions only -- no variables
ifstream inFile; // Input file

// Function prototypes
void fire(int x, int y, char gameArr[25][25]); // Checks to update board
bool fleetSunk(bool gameOver, char gameArr[25][25]); // Checks if game has been won

int main()
{
    // In cout statement below SUBSTITUTE  your name and lab number
    cout << "Samuel Teigland -- 7" << endl << endl;

    // Variable declarations
    int y, x; // x and y coordinates
    bool gameOver = false; // Game over boolean
    char gameArr[25][25]; // Array that will contain the inFile

    inFile.open("gameBoard.txt"); // Open file

    // Program logic
    // for loop that inputs the entire inFile into the array
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            inFile >> gameArr[i][j];
        }
    }

    // while loop that iterates while the game is still on
    while(gameOver == false)
    {
        // Take user input and update the array
        fire (x, y, gameArr);

        // Check to see if the game has been won
        gameOver = fleetSunk(gameOver, gameArr);
    }

    // Print out winning text after the game has been won and while loop is exited
    cout << endl;
    cout << "Game Over! All the enemy ships have been destroyed!" << endl;
    cout << "Here's how you did:" << endl;

    // for loop that prints out the results from the fully updated array
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            cout << gameArr[i][j];
        }
        cout << endl;
    }
    
    cout << endl;

    // Closing program statements
    inFile.close(); // Close the inFile
    return 0;
}

// Function definitions
// Take user input and update the array
void fire (int x, int y, char gameArr[25][25])
{   
    // Ask the user for y and x coordinates
    cout << "Please enter your Y coordinate (0-24): ";
    cin >> y;
    
    // Check for a valid y coordinate
    while (y < 0 || y > 24)
    {
        cout << "Invalid coordinate!" << endl;
        cout << "Please enter your Y coordinate (0-24): ";
        cin >> y;
    }

    cout << "Please enter your X coordinate (0-24): ";
    cin >> x;

    // Check for a valid x coordinate
    while (x < 0 || x > 24)
    {
        cout << "Invalid coordinate!" << endl;
        cout << "Please enter your X coordinate (0-24): ";
        cin >> x;
    }

    // Series of if statements to update the array
    if (gameArr[y][x] == '#') // If coordinates entered = #
    {
        cout << "HIT!" << endl; // Display HIT
        gameArr[y][x] = 'H'; // Replace with H
    }
    else if (gameArr[y][x] == 'H') // If coordinates entered = H
        cout << "HIT AGAIN!" << endl; // Display HIT AGAIN!
    else if (gameArr[y][x] == '~') // If coordinates entered = ~
    {
        cout << "MISS!" << endl; // Display MISS!
        gameArr[y][x] = 'M'; // Replace with M
    }
}

// Boolean function to check if the game is over
bool fleetSunk (bool gameOver, char gameArr[25][25])
{
    // for loops go through the entire board
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {   
            // If the gameboard only finds H and doesn't find #, game is over
            if (gameArr[i][j] == 'H' && gameArr[i][j] != '#')
            {
                gameOver = true;
            }
            // If the gameboard finds both H and/or #, game is not over
            else if (gameArr[i][j] == 'H' || gameArr[i][j] == '#')
            {
                gameOver = false;
            }
        }
    }
    // After loops iterate, return gameOver back to int main()
    return gameOver;
}