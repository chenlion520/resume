#include"struct.h"
#include"fillDeck.h"

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[])
{
    int i;

    for (i = 0; i <= 51; i++) {
        wDeck[i].faceid = i % 13; // A~A
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
        wDeck[i].num = i;

    }
}