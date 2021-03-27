#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <conio.h>
int j = 1;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//char player_one[10], player_two[10], name[10];
struct player_info{
  char player_one[10];
  char player_two[10];
  char name[10];
}info;

int CheckWin();
void Board();
int menu_program();
int main()
{
    int player = 1, i, choice;
    int menu_choice, GoBackChoice;
    char mark;

    time_t now;
    time(&now);
    FILE *fwin;
    fwin = fopen("/Users/abhishek/Downloads/tic tac toe/winner.txt", "a+");

    system("clear");
    menu_program();
    printf("\n\t\t>> Enter Your Choice: "); scanf("%d", &menu_choice);

    switch (menu_choice) {
      case 1:
        system("clear");
        printf("\n\n\t\t>> Enter First Player Name: "); scanf("%s", info.player_one);
        printf("\n\t\t>> Enter Second Player Name: "); scanf("%s", info.player_two);
        do
        {
            Board();
            //player = (player % 2 != 0) ? 1 : 2;
            if(player % 2 != 0){
              player = 1;
              strcpy(info.name, info.player_one);
              //strcpy(mark, mark_one);
              //strcpy(mark, mark_player_one);
            }
            else{
              player = 2;
              strcpy(info.name, info.player_two);
              //strcpy(mark, mark_two);
              //strcpy(mark, mark_player_two);
            }
            //printf("Player %d %s, Enter a Number:  ", player, name);
            printf("\t\t%s\'s turn, Enter a Number:  ",info.name);
            scanf("%d", &choice);


            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[1] == '1')
                square[1] = mark;

            else if (choice == 2 && square[2] == '2')
                square[2] = mark;

            else if (choice == 3 && square[3] == '3')
                square[3] = mark;

            else if (choice == 4 && square[4] == '4')
                square[4] = mark;

            else if (choice == 5 && square[5] == '5')
                square[5] = mark;

            else if (choice == 6 && square[6] == '6')
                square[6] = mark;

            else if (choice == 7 && square[7] == '7')
                square[7] = mark;

            else if (choice == 8 && square[8] == '8')
                square[8] = mark;

            else if (choice == 9 && square[9] == '9')
                square[9] = mark;

            else
            {
                printf("Invalid move, Try again");
                player--;
                //getch();
            }
            i = CheckWin();
            player++;
        }while (i ==  - 1);
        Board();
        //printf("player number = %d\n", player);
        if (i == 1){
          //printf("==>\aPlayer %d %s wins\n\n\n", --player, name);
          fprintf(fwin, " Name = %s  \t  Time = %s", info.name, ctime(&now));
          printf("\t\t\t===>\a %s wins\n\n\n", info.name);
          fclose(fwin);
          /*
          int again;
          printf("press 1 to return to menu\n");
          printf("Press any other key to exit");
          printf("enter your choice: ");
          scanf("%d", &again);

          if(again == 1){
              return main();
          }
          else{
            exit(0);
          }
          */
        }
        else{
          fprintf(fwin, "Draw Between %s and %s\tTime = %s",info.player_one, info.player_two, ctime(&now));
          printf("\t\t\t===>\a Game Draw \n\n\n");
          fclose(fwin);
        }
      break;

      case 2:

        system("clear");

        printf("\t\t\t****************************\n");
        printf("\t\t\t**    GAMEPLAY HISTORY    **\n");
        printf("\t\t\t****************************\n");
        char ch[100];
        fwin = fopen("/Users/abhishek/Downloads/tic tac toe/winner.txt", "r");
        /*
        if(fscanf(fwin,"%c",&ch)==EOF)
        {
          printf("\n\t\tNo GamePlay History");
        }
        */
        if(fwin == NULL){
          printf("NO FILE DETECTED");
        }
        if(getc(fwin) == EOF){
          printf("\n\t\t\t << EMPTY REOCRD >>");
        }
        int count = 1;
        printf("\n");
        while(fgets(ch, sizeof(ch), fwin) != NULL)
        {
            printf("\t\t");
            printf("%d. ", count);
            printf("%s ", ch);
            count++;
            fflush(stdin);
        }
        fclose(fwin);


        printf("\n\n\t\t>> Press 0 To Go To Main Menu \n");
        printf("\n\t\t>> Press 1 To Clear The History And \n");
        printf("\t\t   Return Back To Main Menu\n");

        while (j==1) {
          printf("\n\t\t>> Enter Your Choice: "); scanf("%d", &GoBackChoice);
          if(GoBackChoice == 0){
            return main();
          }

          else if(GoBackChoice == 1){
            fwin = remove("/Users/abhishek/Downloads/tic tac toe/winner.txt");
            // fwin = fopen("/Users/abhishek/Downloads/tic tac toe/winner.txt","w");
            fclose(fwin);
            return main();
          }

        }

      break;

      case 3:
        system("clear");
        printf("\n\t\t*****************************************\n");
        printf("\t\t****    RULES FOR TIC TAC TOE GAME   ****\n");
        printf("\t\t*****************************************\n");


        printf("\n\t********************************************************\n");
        printf("\t** Rule 1: Player 1 uses 'X' and Player 2 uses 'O'    **\n");
        printf("\t** Rule 2: Players must enter the digits according    **\n");
        printf("\t** \t   to the Grid BOARD                          **\n");
        printf("\t** Rule 3: First three matches of 'X' or '0' leads    **\n");
        printf("\t** \t   to WIN the GAME                            **\n");
        printf("\t**\t    GOOD LUCK PLAYERS!!!!                     **\n");
        printf("\t********************************************************\n");


        printf("\n\t\t>> Press 0 To Go To Main Menu \n");
        printf("\n\t\t>> Press 1 To Exit The Game \n");

        while (j==1) {
          printf("\n\t\t>> Enter Your Choice: "); scanf("%d", &GoBackChoice);
          if(GoBackChoice == 0){
            return main();
          }
          else if(GoBackChoice == 1){
            exit(0);
          }
          system("clear");
          printf("\n\t\t*****************************************\n");
          printf("\t\t****    RULES FOR TIC TAC TOE GAME   ****\n");
          printf("\t\t*****************************************\n");
          printf("\n\t\t>> Press 0 To Go To Main Menu \n");
          printf("\n\t\t>> Press 1 To Exit The Game \n");
          printf("\n\t\t>> ERROR: Invalid Input!! Try Again");
        }
      break;

      case 4:
      exit(0);

      default:
      printf("Invalid Number. Try again");
      return main();

    }


}

int CheckWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;


    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    else
        return  - 1;
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/

void Board()
{
    system("clear");
    printf("\n\t\t\t    Tic Tac Toe\n\n");
    printf("\t\tPlayer 1 %s (X)  -  Player 2 %s (O)\n\n\n", info.player_one, info.player_two);

    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("\t\t\t     |     |     \n\n");
}

int menu_program()
{

  printf("\n\n\n\n\t\t*****************************************\n");
  printf("\t\t****                                 ****\n");
  printf("\t\t**** WELCOME TO THE TIC TAC TOE GAME ****\n");
  printf("\t\t****                                 ****\n");
  printf("\t\t*****************************************\n");

  printf("\n\n\t\t>> Press 1 To Enter The Game\n");
  printf("\n\t\t>> Press 2 To Get The Game History\n");
  printf("\n\t\t>> Press 3 To Rules Of The Game \n");
  printf("\n\t\t>> Press 4 To Exit The Game \n");

}
