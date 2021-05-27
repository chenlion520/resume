#include"struct.h"
#include"change_card2.h"

void change_card2(Card* const wdeck, int(*a)[3]) {
	Card tmp;
	for (int k = 0; k < 3; k++) {
		tmp = wdeck[a[0][k] + (13 * 0) - 1];
		wdeck[a[0][k] + (13 * 0) - 1] = wdeck[a[1][k] + (13 * 1) - 1];
		wdeck[a[1][k] + (13 * 1) - 1] = wdeck[a[2][k] + (13 * 2) - 1];
		wdeck[a[2][k] + (13 * 2) - 1] = wdeck[a[3][k] + (13 * 3) - 1];
		wdeck[a[3][k] + (13 * 3) - 1] = tmp;

	}
}