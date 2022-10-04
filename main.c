#include <stdio.h>
#include <time.h>
#include <conio.h>
void printToConsole();
void fillBackground(char);
void movePlayer(char);
void addPlayer();
void fastPrint(char []);

#define ROWS 20
#define COLUMNS 80

char grid[COLUMNS][ROWS];
char buffer[64];
char backgroundChar = 176, playerChar = 226;
int playerX = 0, playerY;
int iterations;

int main()
{
    while (1)
    {
        fillBackground(backgroundChar);
        addPlayer();
        printToConsole();
        movePlayer(getch());
        system("cls");
    }

    return 0;
};

//Change player coordinates based on the input
void movePlayer(char direction)
{

    switch (direction)
    {
    case 'w':
        if (playerY != 0)
        {
            playerY--;
        };
        break;
    case 'a':
        if (playerX != 0)
        {
            playerX--;
        }
        break;
    case 's':
        if (playerY != ROWS)
        {
            playerY++;
        }

        break;
    case 'd':
        if (playerX != COLUMNS)
        {
            playerX++;
        }
        break;

    default:
        break;
    }
};

void addPlayer()
{
    grid[playerX][playerY] = playerChar;
};

// Fill the background with desired ascii
void fillBackground(char backgroundChar)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            grid[j][i] = backgroundChar;
        };
    };
};

// Print everything to the console
void printToConsole()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            printf("%c", grid[j][i]);
        };
        printf("\n");
    };
};
