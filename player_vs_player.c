// Player vs Player

#include <stdio.h>
#include <stdlib.h>
char board_data[9];
int board_state[9];
int turn = 1; // 1 for X and 0 for O
int choice_index;
void set_all_board_values()
{
    int i;
    for (i = 0; i < 9; i++)
    {
        board_data[i] = '.';
        board_state[i] = 0;
    }
}
void display_reference()
{
    int i;
    for (i = 0; i < 9; i += 3)
    {
        printf(" %d | %d | %d \n", i, i + 1, i + 2);
        if (i != 6)
        {
            printf("-----------\n");
        }
    }
    printf("\n\n");
}
void display_board()
{
    int i;
    for (i = 0; i < 9; i += 3)
    {
        printf(" %c | %c | %c \n", board_data[i], board_data[i + 1], board_data[i + 2]);
        if (i != 6)
        {
            printf("-----------\n");
        }
    }
    printf("\n\n");
}
int print_your_turn(int t)
{
    int c;

    while (1)
    {
        if (t == 1)
        {
            // x turn
            printf("X turn pls enter your choice index: ");
        }
        if (t == 0)
        {
            // o turn
            printf("O turn pls enter your choice index: ");
        }
        scanf("%d", &c);
        if (c >= 9 || c < 0)
        {
            printf("Enter a valid choice index. it must be from 0 to 8\n");
        }
        else if (board_state[c] == 1)
        {
            printf("its already filled!!\n");
        }
        else if (board_state[c] == 0)
        {
            if (turn == 1)
            {
                board_data[c] = 'x';
            }
            if (turn == 0)
            {
                board_data[c] = 'o';
            }
            board_state[c] = 1;
            break;
        }
    }

    return c;
}
void switch_turn()
{
    if (turn == 0)
    {
        turn = 1;
    }
    else if (turn == 1)
    {
        turn = 0;
    }
}
int check_win(char ch)
{
    if (board_data[0] == ch && board_data[1] == ch && board_data[2] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[3] == ch && board_data[4] == ch && board_data[5] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[6] == ch && board_data[7] == ch && board_data[8] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[0] == ch && board_data[3] == ch && board_data[6] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[1] == ch && board_data[4] == ch && board_data[7] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[2] == ch && board_data[5] == ch && board_data[8] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[0] == ch && board_data[4] == ch && board_data[8] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
    if (board_data[2] == ch && board_data[4] == ch && board_data[6] == ch)
    {
        printf("%c wins\n", ch);
        return 1;
    }
}

void main()
{
    set_all_board_values();
    turn = 1; // setting first turn to X
    int game_over;
    int chance_ongoing;
    chance_ongoing = 0;
    game_over = 2;
    while (1)
    {
        system("cls");
       // printf("chance %d\n", chance_ongoing);
        chance_ongoing++;
        if (chance_ongoing >9)
        {
            break;
        }

        display_reference();
        display_board();
        choice_index = print_your_turn(turn);
        switch_turn();
        game_over = check_win('x');
        if (game_over == 1)
        {
            break;
        }

        game_over = check_win('o');
        if (game_over == 1)
        {
            break;
        }
    }
    system("cls");
    display_reference();
    display_board();
    game_over = check_win('x');
    game_over = check_win('o');
    if (game_over != 1)
    {
        printf("Its a draw.\n");
    }
    system("pause");
}