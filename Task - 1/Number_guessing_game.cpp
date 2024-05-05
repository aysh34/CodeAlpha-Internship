#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int player_guess = 0, random_no;
    int count = 1;
    srand(time(nullptr));           // Seed the random number generator with the current time
    random_no = 1 + (rand() % 100); // Generates a random number between 1 and 100
    cout << "Guess any number between 1 to 100" << endl;
    while (player_guess != random_no)
    {
        cin >> player_guess;
        if (player_guess == random_no)
        {
            cout << "Congratulations!" << endl;
            break;
        }
        else if (player_guess > random_no)
        {
            cout << "Guess a lower number" << endl;
        }
        else
        {
            cout << "Guess a higher number" << endl;
        }
        count++;
    }
    cout << "You guessed it right in " << count << "th attempt" << endl;
    return 0;
}