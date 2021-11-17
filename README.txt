Michael: The Greedy Ant 

By: Doniyor Nimatullo, Ethan Garcia, and Aditya Saha 


checkloc.c functions:
CWL/CWR/CWF/CWB:
All 4 functions return a posit data type (which is a struct consisting of int x and int y). The
x value of this returned posit shows the number of spaces free in the direction requested,
this is so that the ant can bold jump. It does this within a while loop which checks if the
space ahead is a wall or pheromone, and increments b.x whenever the space is free.
The y value of this posit is a number 1-4 with each number representing a direction 
(1=left, 2=right, 3=up, 4=down). 
movement.c functions:

MOVE_B/MOVE_F/MOVE_L/MOVE_R:
All four functions refer to extern posit a, which is the current position of the ant, the functions
first check if the space ahead is a gold piece, in which case it increments the gold count
and then the x or y value, depending on if its horizontal or vertical movement, gets
incremented or decremented by 1, depending on the direction of movement. It does this in an
if-statement checking if the space ahead is a wall, if it isn't then the ant will move into that
space.
MARK:
The ant pushes its location represented by posit a, into the stack and places a 'p' on his
location in the maze.
BJPI/CJPI:
Both functions have the parameter posit b, with a switch case inside. The case runs for values
of b.y which denotes the direction in which the ant felt the itch. For each case, it first
checks if the space its jumping to is gold, in which case it increments the gold count. It
then jumps into the open space by being incremented by b.x which is the number of free
spaces. In the case of CJPI instead of being incremented by b.x, it is incremented by 1.
BACKTRACK:
This function has parameter posit aux. When called the parameter is pop(). So it pops the
location marked by the ant from the stack, and then it sets its location (a.x,a.y) equal to the
coordinates that it just popped.
ENERGY:
Has parameter c, which denotes the amount of energy to subtract from int MAX_ENERGY.
