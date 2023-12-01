
//SE 185: Final Project Template//
/////////////////////////
/*
Team xx (please insert your team number instead of xx)
Team member 1 "Name" | "Percentage of Contribution to The Project"
Team member 2 "Name" | "Percentage of Contribution to The Project"
Team member 3 "Name" | "Percentage of Contribution to The Project"
Team member 4 "Name" | "Percentage of Contribution to The Project"
*/
////////////////////
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


int main(){
    
	struct Player highs[10];			// Creating highscore table list
	for (int i = 1; i < 10; i++){
		highs[i].rank = i;
		highs[i].score = 0;
		strcpy(highs[i].name, "---");
	}

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
	for (int i = 1; i < 10; i++){	// printing off ranks, scores, and names
		printf("%d	%d	%s\n", highs[i].rank, highs[i].score, highs[i].name);
	}
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
	
	// \n\n\n\n\n\n\n\n\n\n		<- 10 Lines (for reference if need to copy)
	// printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	// 60 Lines (Screen Clear)

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
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			
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
		}
		// Clear board after each level
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		none_selected();
		sleep(1);

		// Prompt Screen
		printf("\n", answer);
		printf("Turn: %d\n", level);
		printf("Score: %d\nOkay, what was the order?(Use w,a,s,d)\n", score);
		scanf("%s", &input);
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
	int tempScore;
	char playerName[4] = "";
	char tempName[4] = "";

	for (int i = 1; i < 10; i++){
    	if (score > highs[i].score){
        	
			// Ask for user's name
			printf("\nWhat is your name? (Enter three capital letters) ");
			scanf("%s", &playerName);
			// Update Names / Shift names down
        	for (int j = i; j < 10; j++){
            	strcpy(tempName, highs[j].name);  	// Reserve name at rank j
            	strcpy(highs[j].name, playerName);  // Replace rank score with player's name
            	strcpy(playerName, tempName);       // Reserve the next rank's name
        	}

			// Update Score / Shift scores down
        	for (int j = i; j < 10; j++){
            	tempScore = highs[j].score;  // Reserve score at rank j
            	highs[j].score = score;      // Replace rank score with player's score
            	score = tempScore;           // Reserve the next rank's score
        	}
        	break;
    	}
	}

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

