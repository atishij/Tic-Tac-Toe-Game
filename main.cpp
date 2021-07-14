//============================================================================
// Name        : Tictactoeproject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;
void drawboard(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"----------\n";
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
		cout<<"----------\n";
		cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
bool placemarker(int slot){
	int row , col;
	row = slot / 3 ;
	if (slot%3==0){
		row = (slot/3)-1 ;
		col = 2;
	}
	else {
	 col = (slot % 3) - 1;}
	if(board[row][col] !='X' && board[row][col] !='0' )
	 {board[row][col] = current_marker;
	 return true;}
	else return false;
}
int winner()
{
	for(int i = 0 ; i< 3 ; i++)
		{
			// for rows
			if(board[i][0] == board[i][1] && board[i][1] == board[i][2] )
			{
				return current_player;
			}
			// for columns
			if(board[0][i] == board[1][i] && board[1][i] == board[2][i] )
			{
				return current_player;
			}
		}
			// for diagnols
			if(board[0][0] == board[1][1] && board[2][2] == board[1][1] ) return current_player;

			if(board[0][2] == board[1][1] && board[2][0] == board[1][1] ) return current_player;



			return 0;
}
void swap_player_and_marker(){
	if(current_marker == 'X' ){ current_marker = 'O';}
	else current_marker = 'X';
	if(current_player == 1 ){ current_player = 2;}
		else current_player = 1;
}
void game(){
	cout<< " player 1 Choose your marker:";
	char marker_pl1;
	cin >> marker_pl1;
	current_player = 1;
	current_marker = marker_pl1;
	drawboard();

	int player_won;

	for(int i = 0 ; i< 9 ; i++){
		cout<<"it's player "<< current_player<<"'s turn . Enter your slot";
		int slot;
		cin >> slot;
		if (slot <1 && slot>9){
			cout<<"Enter a valid slot";
			i--;
			continue;
		}
		if(!placemarker(slot)){
			cout<<"Slot is already filled!! Try another slot";
			i--;
			continue;
		}
		drawboard();
		player_won = winner();
		if (player_won == 1){ cout<< "Congratulations !!! Player 1 wins";
		break ; }
		if (player_won == 2){ cout<< "Congratulations !!! Player 2 wins";
				break ; }
		swap_player_and_marker();

	}
	if (player_won == 0){ cout<< "TIE!!!!";
					}
}

int main(){
	game();

}
