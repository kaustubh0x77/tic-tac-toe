#include <iostream>
#include "Board.cpp"
#include <unistd.h>
#include <curses.h>
#include <map>
#include <string>

#define SYMBOL1 'X'
#define SYMBOL2 'O'

char checkWinner(char state[3][3]){
    // 3 Horizontal rows
    for(int i = 0; i < 3; i++){
        if (state[i][0] != ' ' && state[i][0] == state[i][1] && state[i][1] == state[i][2])
            return state[i][0];
    }
    // 3 Vertical rows
    for(int i = 0; i < 3; i++){
        if (state[0][i] != ' ' && state[0][i] == state[1][i] && state[1][i] == state[2][i]) 
            return state[i][0];
    }
    //Diagonals
    if (state[0][0] != ' ' && state[0][0] == state[1][1] && state[1][1] == state[2][2] )
        return state[0][0];
    if (state[2][0] != ' ' && state[2][0] == state[1][1] && state[1][1] == state[0][2] )
        return state[2][0];
    
    return ' ';
}

int main(){
    WINDOW *w = initscr();
    noecho();
    keypad(w, true);

    char state[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            state[i][j] = ' ';
        }
    }

    Board b;
    b.displayBoard();
    b.setState(state);
    
    char player = SYMBOL1;
    char winner = ' ';

    while ( (winner = checkWinner(state)) == ' ' ){
        pair<int,int> p = b.getPos();
        int y = p.first, x = p.second;

        if(state[y][x] == ' '){
            state[y][x] = player;
            b.setState(state);
            if(player == SYMBOL1) player = SYMBOL2;
            else player = SYMBOL1;
        }
        
    }
    string s = "Winner is " + winner;
    mvaddstr(40,10,s.c_str());
    refresh();
    sleep(3);

    delwin(w);
    endwin();
    refresh();
}