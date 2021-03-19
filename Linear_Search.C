#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int check=1;
	int n,num,pos=-1,i,j,ele;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[100];
	printf("Enter the elements\n");
	for(i=0;i<n ;++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&ele);
	for(j=0;j<n;++j)
	{
		if(a[j]==ele)
		{
			pos++;
			check=0;
			printf("Element is found at position %d\n",pos);
			break;
		}
		pos++;
	}
	if(check==1)
	{
		printf("Element not found\n");
	}
	getch();
}