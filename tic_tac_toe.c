#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLK "\e[1;90m"
#define RED "\e[1;91m"
#define GRN "\e[1;92m"
#define YEL "\e[1;93m"
#define BLU "\e[1;94m"
#define MAG "\e[1;95m"
#define CYN "\e[1;96m"
#define WHT "\e[1;97m"
#define RES "\e[0m"

int computer();
int checkwin();
void board();
int you();

char ch[10] = {'0','1','2','3','4','5','6','7','8','9'};
int com_r[9] = {1,2,3,4,5,6,7,8,9};
int winner;

int main(void)
{
    int i,j,k,m;
    char term;
    srand(time(NULL));
    for(i=0;i<9;i++)
    {
        j = (rand()%8)+1;
            k = com_r[i];
            com_r[i] = com_r[j];
            com_r[j] = k;
    }

    printf(WHT"\n\n\t Tic Tac Toe\n\n"RES);
    printf(BLU"\nDo you want to play first?"RES);
    printf(GRN" (y/n) "RES);

    term = getchar();

    if(term == 'y')
    {
        printf(CYN"\n\nyour mark is "RES);
        printf(YEL"'X'"RES);

        board();

        do
        {
            you();

            m = checkwin();

            if(m != 1 && m != 0)
            {
                computer();

                m = checkwin();

                board();
            }
        } while( m == -1 );

        printf(BLU"\nFinal Result\n"RES);

        board();

    }

    else if(term == 'n')
    {
        printf(CYN"\n\nYour mark is "RES);
        printf(YEL"'X'"RES);

        do
        {
            computer();
            
            board();

            m = checkwin();

            if(m != 1 && m != 0)
            {
                you();
            }

            m = checkwin();

        } while( m == -1 );

        printf(BLU"\nFinal Result\n"RES);

        board();

    }

    else
    {
        printf(RED"\n\n\t\tEND\n\n"RES);
        exit(1);
    }

    if(m == 1 && winner == 1)
    {
        printf(RED"\n\t{ COMPUTER WIN }\n\n"RES);
    }

    else if(m == 1 && winner == 0)
    {
        printf(GRN"\n\t{ YOU WIN }\n\n"RES);
    }

    else
    {
        printf(YEL"\n\t{ TIE }\n\n"RES);
    }


}

int computer(void)
{
    char markc;
    int choice_c,l=1;
    markc = 'O';
    a_again:
    choice_c = com_r[l];
    if (choice_c == 1 && ch[1] == '1')
        ch[1] = markc;
            
    else if (choice_c == 2 && ch[2] == '2')
        ch[2] = markc;
            
    else if (choice_c == 3 && ch[3] == '3')
        ch[3] = markc;
            
    else if (choice_c == 4 && ch[4] == '4')
        ch[4] = markc;
            
    else if (choice_c == 5 && ch[5] == '5')
        ch[5] = markc;
            
    else if (choice_c == 6 && ch[6] == '6')
        ch[6] = markc;
            
    else if (choice_c == 7 && ch[7] == '7')
        ch[7] = markc;
            
    else if (choice_c == 8 && ch[8] == '8')
        ch[8] = markc;
            
    else if (choice_c == 9 && ch[9] == '9')
        ch[9] = markc;
            
    else
    {   
        l++;
        goto a_again;
    }

    l++;
    winner = 1;

}

int you()
{
    int choice;
    char mark;
    mark = 'X';

    winner = 0;

    again:
    printf(YEL"\nEnter Your Choice : "RES);
    scanf("%d", &choice);
    if (choice == 1 && ch[1] == '1')
        ch[1] = mark;
            
    else if (choice == 2 && ch[2] == '2')
        ch[2] = mark;
            
    else if (choice == 3 && ch[3] == '3')
        ch[3] = mark;
            
    else if (choice == 4 && ch[4] == '4')
        ch[4] = mark;
            
    else if (choice == 5 && ch[5] == '5')
        ch[5] = mark;
            
    else if (choice == 6 && ch[6] == '6')
        ch[6] = mark;
            
    else if (choice == 7 && ch[7] == '7')
        ch[7] = mark;
            
    else if (choice == 8 && ch[8] == '8')
        ch[8] = mark;
            
    else if (choice == 9 && ch[9] == '9')
        ch[9] = mark;
            
    else
    {
        printf(RED"Invalid Move "RES);
        goto again;
    }

}

int checkwin()
{
    if (ch[1] == ch[2] && ch[2] == ch[3])
        return 1;
        
    else if (ch[4] == ch[5] && ch[5] == ch[6])
        return 1;
        
    else if (ch[7] == ch[8] && ch[8] == ch[9])
        return 1;
        
    else if (ch[1] == ch[4] && ch[4] == ch[7])
        return 1;
        
    else if (ch[2] == ch[5] && ch[5] == ch[8])
        return 1;
        
    else if (ch[3] == ch[6] && ch[6] == ch[9])
        return 1;
        
    else if (ch[1] == ch[5] && ch[5] == ch[9])
        return 1;
        
    else if (ch[3] == ch[5] && ch[5] == ch[7])
        return 1;
        
    else if (ch[1] != '1' && ch[2] != '2' && ch[3] != '3' &&
        ch[4] != '4' && ch[5] != '5' && ch[6] != '6' && ch[7] 
        != '7' && ch[8] != '8' && ch[9] != '9')

        return 0;
    else
        return  - 1;
}

void board()
{
    printf(BLU"\n\n\tBoard\n\n"RES);

    printf(YEL"     |     |     \n"RES);
    printf("  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m \n", ch[1], ch[2], ch[3]);

    printf(YEL"_____|_____|_____\n"RES);
    printf(YEL"     |     |     \n"RES);

    printf("  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m \n", ch[4], ch[5], ch[6]);

    printf(YEL"_____|_____|_____\n"RES);
    printf(YEL"     |     |     \n"RES);

    printf("  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m  \e[1;93m|\e[0m  \e[1;92m%c\e[0m \n", ch[7], ch[8], ch[9]);

    printf(YEL"     |     |     \n\n"RES);
}
