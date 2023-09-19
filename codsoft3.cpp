#include <iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie=false;
string n1;
string n2;

void Display()
{
cout<<n1<<" Player is 1st player so he/she will play first"<<endl;
cout<<n2<<" Player is 2nd player so he/she will play second"<<endl;


cout<<"    |      |  "<<endl;
cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"    | "<<space[0][2]<<endl;
cout<<"    |      |  "<<endl;
cout<<"____|______|____"<<endl;
cout<<"    |      |  "<<endl;
cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"    | "<<space[1][2]<<endl;
cout<<"    |      |  "<<endl;
cout<<"____|______|____"<<endl;
cout<<"    |      |  "<<endl;
cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"    | "<<space[2][2]<<endl;
cout<<"    |      |  "<<endl;
cout<<"    |      |  "<<endl;

}

void InputValues()
{
int digit;

//player1 will enter
if(token=='x')
{
cout<<n1<<" Please Enter"<<endl;
cin>>digit;
}

//player2 will enter
if(token=='o')
{
cout<<n2<<" Please Enter"<<endl;
cin>>digit;
}

if(digit==1)
{
row=0;
column=0;
}

else if(digit==2)
{
row=0;
column=1;
}

else if(digit==3)
{
row=0;
column=2;
}
else if(digit==4)
{
row=1;
column=0;
}
else if(digit==5)
{
row=1;
column=1;
}
else if(digit==6)
{
row=1;
column=2;
}
else if(digit==7)
{
row=2;
column=0;
}
else if(digit==8)
{
row=2;
column=1;
}
else if(digit==9)
{
row=2;
column=2;
}


else if(digit<1||digit>9)
cout<<"Invalid Position!!!"<<endl;

if(token=='x'&&space[row][column]!= 'x'&& space[row][column]!= 'o')
{
space[row][column]='x';
token='o';
}

else if(token=='o'&&space[row][column]!= 'x'&& space[row][column]!= 'o')
{
space[row][column]='o';
token='x';
}

else
{
cout<<"There is no empty space"<<endl;
InputValues();
}
Display();
}

bool Check()
{

//match row column and diagonal values
 for(int i=0;i<3;i++)
 {
 if(space[i][0]==space[i][1]&&space[i][0]==space[i][2] || space[0][i]==space[1][i]&&space[0][i]==space[2][i])
 return true;
 }
 if(space[0][0]==space[1][1]&&space[1][1]==space[2][2] || space[0][2]==space[1][1]&&space[0][2]==space[2][0])
 return true;
 
//check whether the game is finished or not

for(int i=0;i<3;i++)
 {
   for (int j=0;j<3;j++)
    {
     if(space[i][j]!='x'&& space[i][j]!='o') //position empty
     return false;    //not finished so return false
    }
 }
 
 //if above conditions are not satisfied game is draw
tie=true;
return false; 
 
}
int main() {
    cout << "Enter 1st player Name" << endl;
    getline(cin, n1);
    cout << "Enter 2nd player Name" << endl;
    getline(cin, n2);

    char playAgain;
    do {
        // Initialize the game board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                space[i][j] = '1' + i * 3 + j;
            }
        }
        token = 'x';
        tie = false;

        // Play the game
        while (!Check() && !tie) 
        {
            Display();
            InputValues();
            Check(); // if the game is not won by any player and until it is tie these func will keep running
        }

        // Display the result
        if (token == 'x' && !tie)
            cout << n2 << " Wins" << endl;
        else if (token == 'o' && !tie)
            cout << n1 << " Wins" << endl;
        else
            cout << "It's a draw" << endl;

        // Ask if players want to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;
         
    } while (playAgain == 'y');

    return 0;
}

