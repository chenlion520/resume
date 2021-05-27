#include"struct.h""
#include"sort.h"

void sort(Card* const wdeck, int a,int b, int (*c)[6]) {
	Card temp;
	for (int k = 0; k < b; k++) {
		for (int i = a - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					if (wdeck[c[k][i]].num % 13 > wdeck[c[k][j]].num % 13) {
						temp = wdeck[c[k][i]];
						wdeck[c[k][i]] = wdeck[c[k][j]];
						wdeck[c[k][j]] = temp;
					}
					else if (wdeck[c[k][i]].num % 13 == wdeck[c[k][j]].num % 13) {
						if (wdeck[c[k][i]].num / 13 > wdeck[c[k][j]].num / 13) {
							temp = wdeck[c[k][i]];
							wdeck[c[k][i]] = wdeck[c[k][j]];
							wdeck[c[k][j]] = temp;
						}
					}
				}
			}

	}	
}