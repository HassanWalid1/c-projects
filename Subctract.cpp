/*Program:This is a strategy mathematical game for two players,
 With a stack of coins(or other tokens) between them,
 two players play it.Coins are removed from the pile by the participants in turn,
 always removing a non - zero square number of coins(1, 4, 9, 16, ...),
 Whoever takes out the final coin wins.*/

 //Author: Hassan Walid Hassan Moselhy

 //ID : 20230544

 //Version:1.0

 //Date:3 March.2024

#include <iostream>
#include <random> // Include the random header for generating random numbers
#include <cmath>  // Include the cmath header for mathematical functions
using namespace std;

// Function to play the game
void players(float num_coins)
{
    while (true)
    {
        cout << "The Total Coins Are: " << num_coins << "\n";
        float First_Palyer_Coins;
        cout << "First player please enter your number of coins: ";
        cin >> First_Palyer_Coins;
        while (First_Palyer_Coins <= 0 or First_Palyer_Coins > num_coins or sqrt(First_Palyer_Coins) - floor(sqrt(First_Palyer_Coins)) != 0)
        {
            cout << "Invalid number, please enter a perfect square number: ";
            cin >> First_Palyer_Coins;
        }
        num_coins = num_coins - First_Palyer_Coins;
        if (num_coins < 1)
        {
            cout << "First Player Won!\n";
            break;
        }
        else
        {
            cout << "The remaining coins are " << num_coins << "\n";
        }
        // Second player's turn
        float Second_Palyer_Coins;
        cout << "Second player please enter your number of coins: ";
        cin >> Second_Palyer_Coins;
        while (Second_Palyer_Coins <= 0 or Second_Palyer_Coins > num_coins or sqrt(Second_Palyer_Coins) - floor(sqrt(Second_Palyer_Coins)) != 0)
        {
            cout << "Invalid number, please enter a perfect square number: ";
            cin >> Second_Palyer_Coins;
        }
        num_coins = num_coins - Second_Palyer_Coins;
        if (num_coins < 1)
        {
            cout << "Second Player Won!\n";
            break;
        }
        else
        {
            cout << "The remaining coins are " << num_coins << "\n";
        }
    }
}

// Function to ask the player if they want to play again
bool play_again()
{
    cout << "Want To Play Again? \n" << "1) play again \n" << "2) Exit Game \n";
    float choice;
    cin >> choice;
    if (choice == 1)
    {
        return true;
    }
    else if (choice == 2)
    {
        cout << "Thanks For Playing Our Game";
        return false;
    }
    else
    {
        cout << "Please Enter 1 or 2: ";
        cin >> choice;
    }
    return false;
}

// Function to choose the game mode: random or manual
float rand_or_chose()
{
    float choose;
    cout << "Select The Game Mode: \n" << "1) Random Number\n" << "2) Choose The Number By Yourself\n";
    cin >> choose;
    if (choose == 1)
    {
        random_device rd;

        mt19937 gen(rd());

        uniform_int_distribution<> dis(10, 400);

        return dis(gen);
    }
    else if (choose == 2)
    {
        float num_coins;
        cout << "Please enter the number of coins \n";
        cin >> num_coins;
        while (num_coins < 1)
        {
            cout << "Wrong Number, Enter a Valid Number \n";
            cin >> num_coins;
        }
        return(num_coins);
    }
}

// Main function
int main()
{
    //Representing The Game
    cout << "Welcome To The Subtract Square Game\n" << "The Players Must Take a Perfect Square Like (1, 4, 9, 16, ...)";
    cout << "Last One Takes The Coins Wins\n" << "Good Luck\n";
    float num_coins = rand_or_chose(); // Get the initial number of coins using random or manual selection
    players(num_coins); // Play the game with the initial number of coins

    // Loop to play again
    while (true)
    {
        bool Play_ag = play_again(); // Ask if the player wants to play again
        if (Play_ag == true)
        {
            num_coins = rand_or_chose(); // Get the number of coins for the new game
            players(num_coins); // Play the new game
        }
        else if (Play_ag == false)
            exit(0); // Exit the program if the player chooses not to play again
    }
    return 0;
}