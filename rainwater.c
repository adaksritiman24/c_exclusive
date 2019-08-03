#include<stdio.h>
int calculate(int m,int a,int r[])
{
int j=0,largest1=0,largest2=0;
largest1=r[a];
largest2=r[a];


for(j=a;j<m;j++)
{if(r[j]>largest1)
{largest1=r[j];}
}


for(j=a;j>=0;j--)
{if(r[j]>largest2)
{largest2=r[j];}
}


if(largest1>largest2)
{return largest2-r[a];}

else
{return largest1-r[a];}

}
int main()
{
int n,sum=0,i;
printf("Enter length of trapping area");
scanf("%d",&n);
int arr[n];
printf("Enter the hight of the buildings at the respective positions: \n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=1;i<n-1;i++)
{
sum=sum+calculate(n,i,arr);
}
printf("%d\n",sum);
}

