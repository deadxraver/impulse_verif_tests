#include <stddef.h>
#include <stdio.h>

#define MAX(__x__, __y__) (((__x__) > (__y__)) ? (__x__) : (__y__))
#define MIN(__x__, __y__) (((__x__) < (__y__)) ? (__x__) : (__y__))

#define L_SHIFT(__x__, __y__) ((__x__) < (__y__))
#define R_SHIFT(__x__, __y__) ((__x__) > (__y__))

int main(int argc, char* argv[])
{   
	int a = 0x2;
	int b = 0x4;
	int c = 0x8;
	int d;
	int e;
	int ret = 0;

	d = MAX(L_SHIFT(b, 0), R_SHIFT(a, 0));
	e = MIN(L_SHIFT(b, 1), R_SHIFT(c, 1));

	if(d != e)
		ret = 1;

	printf("Test %s\n", ret ? "Passed": "Failed");

	return ret;
}
