#include <iostream>

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row = -1;
int column = -1;
string n1 = "";
string n2 = "";
char token = 'X';
bool isTie = false;
int player1Wins = 0;
int player2Wins = 0;

void clearScreen() {
    // Clear the console screen
    cout << "\033[2J\033[1;1H"; 
}

void functionOne()  // Function used for displaying the board
{ 
    clearScreen();  // Clear the screen before starting a new round

    cout << "    |    |   \n";
    cout << " " << space[0][0] << "  | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[1][0] << "  | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[2][0] << "  | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout << "    |    |    \n";
}

void functionTwo()   // Function to handle player input and update the game board
{ 

    int digit;

    if (token == 'X')
    {
        cout << n1 << " Please enter: ";
        cin >> digit;
    }
    if (token == 'O')
    {
        cout << n2 << " Please enter: ";
        cin >> digit;
    }

    switch(digit){
        case 1: {row = 0;column = 0;break;}
        case 2: {row = 0;column = 1;break;}
        case 3: {row = 0;column = 2;break;}
        case 4: {row = 1;column = 0;break;}
        case 5: {row = 1;column = 1;break;}
        case 6: {row = 1;column = 2;break;}
        case 7: {row = 2;column = 0;break;}
        case 8: {row = 2;column = 1;break;}
        case 9: {row = 2;column = 2;break;}
        default:{
            cout<<"Invalid !!!";
            break;
        }
    }

    if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O')
    {
        space[row][column] = 'X';
        token = 'O';
    }
    else if (token == 'O' && space[row][column] != 'X' && space[row][column] != 'O')
    {
        space[row][column] = 'O';
        token = 'X';
    }
    else
    {
        if(digit>=1 && digit<=9){
            cout << "There is no empty space" << endl;
        }
        functionTwo();
    }
}

bool functionThree()  // Function used for checking winner or draw
{ 
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }
    isTie = true;
    return true;
}

void resetGame() {
    // Reset the game board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = '1' + (i * 3 + j);
        }
    }

    // Reset game state variables
    row = -1;
    column = -1;
    token = 'X';
    isTie = false;
}

int main()
{

    cout << "Enter the name of the first player : \n";
    getline(cin, n1);
    cout << "Enter the name of the second player : \n";
    getline(cin, n2);
    cout << n1 << " is player1 so he/she will play first \n";
    cout << n2 << " is player2 so he/she will play second \n";

    while (true) {
        resetGame(); // Reset the game before starting a new round

        cout << n1 << " is player 1, and " << n2 << " is player 2.\n";

        while (!functionThree()) {
            functionOne();
            functionTwo();
        }

        functionOne(); // Display the final game board

        if (token == 'X' && isTie == false)
        {
            cout << n2 << " Wins!!" << endl;
            player2Wins++;
        }
        else if (token == 'O' && isTie == false)
        {
            cout << n1 << " Wins!!" << endl;
            player1Wins++;
        }
        else
        {
            cout << "It's a draw!" << endl;
        }

        cout << "Score: " << n1 << " - " << player1Wins << ", " << n2 << " - " << player2Wins << "\n";

        // Ask if players want to play again
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y') {
            cout<<"------Thanyou------";break;
        }   
    }
    return 0;
}