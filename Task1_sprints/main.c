#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
// #include <time.h>
/*
 *
 *  Created on: Mar 27, 2023
 *      Author: youseif essam
 */

#define WIN 0
#define DRAW 1
#define COONTINUE 2
typedef unsigned char uint8_t;

/**************************Functions prototype****************************/

void drawBoard(uint8_t *board); 
/* Function description:
* This function for draw figure of playing
*/

void updateBoard(uint8_t *board, uint8_t position, uint8_t value);
/*Function description:
* This function to upadte figure of playing through take sympol (x/o) and positon from user
*/

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol); // choose player number and his symbol
/*Function description:
* This function to determine each sympol for each player who is first player and his sympol and the same foe second player
*/

void setPlayerConfig(uint8_t *configArray);
/*Function description:
* This function to save each player sympol in array to save it
*/

void loadAndUpdate(uint8_t playerNumber);
/*Function description
* This function determine which player will play 
*/

void getGameState(uint8_t *board, uint8_t *gameState);
/*Function description
* This function to determine the status of game (win/lose/draw)
*/

/**************************Functions prototype****************************/

uint8_t board1[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};    /*Array for printing figure of play*/
uint8_t symbols[2] = {0};   /*Array for sorting sympols of players*/
uint8_t position; // golbal variable to determine the position of playre where he want to play
uint8_t falg_Get_symbol = 0; // flag to check if player repeated sympol or wrong sympol
uint8_t var; // posotion 
uint8_t player=1;
int main()
{
    uint8_t end = 2;
    drawBoard(board1);
    setPlayerConfig(symbols);
    do
    {
        getGameState(board1, &end);
        if (end==WIN || end==DRAW)
        {
            break;
        }
        loadAndUpdate(player==2?player--:player++);
    } while (end != 0 || end != 1);
    return 0;
}
/**************************Functions definition****************************/
void drawBoard(uint8_t *board)
{
    for (uint8_t i = 0; i < 10; i++)
    {
        if (i != 2 && i != 5 && i != 8)
        {
            printf(" %c |", board[i]);
        }
        else
        {
            printf(" %c ", board[i]);
        }
        if (i == 2 || i == 5)
        {
            printf("\n");
            printf("___|___|___\n");
        }
    }
    printf("\n");
}

void updateBoard(uint8_t *board, uint8_t position, uint8_t value)
{
    board[position - 1] = value; // put sympol in the array of board 
    drawBoard(board); // then draw the new array with the sympol of player
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol)
{
    uint8_t  symbolnum = 0;
    printf("player %d enter your symbol: ", playerNumber);
    do
    {
        fflush(stdin); // due to problem in scan if 
        scanf("%c", &symbolnum); // take the sympol and check it using switch case if sympol wrong or repeated
        switch (symbolnum)
        {
        case 'o':
        case 'O':
        case 'x':
        case 'X':
            if (symbolnum==symbol[0] || abs((symbolnum-symbol[0]))==32 ) // for capital and small nymbers this 32 the diffrence between small and capital letter 
            {
                printf("already choosen\n");
                falg_Get_symbol=1;
                break;
            }
            symbol[playerNumber - 1] = symbolnum; // take the second sympol from player 
            falg_Get_symbol = 0;
            break;
        default:
            printf("enter valid symbol\n");
            falg_Get_symbol = 1;
            break;
        }
    } while (falg_Get_symbol);
    falg_Get_symbol=0;
}

void setPlayerConfig(uint8_t *configArray)
{
    getPlayerSymbol(1,configArray);
    getPlayerSymbol(2,configArray);
    
}

void loadAndUpdate(uint8_t playerNumber)
{
    printf("PLAYER %d Choose position ",playerNumber); // take the position of player 
    scanf("%d", &var);
    while (board1[var-1]=='x' ||board1[var-1]=='X' ||board1[var-1]=='o'|| board1[var-1]=='O' || var > 9 || var<=0 ) // check if player play in wrong positon
    {
        printf("invalid move\n");
        printf("PLAYER %d Choose a valid position ",playerNumber);
        scanf("%d", &var);
    }
    updateBoard(board1, var, symbols[playerNumber-1]); // then take position update the board 
}

void getGameState(uint8_t *board, uint8_t *gameState)
{

    static uint8_t freespaces = 10; // variable to check if there are any empty spaces
    freespaces--;
    *gameState = COONTINUE;
    if ((board[0] == board[1] && board[0] == board[2]) || (board[3] == board[4] && board[3] == board[5]) || (board[6] == board[7] && board[6] == board[8] )|| /**/ (board[0] == board[3] && board[0] == board[6]) || (board[1] == board[4] && board[1] == board[7]) ||( board[2] == board[5] && board[2] == board[8]) || /**/( board[0] == board[4] && board[0] == board[8] )||( board[2] == board[4] && board[2] == board[6])) // check if there are values in rows or colums or diagonal are equal
    {
        *gameState = (uint8_t)WIN;
        printf("The player: %d is the winner congratulations",player==2?1:2);
        freespaces=10;
    }
    else if (freespaces == 0)
    {
        *gameState = DRAW;
        printf("Draaaw");
        freespaces=10;
    }
}
/**************************Functions definition****************************/
