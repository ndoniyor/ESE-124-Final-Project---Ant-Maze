#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

//Global Variables 
extern int goldCount;
extern char maze[50][50];
extern posit a;
extern int MAX_ENERGY;

//Move Functions
void MOVE_B(){
	if(maze[a.y+1][a.x]=='@'){	//until gold
		goldCount++;	//increment gold counter 
	}
	if(maze[a.y+1][a.x]!='*')	//until wall
		a.y++;
	maze[a.y][a.x]='x';
	energy(3);				   //uses 3 energy for the function
}

void MOVE_F(){
	if(maze[a.y-1][a.x]=='@'){	//until gold
		goldCount++;	//increment gold counter
	}
	if(maze[a.y-1][a.x]!='*')	//until wall
		a.y--;
	maze[a.y][a.x]='x';
	energy(3);					//uses 3 energy for the function 
}

void MOVE_L(){
	if(maze[a.y][a.x-1]=='@'){	//until gold 
		goldCount++;	//increment gold counter 
	}
	if(maze[a.y][a.x-1]!='*')	//until wall 
		a.x--;
	maze[a.y][a.x]='x';
	energy(3);					//uses 3 energy for the function 
}

void MOVE_R(){
	if(maze[a.y][a.x+1]=='@'){	//until gold 
		goldCount++;	//increment gold counter 
	}
	if(maze[a.y][a.x+1]!='*')	//until wall 
		a.x++;
	maze[a.y][a.x]='x';
	energy(3);					//uses 3 energy 
}

void Mark(){
	push(a);
	maze[a.y][a.x]='p';		//placing a p wherever a place is marked
	energy(3);				//uses 3 energy
}

void BJPI(posit b){
	switch(b.y){
		case 1://Left
			if(maze[a.y][a.x-b.x]=='@'){
				goldCount++;
			}
			a.x=a.x-b.x;
			break;
		case 2://Right
			printf("%d",b.x);
			if(maze[a.y][a.x+b.x]=='@'){
				goldCount++;
			}
			a.x=a.x+b.x;
			break;
		case 3://Up
			if(maze[a.y-b.x][a.x]=='@'){
				goldCount++;
			}
			a.y=a.y-b.x;
			break;
		case 4://Down
			if(maze[a.y+b.x][a.x]=='@'){
				goldCount++;
		}
			a.y=a.y+b.x;
			break;
	}
	maze[a.y][a.x]='j';
	energy(5);	//consumes 5 energy 
}

void CJPI(posit b){
	printf("%d %d\n",b.x,b.y);
	switch(b.y){
		case 1: //Left
			if(maze[a.y][a.x-1]=='@')
				goldCount++;
			a.x=a.x-1;
			break;
		case 2: //Right
			if(maze[a.y][a.x+1]=='@')
				goldCount++;
			a.x=a.x+1;
			break;
		case 3:	//Up
			if(maze[a.y-1][a.x]=='@')
				goldCount++;
			a.y=a.y-1;
			break;
		case 4: //Down
			if(maze[a.y+1][a.x]=='@')
				goldCount++;
			a.y=a.y+1;
			break;
	}
	maze[a.y][a.x]='x';
	energy(3);	//consumes 3 energy 
}

void backtrack(posit aux){
	a.x=aux.x;
	a.y=aux.y;
	maze[a.y][a.x]='o';
}

void energy(int c){
	MAX_ENERGY -= c;	//consuming the indicated amount of energy directed by the functions
}


	
