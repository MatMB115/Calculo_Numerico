#include <stdio.h>
#include <termios.h>
#include <math.h>

float f(float x,float y,float z,float x2,float y2,float z2){
  return ((5-y+z2)/10);
//x=(17-y+2*z)/20
}

float s(float x,float y,float z,float x2,float y2,float z2)
{
  return ((10-2*x-x2)/20);
//y=(-18+z-3*x)/20
}

float t(float x,float y,float z,float x2,float y2,float z2)
{
  return ((10-x-10*y));
//z=(25-2*x+3*y)/20
}

float t1(float x,float y,float z,float x2,float y2,float z2)
{
  return ((0-z-y2)/10);
//z=(25-2*x+3*y)/20
}

float s1(float x,float y,float z,float x2,float y2,float z2)
{
  return ((0-3*y-3*z2)/30);
//z=(25-2*x+3*y)/20
}

float f1(float x,float y,float z,float x2,float y2,float z2)
{
  return ((5-2*x2+2*y2)/20);
//z=(25-2*x+3*y)/20
}

int main()
{
  float x0,y0,z0,x02,y02,z02,x1=0,y1=0,z1=0,x12=0,y12=0,z12=0,tempx,tempy,tempz,tempx1,tempy1,tempz1,acc=0.0001;
  int iteration=0;
  printf("Enter initial guesses:\n");
  scanf("%f%f%f%f%f%f",&x0,&y0,&z0,&x02,&y02,&z02);
  do
  {
    tempx=x1;
    tempy=y1;
    tempz=z1;
    tempx1=x12;
    tempy1=y12;
    tempz1=z12;

    x1=f(x0,y0,z0,x02,y02,z02);
    y1=s(x0,y0,z0,x02,y02,z02);
    z1=t(x0,y0,z0,x02,y02,z02);
    printf("X1 = %f\t X2 = %f\t X3 = %f X4 = %f\t X5 = %f\t X6 = %f\n", x1, y1, z1, x12, y12, z12);
    iteration++;

    x0=x1;
    y0=y1;
    z0=z1;
    x02=x12;
    y02=y12;
    z02=z12;
  }while(fabs(tempx-x1)>acc && fabs(tempy-y1)>acc && fabs(tempz-z1)>acc && fabs(tempx1-x12)>acc && fabs(tempy1-y12)>acc && fabs(tempz1-z12)>acc);

  printf("\n\nResposta final\n");
  printf("x1=%f \nx2=%f \nx3=%f x4=%f \nx5=%f \nx6=%f\n",x1,y1,z1,x12,y12,z12);
  printf("Iterações=%d",iteration);
  getchar();
}
