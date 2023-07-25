void recurssion (int n)
{
    int i;
if (n>0)
{
for(i=0;i<n;i++)
{
printf ("%d",n);
recurssion(n-1);
}
}

}
int main()
{
    int n;
    printf("Enter the number \n");
    scanf("%d",&n);
    recurssion(n);
}
