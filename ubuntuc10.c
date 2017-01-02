#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define numberofboards 201
#define boardsize 101
#define numberofparts 101
int multiply(int m1, int m2);
int Dice(int pos);
int pos = 1, turnsofdice = 0, turnsofgame = 0;
int states[101];
long numberofdiceturns = 100000;
void runGame(), TurnsofDice(), fillLadders(), fillSnakes(), numberofGames(), printGameStats(), logmultiple(), runGames();
void fillSnakesrand(), fillLaddersrand(), printGameStatsrand();
void boardrunGames(), boardfillLaddersrand(), boardfillSnakesrand(), boardDice();
void boardTurnsofDice(), boardnumberofGames1(int b), boardlogmultiple(int c), boardprintGameStats();
void boardSnakesLadders(), boardshuffleSnakesrand(), boardshuffleLaddersrand();
void commonboardlogmultiple(int c), commonboardprintGameStats(), commonboardrunGames();
void commonboardlogtotalmultiple(), commonboardallocatemultiple(int c, int d);
void prefcommonboardlogmultiple1(int c), prefcommonboardprintGameStats1(), prefcommonboardallocatemultiple1(int c, int d);
void prefcommonboardallocatemultiple2(int c, int d), prefboardrunGames1(), prefcommonboardrunGames1();
void prefcommonboardlogwholemultiple1(), prefcommonboardallocatemultiple3(int c);
void prefcommonboardlogmultiple2(int c), boardnumberofGames2(int b), prefcommonboardlogtotalmultiple();
void prefcommonboardprintGameStats2(), prefcommonboardrunGames2(), prefboardrunGames2();
void prefboardfillLaddersrand(int h), prefboardfillSnakesrand(int h);
void prefboardshuffleSnakesrand(), prefboardshuffleLaddersrand();
void prefcommonboardlogwholemultiple0();
void prefcommonboardlogwholemultiple2();
void prefcommonboardprintGameStats3();
void prefboardshuffleSnakesLaddersrand();
struct gamestate gamestatestruct();
int SnakesLadders();
int ladderStart[] = { 8,19,21,28,36,43,50,54,61,62,66 };
int ladderEnd[] = { 26,38,82,53,57,77,91,88,99,96,87 };
int snakeStart[] = { 98,93,83,69,68,64,59,52,48,46 };
int snakeEnd[] = { 13,37,22,33,2,24,18,11,9,15 };
int ladderHit[12];
int snakeHit[11];
int lIndex[101];
int sIndex[101];
int boardstates[numberofboards][boardsize];
int boardlIndex[numberofboards][boardsize];
int boardsIndex[numberofboards][boardsize];
int boardladderHit[numberofboards][12];
int boardsnakeHit[numberofboards][11];
int boardpos[numberofboards];
int boardturnsofdiceforagame[numberofboards];
int boardturnsofgame[numberofboards];
//float boardgameturnmultiple[101];
//float boardgametotalmultiple[101];
float boardgameturnmultiple[101][31];
float boardgametotalmultiple[101][31];
float commonboardgametotalmultipleleft[31];
float commonboardgametotalmultipleadded[31];
float commonboardgametotalmultipletakenin[101];
float logprefwholemultiple = 0;
float logprefwholemultipletaken = 0;
float logprefwholemultipleadded = 1;
float logprefwholemultipleleft = 1;
float prefboardgametotalmultiple[numberofboards];
int snakesshuffled = 0;
int laddersshuffled = 0;
int turnsofdiceforagame = 0;
float turnsasmoney = 100;
int turnsasmoneytakeninx = 0;
float interest = 0.006;
float prefinterest = 0.0045;
float basispoint = 100;
float gameturnmultiple = 1;
float gametotalmultiple = 1;
float logprefgamewholemultiple = 1;
double loggameturnmultiple = 0;
double loggametotalmultiple = 0;
struct gamestate prefgamestate;
struct gamestate
{
	float logprefgamewholemultiple;
	float logprefwholemultipletaken;
	float logprefwholemultipleadded;
	float logprefwholemultipleleft;
	int boardpos[numberofboards];
	int boardturnsofdiceforagame[numberofboards];
	int boardturnsofgame[numberofboards];
	int boardstates[numberofboards][boardsize];
	int boardlIndex[numberofboards][boardsize];
	int boardsIndex[numberofboards][boardsize];
	int boardladderHit[numberofboards][12];
	int boardsnakeHit[numberofboards][11];
	float prefboardgametotalmultiple[numberofboards];
};

