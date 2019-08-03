#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()

{
int i,j,k;
for(i=0;i<40;i++)
{if(i%4==0)
{
for(j=0;j<k;j++)
{printf(".");}
printf("--\n");}
else if(i%4==1)
{
for(j=0;j<k;j++)
{printf(".");}
printf("\\\n");}
else if(i%4==2)
{
for(j=0;j<k;j++)
{printf(".");}
printf("|\n");}
else if(i%4==3)
{
for(j=0;j<k;j++)
{printf(".");}
printf("/\n");
k++;}
usleep(200000);
system("clear");

}
}

