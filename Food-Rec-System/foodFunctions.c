#include <stdio.h>
#include "foodFunctions.h"
// test 

void display_dishes(){
    printf("\nBreakfast: Yogurt, Bagels, Eggs, Stuffed Hasbrowns, Oatmeal\n"
           "Lunch: Hot Dogs, Burritos, Chowder, Potential Leftovers\n"
           "Dinner: Chicken with rice or noodles, Fish and Chips, Swipe Somewhere\n"
           "Snacks: Brookies, Apple Pies, Belvitas, Ritz, Nutrigrain Bars\n");
}

void display_possibilities(){
    char food[][20] = {"Yogurt", "Bagels", "Eggs", "Stuffed Hashbrowns", "Oatmeal",                                                                  // Breakfast
                    "Hot Dogs", "Burritos", "Leftovers", "Chowder",                                                                                  // Lunch
                    "Chicken and rice", "Chicken and noodles", "Chicken,noodles,eggs", "Chicken, rice, eggs", "Fish and Chips",                      // Dinner
                    "Brookies", "Apple Pies", "Belvitas", "Ritz\n"};                                                                                 // Snacks
    int i;
    char input[1000];
    //char possibilities[];
    printf("Input the ingredients you have\n");
    //scanf("%[^\\n]s", input);

    // Next you want to search through food array to see if any of the substrings of input match with any of the food in food array and print out matches
//    for(i = 0; i < sizeof(input); i++){
//
//    }
    printf("%s", &input[0]);
}

int display_menu(){
    int i;

    while(1) {
        printf("\n---------------------------------------------------\n"
               "            Food Recommendation System\n"
               "1. See dishes\n"
               "2. Input Ingredients\n"
               "3. Exit Client\n"
               "---------------------------------------------------\n\n"
               "Enter your choice: ");
        scanf("%d", &i);

        switch(i) {
            case 1: display_dishes();
                break;
            case 2: display_possibilities();
                break;
            case 3:
                return 0;
            default: printf("Please select an option on the list.");
        }
    }
}