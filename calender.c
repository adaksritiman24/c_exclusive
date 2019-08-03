#include<stdio.h>
#include<stdlib.h>
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MG "\x1B[35m"
#define GRE "\x1B[32m"
int main()
{
int m,year,jan=1,overcomed_days=0,count=0,i,skip,j;
int again;
int days1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int days2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char m_name[12][15]={"January","February", "March", "April","May","June", "July","August","September",
"October","November","December"};
while(1)
{
jan=1; overcomed_days=0; count=0; 
system("clear");
printf("Enter the year: ");
scanf("%d",&year);
printf("Enter month number: ");
scanf("%d",&m);
if(m<=12&&m>=1&&year>=1990)
{
for(i=1990;i<year;i++)
{
if(i%4==0)
{jan=jan+2;}
else
{jan++;}

if(jan>6)
{jan=jan-7;}
}
overcomed_days=jan;
if(year%4==0)
{for(i=0;i<m-1;i++)
{overcomed_days=overcomed_days+days2[i];}
}
else if(year%4!=0)
{for(i=0;i<m-1;i++)
{overcomed_days=overcomed_days+days1[i];}}

skip=overcomed_days%7;
printf("\n\n");
printf("\t\t\t\t____________________________________________________\n");
printf("\t\t\t\t|___________________________________________________\n");
printf("\t\t\t\t|"BLUE"CALENDER FOR YEAR: %d\n",year);
printf(RESET"\t\t\t\t|"GRE"Month - %s\n"RESET"\t\t\t\t|\n",m_name[m-1]);

printf(RESET"\t\t\t\t|---------------------------------------------------\n");
printf("\t\t\t\t|"RED"SUN " YELLOW"  MON     TUE     WED     THU     FRI     SAT\n");
printf(RESET"\t\t\t\t|---------------------------------------------------\n");
if(skip!=0)
{printf("\t\t\t\t|");}
for(j=1;j<=skip;j++)
{printf("\t");
count++;}

/*...........................................*/
if(year%4==0)
{
for(i=1;i<=days2[m-1];i++)
{
if(count==0)
{
printf(RESET"\t\t\t\t|"RED"%d\t",i);
count++;
}
else
{
printf(YELLOW"%d\t",i);
count++;
}

if(count%7==0)
{count=0;
printf(RESET"\n\t\t\t\t|\n");
}}}

/*............................................*/

else
for(i=1;i<=days1[m-1];i++)
{
 if(count==0)
  {
  printf(RESET"\t\t\t\t|"RED"%d\t",i);
  count++;
  }
 else
  {
  printf(YELLOW"%d\t",i);
  count++;
  } 
 if(count%7==0)
 {
  count=0;
  printf(RESET"\n\t\t\t\t|\n");
 }
}
if(count==0)
{printf(RESET"\t\t\t\t|___________________________________________________\n");
}
else
{printf(RESET"\n\t\t\t\t|___________________________________________________\n");}

}

else
{printf("Data not available for given parameters");}
printf("\n\n");

printf("Want to continue?(1 for yes /0 for no): ");
scanf("%d",&again);
if(again==1)
{
continue;}
else
{break;}

}

}
