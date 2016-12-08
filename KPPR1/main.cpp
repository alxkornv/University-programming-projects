#include "part.h"

int main()
{
	part A;
	A.set_size(1.0,1.0);
	A.set_sq_len(0.2);
	A.place_on_surface();
	A.move(1,1);
	A.calculate_coord();

	return 0;
}