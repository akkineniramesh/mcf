#include <stdio.h>
#include <stdlib.h>
int multiply(int m1, int m2);
int Dice(int pos);
int pos = 1;
main()
{
	int dice;
	for (dice = 0; dice <= 6; dice = dice + 1)printf("%d", dice);
	for(dice=0;dice<=6;dice=dice+1)
	{
		printf("%d", dice);
	}
	int dice1;
	dice1 = 10;
	while(dice1>=1)
	{
		printf("%d", dice1);
		dice1 = dice1 - 1;
	}
	int ndice[10];
	for(dice1=0;dice1<10;++dice1)
	{
		ndice[dice1] = 5;
		printf("%d", ndice[dice1]);
	}
	if (dice1 > dice)printf("%d %d", dice1, dice);
	printf(" %d", multiply(5, 3));

	srand(time(NULL));
	printf("Random number: %d\n", rand() % 10000);
	//int pos = 1;
	printf("%d", Dice(pos));
	while(pos<100)
	{
		//pos=Dice(pos);
		Dice(pos);
	}
	printf("hello ramesh\n");
	getchar();
}
/*multiply function*/
int multiply(int m1,int m2)
{
	printf(" %d %d", m1, m2);
	return m1*m2;
}
int Dice(int p)
{
	pos = p + rand() % 6 +1;
	printf(" %d", pos);
	return pos;
}