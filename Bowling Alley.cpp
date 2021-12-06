//---------------------------------------------------------------------------------
//
// Title:          BowlingAlley
// Lab Course:     ITCS 2530 V0801 2021FA
// Author:         Ivan Baydov
// Date:           12/5/2021
// Description:    This Program will read the txt file and count each players name and each players points. After that it would collect the total from each indivdual person and print the 
//                 Avrage Score.
//---------------------------------------------------------------------------------

#include <iostream> // Inputs and Outputs stream.
#include <fstream> // File handling.
#include <iomanip> // Formatted inputs and Outputs.
#include <string> // For String data type.
#include <algorithm> // For Transfrom Method.

// Declare Const Int Variables
const int WIDTH = 60; // is used for 
const int NAME_WIDTH = 10;
const int SCORES_WIDTH = 4;
const int AVG_SCORE_WIDTH = 6;

const int NUM_SCORES = 5;
const int NUM_PLAYERS = 10;

using namespace std;
void GetAverageScore(const double Points[NUM_PLAYERS][NUM_SCORES], double AvgScore[NUM_PLAYERS]);
bool GetBowlingData(string filename, double Points[NUM_PLAYERS][NUM_SCORES], string Players[NUM_PLAYERS]);
void PrettyPrintResults(const string Players[NUM_PLAYERS], const double Points[NUM_PLAYERS][NUM_SCORES], const double AvgScore[NUM_PLAYERS]);
int main()
{
    double AvgScore[NUM_PLAYERS];
    double Points[NUM_PLAYERS][NUM_SCORES]; // array for the points in the array to count, also a one part of the double parelile array
    string Players[NUM_PLAYERS]; // array for the Players name in the array, also a one part of the double parelile array

    cout << fixed;
    
    cout << setfill('*') << setw(WIDTH) << "*" << endl
        << setw(5) << "*" << " Welcome To The Bowling Alley in Sterling Heights " << setw(5) << "*" << endl
        << setw(WIDTH) << "*" << endl << endl;

    GetBowlingData("BowlingScores.txt", Points, Players);
    GetAverageScore(Points, AvgScore);
    PrettyPrintResults(Players, Points, AvgScore);

    return 0;

}
// this function is checking if the file can be reached and inputs the players names and scores in the array list.
bool GetBowlingData(string filename, double Points[NUM_PLAYERS][NUM_SCORES], string Players[NUM_PLAYERS]) 
{
    // Create output file stream
    ifstream inputStream; // we use in to input the file into our code insted of outputing the file.
    // Open output file stream
    inputStream.open(filename); // inpustStream will open the filename called BowlingScores.txt.

    while (inputStream.good()) // this while loop will only loop to check if the file is good.
    {
       
        for (int i = 0; i < NUM_PLAYERS; i++) // this for loop will count the players from i which is 10 meaining it would loop 10 times adding each players name each time it loops into a new array box.
        {
            inputStream >> Players[i]; // inputs data into the Players array.
            
            for (int j = 0; j < NUM_SCORES; j++) // this loop will each player and there 4 points for each round.
            {
                inputStream >> Points[i][j]; // inputs data into the points array.
            }
        }
    }
    return 0;
}
// this function is used to get the points of each player then add it in a sum deviding the number of rounds by 4 and displaying the total in the AvgScore array.
void GetAverageScore(const double Points[NUM_PLAYERS][NUM_SCORES],double AvgScore[NUM_PLAYERS])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        double sum = 0;

        for (int j = 0; j < NUM_SCORES; j++)
        {
            sum = sum + Points[i][j];
        }
        AvgScore[i] = sum / NUM_SCORES;
    }

}
// This function displays the output of the program of every players name, plays points, Avg string text, and the avrage score.
void PrettyPrintResults(const string Players[NUM_PLAYERS], const double Points[NUM_PLAYERS][NUM_SCORES],const double AvgScore[NUM_PLAYERS])
{
    
    cout << setfill(' ') << "Scores" << endl
        << setfill('-') << setw(NAME_WIDTH) << "-" << endl
        << setfill(' ');
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        cout << left << setw(NAME_WIDTH) << Players[i] << ":";

        for (int j = 0; j < NUM_SCORES; j++)
        {
            cout << setprecision(0) << right << setw(SCORES_WIDTH) << Points[i][j];
            
        }
        cout << setprecision(1) << " | Avg:" << setw(AVG_SCORE_WIDTH) << AvgScore[i] << endl;
    }

}
// Scratch how it might look
//Scores;
//  JoJo  ; 1 1 1 1 | Avg: 
//  BBilly; 1 1 1 1
