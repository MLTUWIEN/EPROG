#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int getwinner(int player, char playboard[]);

void board(char playboard[]);

int main() {
    int choice, player = 0;
    char playboard[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char mark;

    board(playboard);

    do {
        printf("Player %d, enter a number:  ", player % 2 + 1);
        player++;
        scanf("%d", &choice);
        choice -= 1;
        mark = (char) (player % 2 ? 'X' : 'O');

        assert(choice >= 0);
        assert(choice < 9);

        if (playboard[choice] != 'X' && playboard[choice] != 'O') {
            playboard[choice] = mark;
            board(playboard);
        } else {
            printf("Invalid move!\n");
            player--;
        }
    } while (getwinner(player - 1, playboard));

    return EXIT_SUCCESS;
}


int getwinner(int player, char playboard[]) {
    int i;
    for (i = 0; i < 9; i += 3) {
        if (((playboard[i] == playboard[i + 1]) && (playboard[i + 1] == playboard[i + 2])) ||
            ((playboard[i % 4] == playboard[(i % 4) + 3]) &&
             (playboard[(i % 4) + 3] == (playboard[(i % 4) + 6])))) {
            printf("==>\aPlayer %d win ", player % 2 + 1);
            return 0;
        }
    }
    if (((playboard[0] == playboard[4]) && (playboard[4] == playboard[8]) )
        || ((playboard[2] == playboard[4]) && (playboard[4] == playboard[6]))) {
        printf("==>\aPlayer %d win ", player % 2 + 1);
        return 0;
    }
    if (player >= 8) {
        printf("==>\aGame draw");
        return 0;
    }
    return 1;
}


void board(char playboard[]) {
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", playboard[0], playboard[1], playboard[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", playboard[3], playboard[4], playboard[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", playboard[6], playboard[7], playboard[8]);

    printf("     |     |     \n\n");
}