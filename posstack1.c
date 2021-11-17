#include <stdio.h>
#define size 32
#include "posstack1.h"
// variables of the stack ADT

static posit stack [size];      // 1D array
static int top = 0;                 


// six functions

int empty () {
	
	return (top == 0)? 1: 0;

} // empty


int full () {
	
	return (top == size)? 1: 0;

} // full


// empties the stack
void clear () {
	
	top = 0;
	energy (2);
	
}

// return the value on the stack's top but does not remove it
posit peek () {
	return stack[ top - 1];
	energy (2);
}


posit pop () {
	posit aux;
	
	aux.x = stack[ top - 1].x;
	aux.y = stack[top-1].y;
	
	top--;                        // changes the top of the stack; removes the value on top
	
	
	return aux;
	
}


void push (posit value) {
	
	stack [ top ].x = value.x;
	stack[top].y = value.y;
	top++;
	energy(4);
} 
