#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

class TicTacToe
{
private:
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char current_turn = 'X';
    bool playing = true;
    int state = 0;
    int input;
    void print_board();
    int play_move(int index, char move);
    int check_win(char move);
public:
    void start();
};



#endif