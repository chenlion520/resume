#include"struct.h"
#include"deal2.h"

void deal2(Card* const wDeck,int a) {
    int i;
    int k = 1;
    a = (a - 1) * 13;
    for (i = a; i < a+13; i++,k++) {
        printf("%d \t %5s of %-8s%c", k, wDeck[i].face, wDeck[i].suit, '\n');
    }

}