#include<stdio.h>
#include<math.h>
int main()
{
int i,n;
float per,k,s,mean=0,std=0,x,ll,ul;
printf("Enter the number of sample elements in the data(n): ");
scanf("%d",&n);
float sample[n];
printf("Enter the sample elements(n elements):\n");
for(i=0;i<n;i++)
{
scanf("%f",&sample[i]);
}
printf("Enter minimum percentage of total data analysis required: ");
scanf("%f",&per);
per=per/100;
per=1-per;
k=sqrt((1/per));
for(i=0;i<n;i++)
{
mean=mean+sample[i];
}
mean=mean/n;
for(i=0;i<n;i++)
{
x=(sample[i]-mean)*(sample[i]-mean);
std=std+x;
}
std=std/(n-1);
std=sqrt(std);
ll=mean-(k*std);
if(ll<0) 
{ll=0;}
ul=mean+(k*std);
printf("The interval satisfying the requirement:( %f , %f )\n",ll,ul);
return 0;


}

