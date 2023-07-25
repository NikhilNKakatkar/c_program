#include<stdio.h>
void read(int a[90][90],int n,int m)
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %d",&a[i][j]);
        }
        printf("\n");
    }
}
void display(int a[90][90],int n,int m)

{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void multi(int a[90][90],int b[90][90],int n,int m,int n1,int m1)
{
    int i,j,h[90][90],sum,k;

    if(m==n1)
    { sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m1;j++)
         {
             for(k=0;k<m;k++)

        {
            sum=sum+a[i][k]*b[k][j];
        }
          h[i][j]=sum;
          sum=0;
         }
        printf("\n ");
    }
    printf("The multiplication of matrix is: %d",h[i][j]);
    display(h,n,m1);
    }

    else{
        printf("\n The multiplication can not found\n ");
    }
}
int main()
{
    int a[90][90],n,m,n1,m1,b[90][90];
    printf("Enter the rows and column:\n ");
    scanf("%d%d",&n,&m);
    printf("Enter the first matrix:\n ");
    read(a,n,m);
    printf("The 1st  matrix elements are:\n ");
    display(a,n,m);
    printf("Enter the 2 matrix rows and column:\n ");
    scanf(" %d%d",&n1,&m1);
    printf("\n Enter the second matrix element:\n ");
    read(b,n1,m1);
    printf("\n the second matrix elements are:\n ");
    display(b,n1,m1);
    multi(a,b,n,m,n1,m1);

}