/*	int pos=1,turnsofdice=0,turnsofgame=0;
int a[]=new int[101];
int ladderStart[]={8,19,21,28,36,43,50,54,61,62,66};
int ladderEnd[] = {26,38,82,53,57,77,91,88,99,96,87};
int snakeStart[]= {98,93,83,69,68,64,59,52,48,46};
int snakeEnd[] =  {13,37,22,33,2,24,18,11,9,15};
int ladderHit[]=new int[11];
int snakeHit[]= new int[10];
int lIndex[]= new int[101];
int sIndex[]= new int[101];
int numberofgames=0;
long numberofdiceturns;
int turnsofdiceforagame=0;
double turnsasmoney=0;
float basispoint=100;
Random r= new Random();*/
main()
{
	int dice;
	for (dice = 0; dice <= 6; dice = dice + 1)printf("%d", dice);
	for (dice = 0; dice <= 6; dice = dice + 1)
	{
		printf("%d", dice);
	}
	int dice1;
	dice1 = 10;
	while (dice1 >= 1)
	{
		printf("%d", dice1);
		dice1 = dice1 - 1;
	}
	int ndice[10];
	for (dice1 = 0; dice1<10; ++dice1)
	{
		ndice[dice1] = dice1 * 2;
		printf("%d", ndice[dice1]);
	}
	if (dice1 > dice)printf(" %d %d", dice1, dice);
	printf(" %d", multiply(5, 3));

	srand(time(NULL));
	printf("Random number: %d \n", rand() % 10000);

	//runGame();
	//printGameStats();
	//runGames();
	//printGameStatsrand();
	//boardrunGames();
	//boardprintGameStats();
	//commonboardrunGames();
	//prefcommonboardrunGames1();
	prefcommonboardrunGames2();
	printf("hello ramesh\n");
	getchar();
}
/*multiply function*/
int multiply(int m1, int m2)
{
	printf(" %d %d", m1, m2);
	return m1*m2;
}
int Dice(int p)
{
	pos = p + rand() % 6 + 1;
	//printf(" %d", pos);
	return pos;
}
void runGame()
{
	for (int i = 1; i<101; i++)
	{
		states[i] = 0;
		lIndex[i] = 0;
		sIndex[i] = 0;
	}
	for (int i = 1; i < 12; i++)ladderHit[i] = 0;
	for (int i = 1; i < 11; i++)snakeHit[i] = 0;
	//getSnakesLadders(args);
	//System.out.println("turnsasmoneyatstart=" + turnsasmoney);
	//fillLadders();
	//fillSnakes();
	fillLaddersrand();
	fillSnakesrand();
	while (turnsofdice<numberofdiceturns)
	{
		pos = Dice(pos);
		TurnsofDice();
		if (pos>100)numberofGames();
		pos = SnakesLadders();
	}
}
void TurnsofDice()
{
	++turnsofdice;
	++turnsofdiceforagame;
}
int SnakesLadders()
{
	if (states[pos] != 0)
	{
		if (lIndex[pos] != 0)ladderHit[lIndex[pos]]++;
		if (sIndex[pos] != 0)snakeHit[sIndex[pos]]++;
		//if(pos>states[pos])printf("snakehit %d",pos);
		//if(pos<states[pos])printf("ladderhit %d",pos);
		pos = states[pos];
	}
	return pos;
}
void fillLadders()
{
	for (int i = 0; i<11; i++)
	{
		//if (lIndex[ladderStart[i]] != 0)
		//{
		states[ladderStart[i]] = ladderEnd[i];
		lIndex[ladderStart[i]] = i + 1;
		//}
	}
}
void fillSnakes()
{
	for (int i = 0; i<10; i++)
	{
		//if (sIndex[snakeStart[i]] != 0)
		//{
		states[snakeStart[i]] = snakeEnd[i];
		sIndex[snakeStart[i]] = i + 1;
		//}
	}
}
void numberofGames()
{
	pos = pos - 100;
	//System.out.println("turnsofgame="+turnsofgame);
	//System.out.println("position="+pos);
	turnsofgame++;
	//turnsasmoney = turnsasmoney*(((10000 - basispoint) / 10000) + (basispoint / (turnsofdiceforagame * 350)));
	logmultiple();
	turnsofdiceforagame = 0;
	//if(turnsofgame%35==0)numberofdiceturns=numberofdiceturns+100;
}
void printGameStats()
{
	//printf("turnsofdice= %d \n", turnsofdice);
	//printf("turnsofgame= %d \n", turnsofgame);
	//printf("numberofdiceturns= %d \n", numberofdiceturns);
	//printf("turnsofdiceindistance= %f \n" , turnsofdice*3.5);
	//printf("turnsasmoney= %f \n", turnsasmoney);
	//System.out.println("numberofdiceturnsindistance="+(long)(numberofdiceturns*3.5));
	//printf(" loggametotalmultiple %e ", loggametotalmultiple);
	//printf(" gametotalmultiple %f \n", gametotalmultiple);
	printf(" %f \n", gametotalmultiple);
	//printf("pos= %d", pos);
	//for (int i = 1; i <= 11; i++)
	//printf("LadderHit%d = %d", i, ladderHit[i]);
	//for (int i = 1; i <= 10; i++)
	//printf("SnakeHit%d = %d", i, snakeHit[i]);
}
void logmultiple()
{
	gameturnmultiple = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
		- turnsasmoneytakeninx*(1 + interest)
		+ ((basispoint / (turnsofdiceforagame * 350)))*(turnsasmoneytakeninx + 1);
	//gameturnmultiple = ((10000 - basispoint) / 10000) + ((basispoint / (turnsofdiceforagame * 350)));
	//printf(" gameturnmultiple %f ", gameturnmultiple);
	gametotalmultiple = gametotalmultiple * gameturnmultiple;
	gameturnmultiple = 1;
	//loggameturnmultiple = log(((10000 - basispoint) / 10000) + ((basispoint / (turnsofdiceforagame * 350))));
	//printf(" loggameturnmultiple %e ", loggameturnmultiple);
	//loggametotalmultiple = loggametotalmultiple + loggameturnmultiple;
	//loggameturnmultiple = 0;
	//printf(" loggametotalmultiple %e ", loggametotalmultiple);
}
void runGames()
{
	for (int i = 0; i < 3; i++)
	{
		turnsasmoneytakeninx = i;
		//printf(" turnsasmoneytakeninx %f ", turnsasmoneytakeninx);
		printf(" %i ", turnsasmoneytakeninx);
		runGame();
		printGameStats();
		turnsofdice = 0;
		turnsofgame = 0;
	}
}
void fillLaddersrand()
{
	for (int i = 0; i<11; i++)
	{
		if ((rand() % 6) > 2)
		{
			states[ladderStart[i]] = ladderEnd[i];
			lIndex[ladderStart[i]] = i + 1;
		}
	}
}
void fillSnakesrand()
{
	for (int i = 0; i<10; i++)
	{
		if ((rand() % 6) > 2)
		{
			states[snakeStart[i]] = snakeEnd[i];
			sIndex[snakeStart[i]] = i + 1;
		}
	}
}
void printGameStatsrand()
{
	//printf("turnsofdice= %d \n", turnsofdice);
	//printf("turnsofgame= %d \n", turnsofgame);
	//printf("numberofdiceturns= %d \n", numberofdiceturns);
	//printf("turnsofdiceindistance= %f \n" , turnsofdice*3.5);
	//printf("turnsasmoney= %f \n", turnsasmoney);
	//System.out.println("numberofdiceturnsindistance="+(long)(numberofdiceturns*3.5));
	//printf(" loggametotalmultiple %e ", loggametotalmultiple);
	//printf(" gametotalmultiple %f \n", gametotalmultiple);
	//printf(" %f \n", gametotalmultiple);
	//printf("pos= %d", pos);
	for (int i = 1; i <= 11; i++)
		printf("LadderHit%d = %d \n", i, ladderHit[i]);
	for (int i = 1; i <= 10; i++)
		printf("SnakeHit%d = %d \n", i, snakeHit[i]);
}
void boardrunGames()
{
	gameturnmultiple = 1;
	turnsasmoneytakeninx = 0;
	for (int h = 1; h<101; h++)
	{
		boardpos[h] = 1;
		boardturnsofdiceforagame[h] = 0;
		boardturnsofgame[h] = 0;
		//boardgameturnmultiple[h] = 1;
		//boardgametotalmultiple[h] = 1;
		commonboardgametotalmultipletakenin[h] = 0;
		for (int i = 1; i < 31; i++)
		{
			//boardgameturnmultiple[h][i] = 1;
			boardgametotalmultiple[h][i] = 0.01;
			if (h<2)commonboardgametotalmultipleleft[i] = 1;
			if (h<2)commonboardgametotalmultipleadded[i] = 1;
		}

		for (int i = 1; i<101; i++)
		{
			boardstates[h][i] = 0;
			boardlIndex[h][i] = 0;
			boardsIndex[h][i] = 0;
		}

		for (int i = 1; i < 12; i++)boardladderHit[h][i] = 0;
		for (int i = 1; i < 11; i++)boardsnakeHit[h][i] = 0;
	}
	boardfillLaddersrand();
	boardfillSnakesrand();
	while (turnsofdice<numberofdiceturns)
	{
		boardDice();
		boardTurnsofDice();
		for (int h = 1; h < 101; h++)
		{
			if (boardpos[h] > 100)boardnumberofGames1(h);
			boardSnakesLadders();
		}
		boardshuffleSnakesrand();
		boardshuffleLaddersrand();
	}
	commonboardlogtotalmultiple();
}
void boardfillLaddersrand()
{
	for (int h = 1; h<101; h++)
	{
		for (int i = 0; i<11; i++)
		{
			if ((rand() % 6) > 2)
			{
				boardstates[h][ladderStart[i]] = ladderEnd[i];
				boardlIndex[h][ladderStart[i]] = i + 1;
			}
		}
	}
}
void boardfillSnakesrand()
{
	for (int h = 1; h<101; h++)
	{
		for (int i = 0; i<10; i++)
		{
			if ((rand() % 6) > 2)
			{
				boardstates[h][snakeStart[i]] = snakeEnd[i];
				boardsIndex[h][snakeStart[i]] = i + 1;
			}
		}
	}
}
void boardDice()
{
	int d = rand() % 6 + 1;
	for (int h = 1; h<numberofboards; h++)
	{
		boardpos[h] = boardpos[h] + d;
		//printf(" %d", pos);
	}
}
void boardTurnsofDice()
{
	++turnsofdice;
	for (int h = 1; h<numberofboards; h++)
	{
		boardturnsofdiceforagame[h]++;
	}
}
void boardSnakesLadders()
{
	for (int h = 1; h<numberofboards; h++)
	{
		if (boardstates[h][boardpos[h]] != 0)
		{
			if (boardlIndex[h][boardpos[h]] != 0)boardladderHit[h][boardlIndex[h][boardpos[h]]]++;
			if (boardsIndex[h][boardpos[h]] != 0)boardsnakeHit[h][boardsIndex[h][boardpos[h]]]++;
			//if(pos>states[pos])printf("snakehit %d",pos);
			//if(pos<states[pos])printf("ladderhit %d",pos);
			boardpos[h] = boardstates[h][boardpos[h]];
		}
	}
}
void boardlogmultiple(int h)
{
	for (int i = 1; i < 11; i++)
	{
		turnsasmoneytakeninx = i - 1;
		gameturnmultiple = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
			- turnsasmoneytakeninx*(1 + interest)
			+ ((basispoint / (boardturnsofdiceforagame[h] * 350)))*(turnsasmoneytakeninx + 1);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * gameturnmultiple;
		gameturnmultiple = 1;
	}
	//boardgameturnmultiple[h] = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
	//- turnsasmoneytakeninx*(1 + interest)
	//+ ((basispoint / (boardturnsofdiceforagame[h] * 350)))*(turnsasmoneytakeninx + 1);
	//boardgametotalmultiple[h] = boardgametotalmultiple[h] * boardgameturnmultiple[h];
	//boardgameturnmultiple[h] = 1;
}
void boardnumberofGames1(int h)
{
	boardpos[h] = boardpos[h] - 100;
	//System.out.println("turnsofgame="+turnsofgame);
	//System.out.println("position="+pos);
	boardturnsofgame[h]++;
	//turnsasmoney = turnsasmoney*(((10000 - basispoint) / 10000) + (basispoint / (turnsofdiceforagame * 350)));
	//boardlogmultiple(h);
	//commonboardlogmultiple(h);
	//prefcommonboardlogmultiple(h);
	prefcommonboardlogmultiple1(h);
	boardturnsofdiceforagame[h] = 0;
	//if(turnsofgame%35==0)numberofdiceturns=numberofdiceturns+100;
}
void boardprintGameStats()
{
	for (int h = 1; h<101; h++)
	{
		for (int i = 1; i < 11; i++)
		{
			printf(" %.1f ", boardgametotalmultiple[h][i]);
		}
		printf("\n");
		//}
		//for (int h = 1; h < 101; h++)
		//{
		for (int i = 1; i <= 11; i++)
			printf("L %d = %d \n", i, boardladderHit[h][i]);
		for (int i = 1; i <= 10; i++)
			printf("S %d = %d \n", i, boardsnakeHit[h][i]);
	}
}
void commonboardlogmultiple(int h)
{
	for (int i = 1; i < 11; i++)
	{
		commonboardgametotalmultipleadded[i] = commonboardgametotalmultipleadded[i] - boardgametotalmultiple[h][i];
		turnsasmoneytakeninx = i - 1;
		gameturnmultiple = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
			- turnsasmoneytakeninx*(1 + interest)
			+ ((basispoint / (boardturnsofdiceforagame[h] * 350)))*(turnsasmoneytakeninx + 1);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * gameturnmultiple;
		commonboardallocatemultiple(h, i);
		//commonboardgametotalmultiple[i] = commonboardgametotalmultiple[i] + boardgametotalmultiple[h][i];
		//boardgametotalmultiple[h][i] = commonboardgametotalmultiple[i] / 10000;
		//commonboardgametotalmultiple[i] = commonboardgametotalmultiple[i] - boardgametotalmultiple[h][i];
		gameturnmultiple = 1;
	}
}
void commonboardprintGameStats()
{
	for (int i = 1; i < 11; i++)
	{
		printf(" %.1f ", commonboardgametotalmultipleadded[i]);
	}
	printf("\n");
	for (int i = 1; i < 11; i++)
	{
		printf(" %.1f ", commonboardgametotalmultipleleft[i]);
	}
	printf("\n");
	printf("snakes shuffled %d ", snakesshuffled);
	printf("ladders shuffled %d \n", laddersshuffled);
	for (int h = 1; h<101; h++)
	{
		printf(" %.1f ", boardgametotalmultiple[h][1]);
	}
	printf("\n");
}
void commonboardrunGames()
{
	for (int i = 0; i < 3; i++)
	{
		boardrunGames();
		turnsofdice = 0;
		//commonboardprintGameStats();
		prefcommonboardprintGameStats1();
	}
}
void boardshuffleLaddersrand()
{
	for (int h = 1; h<101; h++)
	{
		if ((h * 1) == (rand() % 100 + 1))
		{
			//printf("shuffling ladders %d ", h);
			laddersshuffled++;
			for (int i = 1; i<101; i++)
			{
				boardstates[h][i] = 0;
				boardlIndex[h][i] = 0;
				boardsIndex[h][i] = 0;
			}
			for (int i = 0; i < 11; i++)
			{
				if ((rand() % 6) > 2)
				{
					boardstates[h][ladderStart[i]] = ladderEnd[i];
					boardlIndex[h][ladderStart[i]] = i + 1;
				}
			}
		}
	}
}
void boardshuffleSnakesrand()
{
	for (int h = 1; h<101; h++)
	{
		if ((h * 1) == (rand() % 100 + 1))
		{
			//printf("shuffling snakes %d ", h);
			snakesshuffled++;
			for (int i = 1; i<101; i++)
			{
				boardstates[h][i] = 0;
				boardlIndex[h][i] = 0;
				boardsIndex[h][i] = 0;
			}
			for (int i = 0; i < 10; i++)
			{
				if ((rand() % 6) > 2)
				{
					boardstates[h][snakeStart[i]] = snakeEnd[i];
					boardsIndex[h][snakeStart[i]] = i + 1;
				}
			}
		}
	}
}
void commonboardlogtotalmultiple()
{
	for (int i = 1; i < 11; i++)
	{
		//for(int h=1;h<101;h++)
		//{
		//commonboardgametotalmultipleadded[i]=commonboardgametotalmultipleadded[i]+boardgametotalmultiple[h][i];
		//}
		commonboardgametotalmultipleadded[i] = commonboardgametotalmultipleadded[i] + commonboardgametotalmultipleleft[i];
	}
}
void commonboardallocatemultiple(int h, int i)
{
	//if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleleft[i]))
	if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i] / 3))
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + (boardgametotalmultiple[h][i] / 10);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 0.9;
	}
	else if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i] / 50)
		&& boardgametotalmultiple[h][i] < commonboardgametotalmultipleleft[i] * 4)
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - (boardgametotalmultiple[h][i] / 4);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 1.25;
	}
	else if (boardgametotalmultiple[h][i] < (commonboardgametotalmultipleadded[i] / 3000))
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + boardgametotalmultiple[h][i];
		boardgametotalmultiple[h][i] = commonboardgametotalmultipleleft[i] / 1000;
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - boardgametotalmultiple[h][i];
	}
	commonboardgametotalmultipleadded[i] = commonboardgametotalmultipleadded[i] + boardgametotalmultiple[h][i];
}
void prefcommonboardallocatemultiple1(int h, int i)
{
	//if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i]))
	if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleleft[i]) * 5)
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + (boardgametotalmultiple[h][i] / 10);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 0.9;
	}
	else if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i] / 80))
	{
		if (boardgametotalmultiple[h][i] < commonboardgametotalmultipleleft[i] * 2)
		{
			//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.25;
			commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - (boardgametotalmultiple[h][i] / 2);
			boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 1.5;
			//if (commonboardgametotalmultipletakenin[h]<0.25)
			//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.1;
		}
		else if (commonboardgametotalmultipletakenin[h]<0.25)
			commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.1;
		//{
		//commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - (boardgametotalmultiple[h][i] / 4);
		//boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 1.25;
		//}
	}
	else if (boardgametotalmultiple[h][i] < (commonboardgametotalmultipleadded[i] / 3000))
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + boardgametotalmultiple[h][i];
		boardgametotalmultiple[h][i] = commonboardgametotalmultipleleft[i] / 1000;
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - boardgametotalmultiple[h][i];
	}
	commonboardgametotalmultipleadded[i] = commonboardgametotalmultipleadded[i] + boardgametotalmultiple[h][i];
}
void prefcommonboardlogmultiple1(int h)
{
	commonboardgametotalmultipleadded[1] = commonboardgametotalmultipleadded[1] - boardgametotalmultiple[h][1];
	turnsasmoneytakeninx = 0;
	//turnsasmoneytakeninx = i - 1;
	//turnsasmoneytakeninx = commonboardgametotalmultipletakenin[1] / commonboardgametotalmultipleadded[1];
	//turnsasmoneytakeninx = commonboardgametotalmultipletakenin[h];
	//gameturnmultiple = ((10000 - basispoint) / 10000) - (turnsasmoneytakeninx*(1 + interest)) + (basispoint / (boardturnsofdiceforagame[h] * 350));
	//turnsasmoneytakeninx = turnsasmoneytakeninx + (commonboardgametotalmultipletakenin[i]/commonboardgametotalmultipleadded[i]);
	gameturnmultiple = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
		- turnsasmoneytakeninx*(1 + interest)
		+ ((basispoint / (boardturnsofdiceforagame[h] * 350)))*(turnsasmoneytakeninx + 1);
	boardgametotalmultiple[h][1] = boardgametotalmultiple[h][1] * gameturnmultiple;
	prefcommonboardallocatemultiple1(h, 1);
	gameturnmultiple = 1;
}
void prefcommonboardprintGameStats1()
{
	printf(" %.1f ", logprefgamewholemultiple);
	printf(" %.1f ", commonboardgametotalmultipleadded[1]);
	printf("\n");
	printf(" %.1f ", commonboardgametotalmultipleleft[1]);
	for (int h = 1; h<101; h++)
	{
		printf(" %.1f ", commonboardgametotalmultipletakenin[h]);
		printf(" %.1f ", boardgametotalmultiple[h][1]);
	}
	printf("\n");
	printf("snakes shuffled %d ", snakesshuffled);
	printf("ladders shuffled %d \n", laddersshuffled);
	printf("\n");
}
void prefcommonboardallocatemultiple2(int h, int i)
{
	//if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i]))
	if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleleft[i]))
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + (boardgametotalmultiple[h][i] / 10);
		boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 0.9;
		//if (commonboardgametotalmultipletakenin[h]<0.25)
		//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.1;
	}
	else if (boardgametotalmultiple[h][i] > (commonboardgametotalmultipleadded[i] / 80))
	{
		if (boardgametotalmultiple[h][i] < commonboardgametotalmultipleleft[i] * 2)
		{
			//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + boardgametotalmultiple[h][i]/20;
			//logprefwholemultipletaken = logprefwholemultipletaken + boardgametotalmultiple[h][i] / 20;
			commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - (boardgametotalmultiple[h][i] / 2);
			boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 1.5;
			//if (commonboardgametotalmultipletakenin[h]<0.25)
			//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.1;
		}
		//else if (commonboardgametotalmultipletakenin[h]<0.25)
		//commonboardgametotalmultipletakenin[h] = commonboardgametotalmultipletakenin[h] + 0.1;
		//{
		//commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - (boardgametotalmultiple[h][i] / 4);
		//boardgametotalmultiple[h][i] = boardgametotalmultiple[h][i] * 1.25;
		//}
	}
	else if (boardgametotalmultiple[h][i] < (commonboardgametotalmultipleadded[i] / 3000))
	{
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] + boardgametotalmultiple[h][i];
		boardgametotalmultiple[h][i] = commonboardgametotalmultipleleft[i] / 1000;
		commonboardgametotalmultipleleft[i] = commonboardgametotalmultipleleft[i] - boardgametotalmultiple[h][i];
	}
	commonboardgametotalmultipleadded[i] = commonboardgametotalmultipleadded[i] + boardgametotalmultiple[h][i];
}
void prefboardrunGames1()
{
	gameturnmultiple = 1;
	turnsasmoneytakeninx = 0;
	logprefgamewholemultiple = 1;
	logprefwholemultiple = 0;
	logprefwholemultipletaken = 0;
	logprefwholemultipleadded = 1;
	logprefwholemultipleleft = 1;
	for (int h = 1; h<101; h++)
	{
		boardpos[h] = 1;
		boardturnsofdiceforagame[h] = 0;
		boardturnsofgame[h] = 0;
		//boardgameturnmultiple[h] = 1;
		//boardgametotalmultiple[h] = 1;
		commonboardgametotalmultipletakenin[h] = 0;
		for (int i = 1; i < 31; i++)
		{
			//boardgameturnmultiple[h][i] = 1;
			boardgametotalmultiple[h][i] = 0.01;
			if (h<2)commonboardgametotalmultipleleft[i] = 1;
			if (h<2)commonboardgametotalmultipleadded[i] = 1;
		}

		for (int i = 1; i<101; i++)
		{
			boardstates[h][i] = 0;
			boardlIndex[h][i] = 0;
			boardsIndex[h][i] = 0;
		}

		for (int i = 1; i < 12; i++)boardladderHit[h][i] = 0;
		for (int i = 1; i < 11; i++)boardsnakeHit[h][i] = 0;
	}
	boardfillLaddersrand();
	boardfillSnakesrand();
	while (turnsofdice<numberofdiceturns)
	{
		boardDice();
		boardTurnsofDice();
		for (int h = 1; h < 101; h++)
		{
			if (boardpos[h] > 100)boardnumberofGames2(h);
			boardSnakesLadders();
		}
		boardshuffleSnakesrand();
		boardshuffleLaddersrand();
		if (turnsofdice % 30 == 0)
			prefcommonboardlogwholemultiple1();
	}
	prefcommonboardlogtotalmultiple();
}
void prefcommonboardrunGames1()
{
	for (int i = 0; i < 1; i++)
	{
		prefboardrunGames1();
		turnsofdice = 0;
		//commonboardprintGameStats();
		prefcommonboardprintGameStats1();
	}
}
void prefcommonboardlogwholemultiple0()
{
	logprefgamewholemultiple = commonboardgametotalmultipleadded[1] + commonboardgametotalmultipleleft[1]
		- logprefwholemultipletaken*(1 + interest);
	if (turnsofdice % 3000 == 0)
		printf("logprefwholemultipletaken %.f", logprefwholemultipletaken);
	logprefwholemultipletaken = 0;
	float ratio = logprefgamewholemultiple / (commonboardgametotalmultipleadded[1] + commonboardgametotalmultipleleft[1]);
	for (int h = 1; h < 101; h++)
	{
		boardgametotalmultiple[h][1] = boardgametotalmultiple[h][1] * ratio;
	}
	commonboardgametotalmultipleleft[1] = commonboardgametotalmultipleleft[1] * ratio;
	commonboardgametotalmultipleadded[1] = logprefgamewholemultiple - commonboardgametotalmultipleleft[1];
}
void prefcommonboardlogwholemultiple1()
{
	logprefgamewholemultiple = logprefwholemultipleadded + logprefwholemultipleleft
		- logprefwholemultipletaken*(1 + prefinterest);
	if (turnsofdice % 3000 == 0)
		printf("logprefwholemultipletaken %.f", logprefwholemultipletaken);
	logprefwholemultipletaken = 0;
	float ratio = logprefgamewholemultiple / (logprefwholemultipleadded + logprefwholemultipleleft);
	for (int h = 1; h < 101; h++)
	{
		boardgametotalmultiple[h][1] = boardgametotalmultiple[h][1] * ratio;
	}
	logprefwholemultipleleft = logprefwholemultipleleft * ratio;
	logprefwholemultipleadded = logprefgamewholemultiple - logprefwholemultipleleft;
}
void prefcommonboardallocatemultiple3(int h)
{
	if (prefboardgametotalmultiple[h] >(logprefwholemultipleleft) * 10)
	{
		logprefwholemultipleleft = logprefwholemultipleleft + (prefboardgametotalmultiple[h] / 200);
		//prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * 0.995;
		logprefwholemultipletaken = logprefwholemultipletaken + prefboardgametotalmultiple[h];
		prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * 1.995;
	}
	else if (prefboardgametotalmultiple[h] > (logprefwholemultipleadded / 240))
	{
		if (prefboardgametotalmultiple[h] < logprefwholemultipleleft * 2)
		{
			//logprefwholemultipleleft = logprefwholemultipleleft - (prefboardgametotalmultiple[h] / 20);
			logprefwholemultipletaken = logprefwholemultipletaken + prefboardgametotalmultiple[h] * 10;
			prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * 11;
		}
		else
		{
			//logprefwholemultipletaken = logprefwholemultipletaken + prefboardgametotalmultiple[h] / 200;
			//prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * 1.005;
		}
	}
	else if (prefboardgametotalmultiple[h] < (logprefwholemultipleadded / 3000))
	{
		logprefwholemultipleleft = logprefwholemultipleleft + prefboardgametotalmultiple[h];
		prefboardgametotalmultiple[h] = logprefwholemultipleleft / 1000;
		logprefwholemultipleleft = logprefwholemultipleleft - prefboardgametotalmultiple[h];
	}
	logprefwholemultipleadded = logprefwholemultipleadded + prefboardgametotalmultiple[h];
}
void prefcommonboardlogmultiple2(int h)
{
	logprefwholemultipleadded = logprefwholemultipleadded - prefboardgametotalmultiple[h];
	turnsasmoneytakeninx = 0;
	gameturnmultiple = ((10000 - basispoint) / 10000)*(turnsasmoneytakeninx + 1)
		- turnsasmoneytakeninx*(1 + interest)
		+ ((basispoint / (boardturnsofdiceforagame[h] * 350)))*(turnsasmoneytakeninx + 1);
	prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * gameturnmultiple;
	prefcommonboardallocatemultiple3(h);
	gameturnmultiple = 1;
}
void boardnumberofGames2(int h)
{
	boardpos[h] = boardpos[h] - 100;
	//System.out.println("turnsofgame="+turnsofgame);
	//System.out.println("position="+pos);
	boardturnsofgame[h]++;
	prefcommonboardlogmultiple2(h);
	boardturnsofdiceforagame[h] = 0;
}
void prefcommonboardlogtotalmultiple()
{
	//commonboardgametotalmultipleadded[1] = commonboardgametotalmultipleadded[1] + commonboardgametotalmultipleleft[1];
	logprefgamewholemultiple = logprefwholemultipleadded + logprefwholemultipleleft;
}
void prefcommonboardprintGameStats2()
{
	printf(" %.1f ", logprefgamewholemultiple);
	printf("\n");
	printf(" %.1f ", logprefwholemultipleadded);
	printf(" %.1f ", logprefwholemultipleleft);
	printf("\n");
	for (int h = 1; h<numberofboards; h++)
	{
		printf(" %.1f ", prefboardgametotalmultiple[h]);
	}
	printf("\n");
	printf("snakes shuffled %d ", snakesshuffled);
	printf("ladders shuffled %d \n", laddersshuffled);
	printf("\n");
}
void prefcommonboardrunGames2()
{
	for (int i = 0; i < 1; i++)
	{
		prefboardrunGames2();
		//struct gamestate prefgamestate1 = gamestatestruct();
		prefgamestate = gamestatestruct();
		printf("%.1f",prefgamestate.logprefgamewholemultiple);
		turnsofdice = 0;
		//prefcommonboardprintGameStats3();
	}
}
void prefboardrunGames2()
{
	gameturnmultiple = 1;
	turnsasmoneytakeninx = 0;
	logprefgamewholemultiple = 1;
	logprefwholemultiple = 0;
	logprefwholemultipletaken = 0;
	logprefwholemultipleadded = 1;
	logprefwholemultipleleft = 1;
	for (int h = 1; h<numberofboards; h++)
	{
		boardpos[h] = 1;
		boardturnsofdiceforagame[h] = 0;
		boardturnsofgame[h] = 0;
		prefboardgametotalmultiple[h] = 0.01;
		for (int i = 1; i<boardsize; i++)
		{
			boardstates[h][i] = 0;
			boardlIndex[h][i] = 0;
			boardsIndex[h][i] = 0;
		}

		for (int i = 1; i < 12; i++)boardladderHit[h][i] = 0;
		for (int i = 1; i < 11; i++)boardsnakeHit[h][i] = 0;
		prefboardfillLaddersrand(h);
		prefboardfillSnakesrand(h);
	}
	//prefboardfillLaddersrand();
	//prefboardfillSnakesrand();
	while (turnsofdice<numberofdiceturns)
	{
		boardDice();
		boardTurnsofDice();
		for (int h = 1; h < numberofboards; h++)
		{
			if (boardpos[h] > boardsize-1)boardnumberofGames2(h);
			boardSnakesLadders();
		}
		prefboardshuffleSnakesLaddersrand();
		//prefboardshuffleSnakesrand();
		//prefboardshuffleLaddersrand();
		if (turnsofdice % 30 == 0)
			prefcommonboardlogwholemultiple2();
		//if (turnsofdice % 3000 == 0)
		//prefcommonboardprintGameStats3();
	}
	prefcommonboardlogtotalmultiple();
}
void prefboardfillLaddersrand(int h)
{
	for (int i = 0; i<11; i++)
	{
		if ((rand() % 6) > 2)
		{
			boardstates[h][ladderStart[i]] = ladderEnd[i];
			boardlIndex[h][ladderStart[i]] = i + 1;
		}
	}
}
void prefboardfillSnakesrand(int h)
{
	for (int i = 0; i<10; i++)
	{
		if ((rand() % 6) > 2)
		{
			boardstates[h][snakeStart[i]] = snakeEnd[i];
			boardsIndex[h][snakeStart[i]] = i + 1;
		}
	}
}
void prefboardshuffleLaddersrand()
{
	for (int h = 1; h<numberofboards; h++)
	{
		if ((h * 1) == (rand() % numberofboards/2)+1)
		{
			//printf("shuffling ladders %d ", h);
			laddersshuffled++;
			for (int i = 1; i<boardsize; i++)
			{
				boardstates[h][i] = 0;
				boardlIndex[h][i] = 0;
				boardsIndex[h][i] = 0;
			}
			prefboardfillLaddersrand(h);
		}
	}
}
void prefboardshuffleSnakesrand()
{
	for (int h = 1; h<numberofboards; h++)
	{
		if ((h * 1) == (rand() % numberofboards/2)+1)
		{
			//printf("shuffling snakes %d ", h);
			snakesshuffled++;
			for (int i = 1; i<boardsize; i++)
			{
				boardstates[h][i] = 0;
				boardlIndex[h][i] = 0;
				boardsIndex[h][i] = 0;
			}
			prefboardfillSnakesrand(h);
		}
	}
}
void prefcommonboardlogwholemultiple2()
{
	logprefgamewholemultiple = logprefwholemultipleadded + logprefwholemultipleleft
		- logprefwholemultipletaken*(1 + prefinterest);
	//if (turnsofdice % 3000 == 0)
	//printf("logprefwholemultipletaken %.f", logprefwholemultipletaken);
	logprefwholemultipletaken = 0;
	float ratio = logprefgamewholemultiple / (logprefwholemultipleadded + logprefwholemultipleleft);
	for (int h = 1; h < numberofboards; h++)
	{
		prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h] * ratio;
	}
	logprefwholemultipleleft = logprefwholemultipleleft * ratio;
	logprefwholemultipleadded = logprefgamewholemultiple - logprefwholemultipleleft;
}
void prefcommonboardprintGameStats3()
{
	printf(" %.1f ", logprefgamewholemultiple);
	printf("\n");
	//printf(" %.1f ", logprefwholemultipleadded);
	//printf(" %.1f ", logprefwholemultipleleft);
	printf("\n");
	printf("\n");
}
void prefboardshuffleSnakesLaddersrand()
{
	for (int h = 1; h<numberofboards; h++)
	{
		int k = (rand() % numberofparts) + 1;
		if ((h * 1) == (rand() % numberofboards / k) + 1)
		{
			//printf("shuffling snakes %d ", h);
			snakesshuffled++;
			for (int i = 1; i<boardsize; i++)
			{
				boardstates[h][i] = 0;
				boardlIndex[h][i] = 0;
				boardsIndex[h][i] = 0;
			}
			prefboardfillSnakesrand(h);
			prefboardfillLaddersrand(h);
		}
	}
}

struct gamestate gamestatestruct()
{
	struct gamestate p;
	p.logprefgamewholemultiple = logprefgamewholemultiple;
	p.logprefwholemultipletaken = logprefwholemultipletaken;
	p.logprefwholemultipleadded = logprefwholemultipleadded;
	p.logprefwholemultipleleft = logprefwholemultipleleft;
	for (int h = 1; h<numberofboards; h++)
	{
		p.boardpos[h] = boardpos[h];
		p.boardturnsofdiceforagame[h] = boardturnsofdiceforagame[h];
		p.boardturnsofgame[h] = boardturnsofgame[h];
		p.prefboardgametotalmultiple[h] = prefboardgametotalmultiple[h];
		for (int i = 1; i<boardsize; i++)
		{
			p.boardstates[h][i] = boardstates[h][i];
			p.boardlIndex[h][i] = boardlIndex[h][i];
			p.boardsIndex[h][i] = boardsIndex[h][i];
		}
		for (int i = 1; i < 12; i++)p.boardladderHit[h][i] = boardladderHit[h][i];
		for (int i = 1; i < 11; i++)p.boardsnakeHit[h][i] = boardsnakeHit[h][i];
	}
	return p;
}
