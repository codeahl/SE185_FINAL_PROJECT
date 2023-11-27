
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
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//////////////////////
//Struct Definition//
////////////////////


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


int main(){
    tri_selected();
    printf("\n\n\n");
    sqr_selected();
    printf("\n\n\n");
    cir_selected();
    printf("\n\n\n");
    x_selected();
    return 0;

}

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

