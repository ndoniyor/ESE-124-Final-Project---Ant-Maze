/*
ESE 124 Course Project
Spring 2021
Michael: The Greedy Ant 

By: 
Ethan Garcia
Doniyor Nimatullo
Aditya Saha
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "checkloc1.h"
//FSM states
#define IDLE 0
#define MOVEF 1
#define MOVEB 2
#define MOVEL 3
#define MOVER 4
#define CW_F 5
#define CW_B 6
#define CW_L 7
#define CW_R 8
#define BJ 9
#define CJ 10
#define BACK 11
#define CLEAR 12
#define PEEK 13
#define MARK 14
#define END 15

int MAX_ENERGY = 0;
int goldCount=0;
char maze[50][50];
int RC=0;
posit a;

int main(int argc, char *argv[]) {
	//initilizing variables
	posit b;
	FILE *input;
	FILE *intel;
	FILE *results;
	input = fopen("Maze1.txt","r");
	intel = fopen("intel.txt","r");
	results = fopen("results.txt","w");
	int state = IDLE;
	char bigMaze[2500];
	int i=0,j,k=0;
	char c;
	int t=0;
	char n[32];
	
	while(1){
		c = fgetc ( input ) ; // reading the file
	    if (c == EOF)
	    	break ;
		if(c==' '||c=='*'||c=='@'||c=='x'){	// ' ' empty space, '*' wall, '@' pots of gold, 'x' route of the ant
			bigMaze[i]=c;
			i++;
		}
	}
	//Finding entry point of the maze by finding an open space on all 4 corners of the maze 
	RC=sqrt(i);
	for(i=0;i<RC;i++){
		for(j=0;j<RC;j++){
			maze[i][j]=bigMaze[k];
			k++;
		}
	}
	for(i=0;i<RC;i++){
		for(j=0;j<RC;j++){
			fprintf(results,"%c",maze[i][j]);
			printf("%c",maze[i][j]);
		}
		fprintf(results,"\n");
		printf("\n");
	}
	for(i=0;i<RC;i++){
		if(maze[0][i]==' '){
			a.x=i;
			a.y=0;	
		}
	}
	for(i=0;i<RC;i++){
		if(maze[RC-1][i]==' '){
			a.x=i;
			a.y=RC-1;	
		}
	}
	for(i=0;i<RC;i++){
		if(maze[i][0]==' '){
			a.x=0;
			a.y=i;	
		}
	}
	for(i=0;i<RC;i++){
		if(maze[i][RC-1]==' '){
			a.x=RC-1;
			a.y=i;	
		}
	}
	fscanf(intel,"%d\n",&MAX_ENERGY); //added this to make max energy based on intel file input
	printf("Energy: %d\n", MAX_ENERGY);	//printing the total available energy to be used
	
	//Reading the intelligence file
	while(fscanf(intel, "%s %d\n",&n, &t)!=EOF){
		maze[a.y][a.x]='x';
		fprintf(results,"(%d,%d)\n",a.x,a.y); //prints coordinates at each iteration into results file
		printf("n is %s t is %d\n",n,t);
		
		if(strcmp(n,"MOVE_F")==0){
			state = MOVEF;
		}
		if(strcmp(n,"MOVE_B")==0){
			state = MOVEB;
		}
		if(strcmp(n,"MOVE_L")==0){
			state = MOVEL;
		}
		if(strcmp(n,"MOVE_R")==0){
			state = MOVER;
		}
		if(strcmp(n,"CWF")==0){
			state = CW_F;
		}
		if(strcmp(n,"CWB")==0){
			state = CW_B;
		}
		if(strcmp(n,"CWL")==0){
			state = CW_L;
		}
		if(strcmp(n,"CWR")==0){
			state = CW_R;
		}
		if(strcmp(n,"BJPI")==0){
			state = BJ;
		}
		if(strcmp(n,"CJPI")==0){
			state = CJ;
		}
		if(strcmp(n,"BACKTRACK")==0){
			state = BACK;
		}
		if(strcmp(n,"CLEAR")==0){
			state = CLEAR;
		}
		if(strcmp(n,"PEEK")==0){
			state = PEEK;
		}
		if(strcmp(n,"MARK")==0){ 
			state= MARK;
		}
		if(strcmp(n,"END")==0){
			state = END;
		}
		//Finite State Machine
		switch(state){
			case IDLE:
				break;
			case MOVEF:
				for(i=0;i<t;i++){
					MOVE_F();
				}
				break;
			case MOVEB:
				for(i=0;i<t;i++){
					MOVE_B();
				}
				break;
			case MOVEL:
				for(i=0;i<t;i++){
					MOVE_L();
				}
				break;
			case MOVER:
				for(i=0;i<t;i++){
					MOVE_R();
				}
				break;
			case CW_F:
				b=CWF(a);
				break;
			case CW_B:
				b=CWB(a);
				break;
			case CW_L:
				b=CWL(a);
				break;
			case CW_R:
				b=CWR(a);
				break;
			case BJ:
				BJPI(b);
				break;
			case CJ:
				for(i=0;i<t;i++){
					CJPI(b);
				}
				break;
			case BACK:
				for(i=0;i<t;i++){
					backtrack(pop());
				}
				break;
			case CLEAR:
				clear();
				break;
			case PEEK:
				peek();
				break;
			case MARK:
				Mark();
				break;
			case END:
				break;
		}
		if(MAX_ENERGY<=0){
			printf("OUT OF ENERGY - GAME OVER\n"); //When the ant runs out of energy 
			state = END;	//end program 
			MAX_ENERGY=0;
			break;
		}
	}
	maze[a.y][a.x] ='L'; //marks final spot
	for(i=0;i<RC;i++){
		for(j=0;j<RC;j++){
			printf("%c",maze[i][j]);
			fprintf(results,"%c",maze[i][j]); //prints final maze results 
		}
		fprintf(results,"\n");
		printf("\n");
	}
	fprintf(results,"Gold: %d\nEnergy count: %d\n",goldCount,MAX_ENERGY); //prints the total gold collected and total energy left
}
