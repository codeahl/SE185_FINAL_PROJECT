//SE 185: Final Project
/////////////////////////
/*
Team xx (I do not believe we were given a team #)
Team member 1 "Connor Deahl" | "~33%"
Team member 2 "Ryan Horsey" | "~33%"
Team member 3 "Carter Ohl" | "~33%"
*/
////////////////////
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//////////////////////
//Struct Definition//
////////////////////

struct Player {
	int rank;
	int score;
	char name[4];
};

/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//them below the main function////
/////////////////////////////////
void tri_selected();
void cir_selected();
void x_selected();
void sqr_selected();
void print_tri();
void print_sqr_cir();
void print_x();
void print_blank(int num);
void none_selected();
void post_round_countdown();
void print_highscores(struct Player highscore[]);
void write_to_file(struct Player highscore[], int score, FILE* file);
void new_screen();


int main(){
    
	FILE* file;


	struct Player highscore[10];
	
	file = fopen("highScores.txt", "r");
	fscanf(file, "%2d %3s , %2d %3s , %2d %3s , %2d %3s , %2d %3s , %2d %3s , %2d %3s , %2d %3s , %2d %3s .", 
	&highscore[0].score, highscore[0].name, &highscore[1].score, highscore[1].name, &highscore[2].score, highscore[2].name, &highscore[3].score, highscore[3].name, &highscore[4].score, highscore[4].name, &highscore[5].score, highscore[5].name,
	&highscore[6].score, highscore[6].name, &highscore[7].score, highscore[7].name, &highscore[8].score, highscore[8].name);

	fclose(file);


	char wantToPlay;

	// Uncomment for visualizing all of the selected shapes. 

	// tri_selected();
    // printf("\n\n\n");
    // sqr_selected();
    // printf("\n\n\n");
    // cir_selected();
    // printf("\n\n\n");
    // x_selected();

	// Start
	printf("Welcome to the Memory game.\n");		// USE FULLSCREEN CYGWIN
	printf("To start the game, press \"g\".\n");
	printf("In the game, various shapes will appear with a square around it.\n");
	printf("You must remember the shapes that are boxed and repeat the order.\n");
	printf("Use w for up, s for down, a for left, and d for right.\n");

	gameLoop:; // Look at end of main() for reference

	printf("\nHighscore Table:\n");
	printf("Rank	Score	Name\n"); // seperated with tab characters
	print_highscores(highscore);
	printf("What would you like to do?\n");
	printf("\"g\" for a game.\n");
	scanf("\n%c", &wantToPlay);	// scan user input
	if (wantToPlay != 'g'){
		printf("See you next time!");	// user doesn't input "g" and ends game
		return 0;
	}
	usleep(500000);
	printf("3...\n");
	sleep(1);
	printf("2...\n");
	sleep(1);
	printf("1...\n");
	sleep(1);
	

	//<-------------- Game Loop----------------->

	int levelShapes[99]; // Array to keep track of the order of the shapes for the current game
	srand((int)time(NULL));

	char answer[99] = "";

	char addToAnswer;
	// Assign levels 1-100 their shape indexed 0-99
	for (int i = 0; i < 99; i++){
		levelShapes[i] = rand()%4; 
	}

	int x = 1;
	int level = 1;
	int score = 0;
	char input[99];

	while (x == 1){

		answer[0] = '\0'; // Clear answer for each level

		// Loop for each level
		for(int i = 0; i < level; i++){
			// Print level shape
			new_screen();
			
			switch (levelShapes[i]){
				case 0: tri_selected();
					addToAnswer = 'w';
					strncat(answer, &addToAnswer, 1);
					break;
				case 1: sqr_selected();
					addToAnswer = 'a';
					strncat(answer, &addToAnswer, 1);
					break;
				case 2: cir_selected();
					addToAnswer = 'd';
					strncat(answer, &addToAnswer, 1);
					break;
				case 3: x_selected();
					addToAnswer = 's';
					strncat(answer, &addToAnswer, 1);
					break;
			}
			sleep(1);
			new_screen();
			none_selected();
			usleep(250000);
		}
		// Clear board after each level
		new_screen();
		none_selected();
		sleep(1);

		// Prompt Screen
		printf("\n");

		int isWASD;
		while(1) {
			isWASD = 1;
			printf("Turn: %d\n", level);
			printf("Score: %d\nOkay, what was the order?(Use w,a,s,d)\n", score);
			scanf("%s", &input);
			for(int i = 0; i < strlen(input); i++) {
				if(input[i] != 119 && input[i] != 97 && input[i] != 115 && input[i] != 100) {
					isWASD = 0;
					break;
				}
			}
			if(strlen(input) == level && isWASD) {
				break;
			}
			else {
				printf("Please enter the correct amount of characters, only using only lowercase \"wasd\"\n\n");
			}
		}
		if (strncmp(input, answer, level) == 0){
			level++;
			score++;
		}
		else {x = 0;} // End game	
	}
		sleep(1);

	// Post-game screen goes here
	printf("\nGame Over!\n");

	// Highscore?
	write_to_file(highscore, score, file);

	// Play again?
	char playAgain;
	printf("\nWould you like to play again? (y/n)\n");
	scanf("\n%c", &playAgain);
	if (playAgain == 'y'){ goto gameLoop; }

    return 0;
}

