#include"struct.h"
#include"change.h"

void change_card(Card* const wdeck, int(*a)[3]) {
	Card tmp;
	for (int k = 0; k < 3; k++) {
		tmp = wdeck[a[0][k] + (13 * 0) - 1];
		wdeck[a[0][k] + (13 * 0) - 1] = wdeck[a[1][k] + (13 * 1) - 1];
		wdeck[a[1][k] + (13 * 1) - 1] = tmp;

	}
}