#include<stdio.h>
#include<conio.h>
#define ME 'X'
#define AI 'O'
#define DEF 999

char board[9]={'0','1','2','3','4','5','6','7','8'};
void boardPattern()
{
    // printf("\n");
    // for(int i=0;i<9;i++)
    // {
    //     if(i % 3==0 && i!=0)
    //     printf("\n---+---+---");
    //     printf("%c",board[i]);
    //     if(i% 3 !=2)
    //     printf("|");

    // }
    // printf("\n\n");
    for (int r = 0; r < 3; r++) {
        printf("%c  |%c  | %c\n", board[r*3], board[r*3 + 1], board[r*3 + 2]);
        if (r < 2) printf("---+---+---\n");
    }
    // printf("\n");
}
int isMovesLeft()
{
    for(int i=0;i<9;i++)
    if(board[i]!= 'X' && board[i] != 'O')
    return 1;
    return 0;
}
int evaluate()
{
    int winComb[8][3]={
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for(int i=0;i<8;i++)
    {
        int a=winComb[i][0], b=winComb[i][1], c=winComb[i][2];
        if(board[a]==board[b] && board[b]==board[c])
        {
            if(board[a]==AI)
            return +10;
            else if (board[a]==ME)
            return -10;
        }
    }
    return 0;
}
int minmax(int depth, int Max)
{
    int score= evaluate();
    if(score == 10)
    return score - depth;
    if(score ==-10)
    return score + depth;
    if(!isMovesLeft()) return 0;

    if(Max)
    {
        int best=-DEF;
        for(int i=0;i<9;i++)
        {
            if(board[i]!= 'X' && board[i]!= 'O'){
            char backup=board[i];
            board[i]=AI;
            int val= minmax(depth +1, 0);
            if(val > best)
            best =val;
            board[i] =backup;
            }
        }
        return best;
    }
    else{
        int best =DEF;
        for(int i=0;i<9;i++)
        {
            if(board[i]!='X' && board[i] !='O')
            {
                char backup =board[i];
                board[i]=ME;
                int val=minmax(depth +1,1);
                if(val < best) best= val;
                board[i] = backup;
            }
        }
        return best;
    }

}
int BestMove()
{
    int bestval=-DEF, bestMove=-1;
    for(int i=0;i<9;i++)
    {
        if(board[i] != 'X' && board[i] !='O')
        {
            char backup= board[i];
            board[i] =AI;
            int moveVal = minmax(0,0);
            board[i] = backup;

            if(moveVal > bestval)
            {
                bestMove =i;
                bestval = moveVal;
            }
        }
    }
    return bestMove;
}
int main()
{
    int move;
    printf("Tic Tac Toe Game:\n");
    printf("Your Symbol id 'X' & AI: 'O' \n");
    boardPattern();

    while(isMovesLeft() && evaluate()==0)
    {
        printf("Enter your move select number from 0-8:");
        scanf("%d",&move);
        if (move <0 || move >8 || board[move] == 'X' || board[move]=='O')
        {
            printf("Its invalid Select number between 0 to 8 onl");
            continue;
        }
        board[move]=ME;
        boardPattern();
        if(evaluate()==-10)
        {
            printf("You WIN!!");
            break;
        }
        if(!isMovesLeft())
        break;

        int aimove = BestMove();
        board[aimove] =AI;
        printf("AI choose %d\n", aimove);
        boardPattern();
        if(evaluate()==10)
        {printf("AI Win this time>>!");
        break;}
       
        
    }
     if(evaluate()==0 && !isMovesLeft())
    printf("Its a DRAW!\n");
    return 0;
}
