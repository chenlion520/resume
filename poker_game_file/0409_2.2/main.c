#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"struct.h"
#include"deal.h"
#include"deal2.h"
#include"fillDeck.h"
#include"shuffle.h"
#include"change_card1.h"
#include"change_card2.h"
#include"change.h"
#include"sort.h"


int sort1(Card* const , int(*)[6], int ,int);
int main() {
	int order;
	int maxf, maxm, maxl,max;
	int people= 0;
	int changenum;
	Card deck[52];
	int last[4][6] = {0}, mid[4][6] = { 0 }, first[4][6] = { 0 };
	const char* face[] = { "Ace", "Deuce", "Three",
						   "Four", "Five",
						   "Six", "Seven", "Eight",
						   "Nine", "Ten",
						   "Jack", "Queen", "King" };

	const char* suit[] = { "Clubs" , "Diamonds", "Hearts", "Spades" };			////////////////////
	srand(time(NULL));
	fillDeck(deck, face, suit);																		// 設牌初始值
	shuffle(deck);	// 洗牌
	printf("menu :\n");
	printf("按(1)開始:\n按(5)結束遊戲:\n");
	scanf_s("%d", &order);
	while (order != 5) {
		int flagf = -1, flagm = -1, flagl = -1;
		int score[4] = {0};
		int samef[4] = { 0 }, samem[4] = {0},  samel[4] = { 0 };
		switch (order) {
			
		case 1:
			shuffle(deck);
			printf("請選擇遊玩人數2人或4人\n");
			scanf_s("%d", &people);
			if (people == 4) {
				int change[4][3] = { 0 };
				printf("請選擇換牌順序\n 1.順時鐘(1-->2-->3-->4-->1)\n 2.逆時鐘(4-->3-->2-->1-->4)\n ");
				scanf_s("%d",&changenum);
				//printf("changenum=%d", changenum);
				switch (changenum) {
				case 1: //順時鐘
					for (int i = 0; i < 4; i++) {
						printf("player %d:\n", i+1);
						deal2(deck,i+1);
						while (1) {
							printf("請輸入你要換的牌的編號(1~13中挑三張):\n");
						for (int k = 0; k < 3; k++) {
							scanf_s("%d", &change[i][k]);
						}
							if (change[i][0] > 0 && change[i][0] < 14 &&
								change[i][1] > 0 && change[i][1] < 14 &&
								change[i][2] > 0 && change[i][2] < 14 &&
								change[i][0] != change[i][1] && change[i][1] != change[i][2])
								break;
						}
					}
					change_card1(deck, change);
					for (int i = 0; i < 4; i++) {
						printf("player %d:\n", i + 1);
						deal2(deck, i + 1);
					}
					break;
				case 2: //逆時鐘
					for (int i = 0; i < 4; i++) {
						printf("player %d:\n", i + 1);
						deal2(deck, i + 1);
						while (1) {
							printf("請輸入你要換的牌的編號(1~13中挑三張):\n");
							for (int k = 0; k < 3; k++) {
								scanf_s("%d", &change[i][k]);
							}
							if (change[i][0] > 0 && change[i][0] < 14 &&
								change[i][1] > 0 && change[i][1] < 14 &&
								change[i][2] > 0 && change[i][2] < 14 &&
								change[i][0] != change[i][1] && change[i][1] != change[i][2])
								break;
						}
					}
					change_card2(deck, change);
					for (int i = 0; i < 4; i++) {
						printf("player %d:\n", i + 1);
						deal2(deck, i + 1);
					}
					break;
				}
			}
			else if(people == 2) {
				int change[4][3] = { 0 };
				for (int i = 0; i < 2; i++) {
					printf("player %d:\n", i + 1);
					deal2(deck, i + 1);
					while (1) {
					printf("請輸入你要換的牌的編號(1~13中挑三張):\n");
					for (int k = 0; k < 3; k++) {
						scanf_s("%d", &change[i][k]);
					}
					if (change[i][0] > 0 && change[i][0] < 14 &&
						change[i][1] > 0 && change[i][1] < 14 &&
						change[i][2] > 0 && change[i][2] < 14 &&
						change[i][0] != change[i][1] && change[i][1] != change[i][2])
						break;
					}
				}
				change_card(deck, change);
				for (int i = 0; i < 2; i++) {
					printf("player %d:\n", i + 1);
					deal2(deck, i + 1);
				}

			}
			printf("按(1)重新開始:\n按(2)繼續下一回合:\n按(5)結束遊戲:\n");
			scanf_s("%d", &order);
			break;
		case 2:
			for (int i = 0; i < people; i++) {
				printf("player %d:\n", i + 1);
				deal2(deck, i + 1);
				printf("請選出後敦5張\n");
				for (int k = 0; k < 5; k++) {
					scanf_s("%d", &last[i][k]);
					last[i][k] = last[i][k] + 13 * i - 1;
					//printf("out last %d %d = %d\n", i, k, last[i][k]);
				}
				
				printf("請選出中敦5張\n");
				for (int k = 0; k < 5; k++) {
					scanf_s("%d", &mid[i][k]);
					mid[i][k] = mid[i][k] + 13 * i - 1;
					//printf("out last %d %d = %d\n", i, k, mid[i][k]);
				}
				printf("請選出前敦3張\n");
				for (int k = 0; k < 3; k++) {
					scanf_s("%d", &first[i][k]);
					first[i][k] = first[i][k] + 13 * i - 1;
					//printf("out last %d %d = %d\n", i, k, first[i][k]);

				}
			
				
			}
			for (int k = 0; k < people ; k++) {
				printf("第%d位玩家的後敦\n",k+1);
				last[k][5] = sort1(deck, last, 5, k);
				//printf("第%d位玩家的後敦牌為%d %d %d\n",k,k,5, last[k][5]);
			}
			for (int k = 0; k < people; k++) {
				printf("第%d位玩家的中敦\n", k+1);
				mid[k][5] = sort1(deck, mid, 5, k);
				//printf("第%d位玩家的中敦牌為%d %d %d\n", k, k, 5, mid[k][5]);
			}
			for (int k = 0; k < people; k++) {
				printf("第%d位玩家的前敦\n", k+1);
				first[k][5] = sort1(deck, first, 3, k);
				//printf("第%d位玩家的前敦牌為%d %d %d\n", k, k, 5, first[k][5]);
			}
			sort(deck, 5, people, last);
			sort(deck, 5, people, mid);
			sort(deck, 3, people, first);
			maxl = last[0][5];
			//////////////////////////////以下判斷各敦冠軍///////////////////////////
			for (int i = people - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					if (last[i][5] == last[j][5]) {
						samel[i]++;
						samel[j]++;
					}
				}
			}
			for (int i = people - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					if (mid[i][5] == mid[j][5]) {
						samem[i]++;
						samem[j]++;
					}
				}
			}
			for (int i = people - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					if (first[i][5] == first[j][5]) {
						samef[i]++;
						samef[j]++;
					}
				}
			}
			for (int i = 0; i < people; i++) {
				if (last[i][5] > maxl) {
					max = last[i][5];
				}
			}

			




			//printf("玩家%d為第一名\n",max+1);
			printf("按(1)重新開始:\n按(2)繼續下一回合:\n按(5)結束遊戲:\n");
			scanf_s("%d", &order);
			break;
		}
	}
	return 0;
}


