#ifndef COORD_H
#define COORD_H
typedef struct cd{
	short x;
	short y;
}coord;

/*coordinate a - cooordinate b*/
coord minus(coord a,coord b);
/*coordinate a * scalar*/
coord devide(coord a,short scalar);
/*coordinate a / scalar*/
coord multiply(coord a,short scalar);
#endif
