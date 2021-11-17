typedef struct{
	int x;
	int y;
}posit;

int empty ();   // declaration

int full ();

void clear ();

posit peek ();

posit pop ();

void push (posit value);   // we do not have to specify the name of the parameter

