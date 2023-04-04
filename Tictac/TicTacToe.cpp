#include<iostream>
#include "TicTacToe.h"


void TicTacToe::start()
{
    while (playing == true)
    {
        print_board();
        std::cout << "Play your move " << current_turn << std::endl;
        std::cin >> input;
        if (play_move(input, current_turn) == 0)
        {
            std::cout << "Box already occupied" << std::endl;
            continue;
        };
        state = check_win(current_turn);
        if (state == 1)
        {
            print_board();
            std::cout << current_turn << " wins the game!" << std::endl;
            break;
        }
        else if (state == 2)
        {
            std::cout << "Draw!" << std::endl;
            break;
        };
        current_turn = (current_turn == 'X') ? 'O' : 'X';
    }
};


void TicTacToe::print_board()
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            std::cout << " | ";
        }
        std::cout << board[i];
        if (i == 2 || i == 5)
        {
            std::cout << std::endl;
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
};


int TicTacToe::play_move(int index, char move)
{
    if (index >= 0 && index < 9)
    {
        if (board[index] == ' ')
        {
            board[index] = move;
            return 1;
        }
    }
    return 0;
};


/*
   0 1 2
   3 4 5
   6 7 8
*/
int TicTacToe::check_win(char move)
{
    if (
        // Horizontal checks
        (board[0] == move && board[1] == move && board[2] == move) ||
        (board[3] == move && board[4] == move && board[5] == move) ||
        (board[6] == move && board[7] == move && board[8] == move) ||
        // Vertical Checks
        (board[0] == move && board[3] == move && board[6] == move) ||
        (board[1] == move && board[4] == move && board[7] == move) ||
        (board[2] == move && board[5] == move && board[8] == move) ||
        // Diagonal Checks
        (board[0] == move && board[4] == move && board[8] == move) ||
        (board[2] == move && board[4] == move && board[6] == move))
    {
        return 1;
    }
    else
    {
        bool draw = true;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                draw = false;
                break;
            }
        }
        if (draw == true)
        {
            return 2;
        }
    }
    return 0;
};