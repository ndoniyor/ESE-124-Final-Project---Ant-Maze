#include <stdio.h>
#include "checkloc1.h"
extern char maze[50][50];
//1=left, 2=right, 3=up, 4=down	

//Check if open spaces are available in specific directions
//Tells Michael if there is an itch	
posit CWL(posit a){
	posit b;
	b.x=0;
	int i;
	i=a.x-1; //set i = a.x-1 here in order to start tracking spaces after ant and not ant itself
	while(maze[a.y][i]!='*'&&maze[a.y][i]!='p'){	//Checks if next locations until meeting a wall are pheromone free
		i--;
		b.x++;
	}
	b.y=1;
	energy(1);	//uses 1 energy 
	return b;
}

posit CWR(posit a){
	posit b;
	b.x=0;
	int i;
	i=a.x+1; //same principle as before but in other direction
	while(maze[a.y][i]!='*'&& maze[a.y][i]!='p'){	//Checks if next locations until meeting a wall are pheromone free
		i++;
		b.x++;
	}
	b.y=2;
	energy(1);	//uses 1 energy 
	return b;
}

posit CWF(posit a){
	posit b;
	b.x=0;
	int i;
	i=a.y-1;
	while(maze[i][a.x]!='*'&&maze[i][a.x]!='p'){	//Checks if next locations until meeting a wall are pheromone free
		i--;
		b.x++;
	}
	b.y=3;
	energy(1);	//uses 1 energy 
	return b;
}

posit CWB(posit a){
	posit b;
	b.x=0;
	int i;
	i=a.y+1;
	while(maze[i][a.x]!='*'&&maze[i][a.x]!='p'){	//Checks if next locations until meeting a wall are pheromone free
		i++;
		b.x++;
	}
	b.y=4;
	energy(1);	//uses 1 energy 
	return b;
}
