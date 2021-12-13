//
// Created by cslco on 11/23/2021.
//

#include <stdio.h>
#include "moneyFunctions.h"

void dollar_euro(int amount){
    // 1 dollar = .89 Euro
    int i;
    double k = 0;
    for(i = 0; i < amount; i++){
        k = k + .89;
    }
    printf("%d US Dollars is %.2f Euros\n", amount, k);
}

void convert_money(){
    int i, j, m, k = 1;
    printf("List of available currencies:\n"
           "1. US Dollar\n"
           "2. Euro\n"
           "3. Pound\n");
    printf("Enter the number of the currency you want to convert from\n");
    scanf("%d", &i);
    printf("Enter the number of the currency you want to convert to\n");
    scanf("%d", &j);
    printf("How much would you like to convert?\n");
    scanf("%d", &m);

    switch(i) {
        case 1: i == 1 && j == 2;
            dollar_euro(m);
            break;
        default: printf("Please select an option on the list.\n");
        }

}

int display_menu(){
    int i;
    double x = -1269.45630002;
    double y =  269.000568003;
    double k = 0;
    for(i = 0; i < 150; i++){
        k = k + 1.00 - .11;
    }

    while(1) {
        printf("\n---------------------------------------------------\n"
               "              Money Converter System\n"
               "1. Convert Money\n"
               "2. Exit Client\n"
               "---------------------------------------------------\n\n"
               "Enter your choice: ");
        scanf("%d", &i);

        switch(i) {
            case 1: convert_money();
                break;
            case 2: return 0;
            case 3: printf("%.2f\n", k);
            default: printf("Please select an option on the list.");
        }
    }
}