int sort1(Card* const wdeck, int (*a)[6], int b,int c) {	
	int flag = 0;
	int total = 0, total1 = 0, total2 = 0;
	int countsuit[4] = { 0 };
	int count[14] = { 0 };
	
		//printf("後敦 %d= \n",c);
		for (int i = 0; i < b; i++) {
			//printf("in last %d %d = %d\n", c,i, a[c][i]);
			//printf("%5s of %-8s%c\n", wdeck[a[c][i]]);
			if (wdeck[a[c][i]].faceid == 0) {
				count[0] ++;
				count[13] ++;
			}
			else {
				count[wdeck[a[c][i]].faceid] ++;
			}
		}
		for (int i = 0; i < b; i++) {
			if (wdeck[a[c][i]].suit == "Clubs") {
				countsuit[0] ++;
			}
			else if (wdeck[a[c][i]].suit == "Diamonds") {
				countsuit[1] ++;
			}
			else if (wdeck[a[c][i]].suit == "Hearts") {
				countsuit[2] ++;
			}
			else if (wdeck[a[c][i]].suit == "Spades") {
				countsuit[3] ++;
			}
		}
		for (int i = 0; i < 13; i++) {
			if (count[i] == 1) {
				total++;
			}
			else if (total == 5) {
				break;
			}
			else {
				total = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (countsuit[i] == 5) {

				total1++;
			}
		}
		for (int i = 0; i < 13; i++) {
			if (count[i] == 3) {
				total2 += 1;
			}
			if (count[i] == 2) {
				total2 += 2;
			}
		}
		for (int i = 0; i < 13; i++) {
			if (count[i] == 4) {
				flag = 1;
			}
			else if (total2 == 3) {
				flag = 2;
			}
			else if (total2 == 1) {
				flag = 3;
			}
			else if (total2 == 4) {
				flag = 4;
			}
			else if (total2 == 2) {
				flag = 5;
			}
		}
		if (total1 == 1 && total == 5) {
			printf("同花順子\n");
			return 10 ;
		}
		else if (total1 == 1) {
			printf("同花\n");
			return 9;
		}
		else if (total == 5) {
			printf("順子\n");
			return 8 ;
		}
		switch (flag) {
		case 0:
			printf("散子\n");
			return 2;
			break;
		case 1:
			printf("四條\n");
			return 7;
			break ;
		case 2:
			printf("葫蘆\n");
			return 6;
			break;
		case 3:
			printf("三條\n");
			return 5;
			break;
		case 4:
			printf("二對\n");
			return 4;
			break;

		case 5:
			printf("條子\n");
			return 3;
			break;
		}
	}