// ----------------FUNCTIONS----------------- //

void print_blank(int num) {
    while(num != 0){
		printf(" ");
		--num;
	}
}

//Shape printing functions until after "x_selected()"
void print_tri() {
    int i, j;
    for(i = 1; i <= 6;  i++){
		for(j = 1; j <= (6 - i)+13; j++){
			printf(" ");
		}
		for(j = 1; j <= ((2*i)-1); j++){
			printf("^");
		}
        //printing an increasing, odd # of ^'s per line
		
		printf("\n");
	}
}

void print_sqr_cir() {
    printf("\n   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	print_blank(20);
	printf("OO");
	printf("\n");	
	
	printf("   H     H");
	print_blank(19);
	printf("O  O");
	printf("\n");
	printf("   H     H");
	print_blank(18);
	printf("O    O");
	printf("\n");
	
	printf("   H     H");
	print_blank(18);
	printf("O    O");
	printf("\n");
	
	printf("   H     H");
	print_blank(18);
	printf("O    O");
	printf("\n");
	
	printf("   H     H");
	print_blank(19);
	printf("O  O");
	printf("\n");

	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
    print_blank(20);
    printf("OO\n");
}

void print_x(){
	printf("\n");
	print_blank(15);
	printf("X     X\n");
	print_blank(16);
	printf("X   X\n");
	print_blank(17);
	printf("X X\n");
	print_blank(18);
	printf("X\n");
	print_blank(17);
	printf("X X\n");
	print_blank(16);
	printf("X   X\n");
	print_blank(15);
	printf("X     X\n");
	
}

void tri_selected() {
    int i, j;

    print_blank(11);
    printf(".................\n");
    print_blank(11);
	printf(".");
	print_blank(15);
	printf(".\n");

    for(i = 1; i <= 6;  i++){
		for(j = 1; j <= (6-i)+13; j++){
			if(j == 12){
				printf(".");
			}
			printf(" ");
		}
		
		for(j = 1; j <= ((2*i)-1); j++){
			printf("^");
		}
		
        print_blank(8-i);
        printf(".");
		printf("\n");
	}
	
	print_blank(11);
	printf(".................\n");

    print_sqr_cir();
    printf("\n");
    print_x();
}

void sqr_selected() {
    print_tri();
	printf(" ...........\n");
	
	printf(" .");
	print_blank(9);
	printf(".\n");
	
	printf(" . ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	printf(" .");

	print_blank(18);
	printf("OO");
	printf("\n");

	printf(" . H     H");
	printf(" .");
	print_blank(17);
	printf("O  O");
	printf("\n");
	printf(" . H     H");
	printf(" .");
	print_blank(16);
	printf("O    O");
	printf("\n");
	printf(" . H     H");
	printf(" .");
	print_blank(16);
	printf("O    O");
	printf("\n");
	printf(" . H     H");
	printf(" .");
	print_blank(16);
	printf("O    O");
	printf("\n");
	printf(" . H     H");
	printf(" .");
	print_blank(17);
	printf("O  O");
	printf("\n");
	
	printf(" . ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	printf(" .");
    print_blank(18);
	printf("OO");
	printf("\n");
	printf(" .");
	print_blank(9);
	printf(".\n");
	
	printf(" ...........");
    print_x();
}

void cir_selected() {
    print_tri();
    print_blank(25);

	printf("............\n");
	print_blank(25);
	printf(".");
	
	print_blank(10);
	printf(".\n");

	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}

	print_blank(15);
	printf(".    OO    .");
	printf("\n");	
	
	printf("   H     H");
	print_blank(15);
	printf(".   O  O   .");
	printf("\n");
	
	printf("   H     H");
	print_blank(15);
	printf(".  O    O  .");
	printf("\n");
	printf("   H     H");
	print_blank(15);
	printf(".  O    O  .");
	printf("\n");
	printf("   H     H");
	print_blank(15);
	printf(".  O    O  .");
	printf("\n");
	printf("   H     H");
	print_blank(15);
	printf(".   O  O   .");
	printf("\n");
	
	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	print_blank(15);
	printf(".    OO    .\n");
    print_blank(25);
    printf(".");
    print_blank(10);
    printf(".\n");
	
	print_blank(25);
	printf("............");
    print_x();
}

void x_selected() {
    print_tri();
    print_sqr_cir();
    print_blank(12);
	printf(".............\n");
	print_blank(12);
	printf(".");
	print_blank(11);
	printf(".\n");
    
	print_blank(12);
	printf(".  X     X  .\n");
	print_blank(12);
	printf(".   X   X   .\n");
	print_blank(12);
	printf(".    X X    .\n");
	print_blank(12);
	printf(".     X     .\n");
	print_blank(12);
	printf(".    X X    .\n");
	print_blank(12);
	printf(".   X   X   .\n");
	print_blank(12);
	printf(".  X     X  .\n");

	print_blank(12);
	printf(".");
	print_blank(11);
	printf(".\n");

	print_blank(12);
	printf(".............\n");
}




void none_selected() {
    print_tri();
    print_sqr_cir();
    print_x();
}

void post_round_countdown(){
	printf("Good job, get ready for the next round.\n");
	sleep(1);
	printf("3...\n");
	sleep(1);
	printf("2...\n");
	sleep(1);
	printf("1...\n");
	sleep(1);
}

void print_highscores(struct Player highscore[]) {
	for(int i = 0, j = 1; i < 9; i++, j++){
			printf(" %d	%d	%s\n", j, highscore[i].score, highscore[i].name);
		}
}

void write_to_file(struct Player highscore[], int score, FILE* file) {
	int rank = 9;
	for(int i = 8; i >= 0; i--) {
		if(score > highscore[i].score) {
			rank--;
		}
	}

	if(rank < 9) {
		for (int i = 8; i > rank; i--) {
    	highscore[i] = highscore[i-1];
		}

		printf("Congratulations, you made it on the highscore table\n");
		char tempName[4];
		int isAlpha;
		while(1) {
			isAlpha = 1;
			printf("Please enter your name (Only 3 captial letters): \n");
			scanf("%s", tempName);
			for(int i = 0; i < strlen(tempName); i++) {
				if(!(tempName[i] >= 65 && tempName[i] <= 90)) {//Checks for a capital alphabet letter
					isAlpha = 0;
					break;
				}
			}
			if(isAlpha && strlen(tempName) == 3) {
				break;
			}
			else {
				printf("Enter only 3 capital alphabet letters\n\n");
			}

		}


		strcpy(highscore[rank].name, tempName);
		highscore[rank].score = score;
	}
	else{
		return;
	}

	file = fopen("highScores.txt", "w");

	fprintf(file, "%d %s , %d %s , %d %s , %d %s , %d %s , %d %s , %d %s , %d %s , %d %s .", 
	highscore[0].score, highscore[0].name, highscore[1].score, highscore[1].name, highscore[2].score, highscore[2].name, highscore[3].score, highscore[3].name, highscore[4].score, highscore[4].name, highscore[5].score, highscore[5].name,
	highscore[6].score, highscore[6].name, highscore[7].score, highscore[7].name, highscore[8].score, highscore[8].name);

	fclose(file);
}

//Used to clear the screen for a new shape configuration
void new_screen() {
	for (int i = 0; i < 100; i++) {
		printf("\n");
	}
}

