#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#define TIC_TAC_SIZE 3;
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

struct tic_tac_op
{
    int best_i;
    int best_j;
};

void draw_tic_tac_toe_game_window(char tic_tac[3][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("-------\n");
        }

        for (int j = 0; j < size; j++)
        {
            printf("|%c", tic_tac[i][j]);
        }
        printf("|\n");
        printf("-------\n");
    }
}

int is_completed(char array[3][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_winner(char tic_tac_toe_game_window[3][3], int size, char computer_code, char player_code, int depth)
{
    // check for diagonal wins
    int diag_computer = 0;
    int diag_player = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                if (tic_tac_toe_game_window[i][j] == player_code)
                {
                    diag_player++;
                }
                else if (tic_tac_toe_game_window[i][j] == computer_code)
                {
                    diag_computer++;
                }
            }
        }
    }

    if (diag_computer == size)
    {
        return 10 - depth; // computer wins
    }
    if (diag_player == size)
    {
        return -10 + depth; // player wins
    }

    // check reverse diagonal

    int diag_computer_t = 0;
    int diag_player_t = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == size - j - 1)
            {
                if (tic_tac_toe_game_window[i][j] == player_code)
                {
                    diag_player_t++;
                }
                else if (tic_tac_toe_game_window[i][j] == computer_code)
                {
                    diag_computer_t++;
                }
            }
        }
    }

    if (diag_computer_t == size)
    {
        return 10 - depth; // computer wins
    }
    if (diag_player_t == size)
    {
        return -10 + depth; // player wins
    }

    // check for rows
    int row_computer, row_player;
    for (int i = 0; i < size; i++)
    {
        row_computer = 0;
        row_player = 0;

        for (int j = 0; j < size; j++)
        {
            if (tic_tac_toe_game_window[i][j] == player_code)
            {
                row_player++;
            }
            else if (tic_tac_toe_game_window[i][j] == computer_code)
            {
                row_computer++;
            }
        }

        if (row_computer == size)
        {
            return 10 - depth;
        }
        if (row_player == size)
        {
            return -10 + depth;
        }
    }

    // check for column
    int col_computer, col_player;
    for (int i = 0; i < size; i++)
    {
        col_computer = 0;
        col_player = 0;

        for (int j = 0; j < size; j++)
        {
            if (tic_tac_toe_game_window[j][i] == player_code)
            {
                col_player++;
            }
            else if (tic_tac_toe_game_window[j][i] == computer_code)
            {
                col_computer++;
            }
        }

        if (col_computer == size)
        {
            return 10 - depth;
        }
        if (col_player == size)
        {
            return -10 + depth;
        }
    }

    // nobody wins

    return INT_MIN;
}

int minimax(char tic_tac_array[3][3], int size, int depth, bool is_maximizer)
{

    int score = check_winner(tic_tac_array, size, 'X', 'O', depth);
    if (score != INT_MIN)
    {
        return score;
    }

    if (is_completed(tic_tac_array, size))
    {
        return 0;
    }

    if (is_maximizer)
    {
        int best = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (tic_tac_array[i][j] == ' ') // empty slot
                {
                    // char **new_tic_tac_array = intialize_empty_array(size);
                    // copy_array(tic_tac_array, new_tic_tac_array, size);

                    tic_tac_array[i][j] = 'X';
                    best = max(minimax(tic_tac_array, size, depth + 1, false), best);

                    tic_tac_array[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    {
        int best = INT_MAX;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (tic_tac_array[i][j] == ' ') // empty slot
                {
                    // char **new_tic_tac_array = intialize_empty_array(size);
                    // copy_array(tic_tac_array, new_tic_tac_array, size);

                    tic_tac_array[i][j] = 'O';
                    best = min(
                        minimax(tic_tac_array, size, depth + 1, true),
                        best);

                    tic_tac_array[i][j] = ' ';

                    // free(new_tic_tac_array);
                }
            }
        }
        return best;
    }
}

bool tie_breaker_move(int curr_row, int curr_col, int new_row, int new_col)
{
    if (new_row == 1 && new_col == 1)
    {
        // center position in tie breaker
        return true;
    }
    return false;
}

struct tic_tac_op findBest(char tic_tac_array[3][3], int size)
{
    int best_i = -1;
    int best_j = -1;
    int best_score = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (tic_tac_array[i][j] == ' ')
            {
                tic_tac_array[i][j] = 'X';
                int best = minimax(tic_tac_array, size, 0, false);
                tic_tac_array[i][j] = ' ';
                if (best > best_score || (best == best_score && tie_breaker_move(best_i, best_j, i, j)))
                {
                    best_score = best;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    struct tic_tac_op best_move;
    best_move.best_i = best_i;
    best_move.best_j = best_j;

    return best_move;
}

void clear_terminal()
{
    system("cls");
}

void clear_screen_and_redraw_window(char array[3][3], int size)
{
    clear_terminal();
    printf("This is a tic-tac-toe game.\nYou are playing against computer.\n");
    draw_tic_tac_toe_game_window(array, 3);
}

bool position_available(char array[3][3], int row, int col)
{
    if (row > 3 || row < 1 || col > 3 || col < 1)
    {
        return false;
    }
    return array[row - 1][col - 1] == ' ';
}

void main()
{

    char tic_tac_array[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tic_tac_array[i][j] = ' ';
        }
    }

    clear_screen_and_redraw_window(tic_tac_array, 3);

    int you_wanna_start_first;
    printf("You wanna start? (1 - yes, 0 - no): ");
    scanf("%d", &you_wanna_start_first);

    if (you_wanna_start_first != 1)
    { // computer plays first
        printf("Sure .. Computer is Playing ....\n");

        Sleep(1000);

        struct tic_tac_op result = findBest(tic_tac_array, 3);
        tic_tac_array[result.best_i][result.best_j] = 'X';
        clear_screen_and_redraw_window(tic_tac_array, 3);
    }

    while (1)
    {
        printf("You are playing as O.\nEnter your move in this format -> <row> <space> <col>: ");
        int row;
        int col;
        do
        {
            scanf("%d", &row);
            scanf("%d", &col);
            if (!position_available(tic_tac_array, row, col))
            {
                printf("Illegal move. Enter again: ");
            }
        } while (!position_available(tic_tac_array, row, col));

        tic_tac_array[row - 1][col - 1] = 'O';
        clear_screen_and_redraw_window(tic_tac_array, 3);

        if (check_winner(tic_tac_array, 3, 'X', 'O', 0) != INT_MIN)
        {
            printf("You win!\n");
            break;
        }

        if (is_completed(tic_tac_array, 3))
        {
            printf("---Draw----");
            break;
        }

        printf("Computer Playing ....\n");

        Sleep(1000);

        struct tic_tac_op result = findBest(tic_tac_array, 3);
        tic_tac_array[result.best_i][result.best_j] = 'X';
        clear_screen_and_redraw_window(tic_tac_array, 3);

        if (check_winner(tic_tac_array, 3, 'X', 'O', 0) != INT_MIN)
        {
            printf("Oops! ... You loose!\n");
            break;
        }

        if (is_completed(tic_tac_array, 3))
        {
            printf("---Draw----");
            break;
        }
    }

    return;
}