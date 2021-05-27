#include"struct.h"
#include"shuffle.h"

void shuffle(Card* const wDeck)
{
    int i, j;
    Card temp;

    for (i = 0; i <= 51; i++) {
        j = rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}