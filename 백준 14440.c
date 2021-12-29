#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int x, y, a, b, n;
	scanf("%d %d %2d %2d %d", &x, &y, &a, &b, &n);
	if (n == 0)
	{
		printf("%02d\n", a);
		return 0;
	}
	else if (n == 1)
	{
		printf("%02d\n", b);
		return 0;
	}
	int temp;
	for (int i = 2; i <= n; i++)
	{
		temp = b;
		b = (y * a + x * temp)%100;
		a = temp;
	}
	printf("%02d\n", b);
}