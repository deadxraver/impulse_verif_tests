#include <stddef.h>
#include <stdio.h>
#include <math.h>

#ifdef DBG_PRINT
#define DEBUG_PRINT(x,y,z,i) printf(x,y,z,i);
#else
#define DEBUG_PRINT(x,y,z,i)
#endif

struct z_info
{
  char *z_fmt;
  char *z_name;
  float z_float;
  int z_int;
};

int main(int argc, char* argv[])
{
    size_t i = 0;
    struct z_info z_array[] = { {"%s %f %d\n", "Item0", M_PI, 12345},
                                {"%s %f %d\n", "Item1", M_PI_2, 54321},
                                {"%s %f %d\n", "Item2", M_PI_4 / 0.0001, 0xBADC00DE},
                                {"%s %f %d\n", "Item3", M_SQRT1_2, 44444} };
    while (i < (sizeof (z_array) / sizeof (struct z_info))) {
       if (z_array[i].z_int != 0xBADC00DE) {
          DEBUG_PRINT(z_array[i].z_fmt, z_array[i].z_name, z_array[i].z_float, z_array[i].z_int)
       }
       i++;
    }
    return 0;
}
