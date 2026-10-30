#include <stdio.h>

int main() {
    int total_money = 700;
    int total_coins;
    int twenty_five_paise, fifty_paise, one_rupee;
    total_coins = total_money * 100; // converting total money to total paise

    twenty_five_paise = total_coins / (25 + 50 + 100);
    fifty_paise = twenty_five_paise;
    one_rupee = twenty_five_paise;

    printf("Number of 25 paise coins: %d\n", twenty_five_paise);
    printf("Number of 50 paise coins: %d\n", fifty_paise);
    printf("Number of 1 rupee coins: %d\n", one_rupee);

    return 0;
}