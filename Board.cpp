#include <iostream>
#include <curses.h>
#include <string>
#include <unistd.h>
#include <map>

using namespace std;

class Board{
    /**
     * [ ][ ][ ]
     * [ ][ ][ ]
     * [ ][ ][ ]
     *   
    */
    public:
        Board(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    boardState[i][j] = ' ';
                }
            }
            highlightX = 0;
            highlightY = 0;
            offX = (COLS - 9) / 2;
            offY = (LINES - 3) / 2;
        }

        void displayBoard(){
            //int offX = 10 , offY = 10;
            for(int y = 0; y < 3; y++){
                for(int x = 0; x < 3; x++){
                    //cout << "[" << boardState[y][x] << "]";
                    mvaddch(offY + y, offX + 3*x, '[');
                    mvaddch(offY + y, offX + 3*x + 1, boardState[y][x]);
                    mvaddch(offY + y, offX + 3*x + 2, ']');
                }
            }
            mvaddch(offY + highlightY, offX + 3*highlightX, '[');
                            // boardState[highlightY][highlightX]); 
                            // Hack for cursor advancement 
            refresh();
        }

        void moveCursorRelative(int yDiff, int xDiff){
            highlightX += xDiff;
            if (highlightX > 2) highlightX = 2;
            if (highlightX < 0) highlightX = 0;

            highlightY += yDiff;
            if (highlightY > 2) highlightY = 2;
            if (highlightY < 0) highlightY = 0; 
        }

        pair<int,int> getPos(){
            unsigned int ch;
            // curs_set(0);
            pair<int,int> pos(-1,-1); //pos = (y,x);

            while( (ch = getch()) != '\n'){
                switch( (unsigned int)ch){
                    case KEY_UP:
                        this->moveCursorRelative(-1,0);
                        break;
                    case KEY_DOWN:
                        this->moveCursorRelative(1,0);
                        break;
                    case KEY_LEFT:
                        this->moveCursorRelative(0,-1);
                        break;
                    case KEY_RIGHT:
                        this->moveCursorRelative(0,1);
                }
                this->displayBoard();
                refresh();
            }
            pos.second = highlightX;
            pos.first = highlightY;
            return pos;
        }

        void setState(char state[3][3]){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    boardState[i][j] = state[i][j];
                }
            }
            this->displayBoard();
        }
    private:
        char boardState[3][3];
        int highlightX;
        int highlightY;
        int offY;
        int offX;
};

/**
int main(){
    WINDOW *win = initscr();
    noecho();
    keypad(win, true);
    
    if (win == NULL){
        cout << "Problem loading curses\n";
        return 1;
    }

    Board b;
    b.displayBoard();
    refresh();
    int l = 9;
    char state[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            state[i][j] = ' ';
        }
    }
    while(l > 0){
        auto a = b.getPos();
        state[a.first][a.second] = 'X';
        b.setState(state);
    }
    delwin(win);
    endwin();
    refresh();

    //cout << a.first << " " << a.second;
    return 0;
}
*/