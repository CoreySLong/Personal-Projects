//////////////////////////////////////////////////////////////////////////////////////
// File: games.c
// Description: Code for the various games able to be played in game project
// Authors: Corey Long and Abdul Umar
// Start Date: 11/11/21
// Notes:
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "games.h"

void tic_tac_toe(){
    int i;
    char ch;

    printf("\n************ Welcome to \"Tic-Tac-Toe\" ************\n"
           "Would you like to be X or O?\n");
    scanf("%c", &ch);
    if(ch != NULL)
        printf("Would you like to go first(1) or second(2)?\n");
    scanf("%d", &i);

    printf("1   2   3\n"            // Numbering the columns
           "1\n2\n3\n");                   // Numbering the rows
    //return 0;
}

int one_to_ten(){
    int i;

    while(1){
        printf("\n************ Welcome to \"Guess A Number\" ************\n"
               "     Guess a number 1-10 or 11 to quit the game: ");
        scanf("%d", &i);

        switch(i){
            case 1: printf("Good job!\n");
                sleep(1);
                printf("SIKE I LIED\n");
                break;
            case 2: printf("Maybe try and guess 1 next time.\n");
                break;
            case 3: printf("I almost made this the number, but nope, you're wrong.\n");
                break;
            case 4: printf("Unfortunately not my friend.\n");
                break;
            case 5: printf("Did you really think it would be the number in the middle?? You're better than that.\n");
                break;
            case 6: printf("Nah, six is a weird number to me for some reason.\n");
                break;
            case 7: printf("I guess lucky number seven isn't so lucky.\n");
                break;
            case 8: printf("Eight is a pretty cool number but this is incorrect unfortunately.\n");
                break;
            case 9: printf("Noooooope, incorrect my friend.\n");
                break;
            case 10: printf("You are correct!\n");
                return 0;
            case 11:
                return 0;
            default: printf("Please enter a number 1-10 or 11 to quit the game \n\n");
        }
    }
}

int display_game_menu(){
    int i;   // used to scan the number user inputs

    while(1){
        printf("---------------------------------------------------\n"
               "      Welcome to Corey's Gaming Extravaganza!\n\n"
               "Type the number of the game you would like to play.\n"
               "1. Guess a number 1-10\n"
               "2. Tic-Tac_Toe\n"
               "3. Exit\n"
               "---------------------------------------------------\n"
               "Enter your choice:");
        scanf("%d", &i);

        switch(i){
            case 1: one_to_ten();
                break;
            case 2: tic_tac_toe();
                break;
            case 3: printf("Exiting the game client, goodbye!\n");
                return 0;
            default: printf("Please enter an option on the list\n\n");

        }
    }
}
