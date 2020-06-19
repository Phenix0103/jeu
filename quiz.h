/**
* @file quiz.h
*/
#pragma once
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Question {
	char question[255];
	char reponse1[255];
	char reponse2[255];
        char reponse3[255];
} Question;

typedef struct Quiz {
	FILE *f;
	Question questions[5];
} Quiz;

const char* getQuestion(Question *t,int q);

void QUIZ_Init(Quiz *q,char* filename);

int play_enigme2(SDL_Surface *screen);

