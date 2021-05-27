#include"struct.h"
#include"deal.h"

void deal(Card* const wDeck) {
    int i;
 
    for (i = 0; i < 13; i++) {
        printf("%d \t  %5s of %-8s%c", i + 1, wDeck[i].face, wDeck[i].suit, '\n');
    }

}