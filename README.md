# TicTacToe
TicTacToe game in console with documentation 


print_board() is simple. It draws our board at first and then for every move that players do.

play_move(int index, char move) checks if index of your move is correct and changes board 
due to your move

check_win(char move) checks if conbination is winning and checks if it is draw

start() starts the game in while loop, the main interfce and interaction betwwen players.
then checks if it win or draw or to continue the game for another player
game always starts form 'X' only then for 'O'
