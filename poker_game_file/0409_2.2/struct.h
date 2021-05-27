#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct card {
	const char* face;
	const char* suit;
	int num;
	int faceid;
};


typedef struct card Card;