#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[10][10],isSelected[10][10],inputX=0,inputY=0,lives=3;

void printBoard(int n,int lives)
{
    printf("      x 1 2 3 4 5 6 7 8 9 10\ny\n");
    for (int i=0;i<10;i++)
    {
        printf("%i\t",i+1);
        for (int j=0;j<10;j++)
        {
            if (isSelected[j][i]==0)
                printf("* ");
            else
                printf("%i ",board[j][i]);
        }
        printf("\n");
    }
    printf("\nLives: %i\n",lives);
    if (n!=0&&board[inputX-1][inputY-1]==1)
    {
        printf("\nYou hit a bomb!!\n");
        if (lives==0)
        {
            printf("You ran out of lives...\n");
        }
    }
}

void game()
{
    system("cls");
     int randX,randY,score=0;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            board[i][j]=0;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            isSelected[i][j]=0;
    srand(time(0));
    for(int i=0;i<5;i++)
    {
        randX=rand()%10;
        randY=rand()%10;
        if (board[randX][randY]==0)
            board[randX][randY]=1;
        else
            i--;
    }
    for (int n=0;n<10&&int lives!=0;n++)
    {
        printBoard(n,lives);
        inputX=0,inputY=0;
        if (lives!=0)
        {
            printf("\nInput coordinates to check [x,y]: ");
            while (inputX<1||inputX>10||inputY<1||inputY>10)
            {
                scanf("%i %i",&inputX,&inputY);
                if (inputX<1||inputX>10||inputY<1||inputY>10)
                    printf("\nInvalid coordinates [x,y]: ");
            }
        }
        if(isSelected[inputX-1][inputY-1]==0)
            isSelected[inputX-1][inputY-1]=1;
        else
            n--;
        if (board[inputX-1][inputY-1]==1)
            lives--;
        else
            score+=10;
        system("cls");
    }
    printBoard(10,lives);
    if (lives!=0)
        printf("\nYOU WIN!!\n");
    printf("Score: %i\n", score);
    system("pause");
    main();

}

int main()
{
    int choice;
    system("cls");
    printf("\t\tWelcome to Minesweeper\n");
    printf("1.play\n");
    printf("2.exit\n");
    printf(" Please select number: ");
    scanf(" %d",&choice);

    switch(choice)
    {
        case 1:
            {
            game();
            };break;
        case 2:
            {
            printf("goodbye!");
            };break;
        default: printf("Error! Pls input 1 and 2 only!");
    }


   }
