#include<stdio.h>
int main()
{
int n,i,j,temp=0;
printf("Enter the length of each side of square matrix: ");
scanf("%d",&n);
int a[n][n];
printf("Enter the values in the matrix accordingly: ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}

}
for(i=0;i<n;i++){
for(j=0;j<n/2;j++)
{
temp=a[i][j];
a[i][j]=a[i][n-1-j];
a[i][n-1-j]=temp;
}  

}
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
temp=a[i][j];
a[i][j]=a[j][i];
a[j][i]=temp;
}

}

printf("\nThe rotated matrix is:\n\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("\n");


}
