
#include<stdio.h>
#include<termios.h>
#include<math.h>

#define f1(x,y,z) (y + 9)/10
#define f2(x,y,z) (x + 2*z + 7)/10
#define f3(x,y,z) (4*x + 25)/10
#define f4(x,y,z) (4*x + 25)/10
#define f5(x,y,z) (4*x + 25)/10
#define f6(x,y,z) (4*x + 25)/10


/* Main function */
int main()
{
 double x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 printf("Enter tolerable error:\n");
 scanf("%lf", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e && count <= 15);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

 getchar();
 return 0;
}