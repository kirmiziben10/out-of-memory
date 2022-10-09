#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void printToConsole();
void fillBackground(char);
void movePlayer(char);
void addPlayer();
void fastPrint(char[]);

#define ROWS 10
#define COLUMNS 50

char grid[COLUMNS + 1][ROWS];
char buffer[(COLUMNS + 2) * ROWS];
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
        printf("\033[H");
        printf("%s", buffer);
        movePlayer(getch());
    }

    return 0;
};

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
        if (playerY != ROWS - 1)
        {
            playerY++;
        }

        break;
    case 'd':
        if (playerX != COLUMNS - 1)
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

// Assign everything to the buffer

void printToConsole()
{
    int i, j;
    for (int i = 0; i < (COLUMNS)*ROWS; i++)
    {
        buffer[i] = '0';
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            buffer[i * COLUMNS + j + i] = grid[j][i];
        };
        buffer[(i + 1) * (COLUMNS) + i] = '\n';
    };
};
