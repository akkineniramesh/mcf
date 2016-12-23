import java.util.*;
import java.io.*;
//"C:\Program Files\Java\jdk1.5.0_01\bin\javac.exe" SnakesnLadders.java
//java SnakesnLadders sal.txt
/*3 7 9
1 2 3 4 5 6 7 8 9 10
100000
1000000
8 19 21 28 36 43 50 54 61 62 66
26 38 82 53 57 77 91 88 99 96 87
98 93 83 69 68 64 59 52 48 46
13 37 22 33 2 24 18 11 9 15*/
class SnakesnLadders 
{
	int pos=1,turnsofdice=0,turnsofgame=0;
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
	Random r= new Random();
	String args;
	public static void main(String[] args) 
	{
		SnakesnLadders sal=new SnakesnLadders();
		sal.runGame(args[0]);
		//System.out.println("Hello World!");
	}
	void runGame(String args1)
	{
		args=args1;
		for(int i=1;i<101;i++)
		{
			a[i]=0;
			lIndex[i]=0;
			sIndex[i]=0;
		}
		getSnakesLadders(args);
		System.out.println("turnsasmoneyatstart="+turnsasmoney);
		fillLadders();
		fillSnakes();
		/*while(((turnsofgame<numberofgames)||(turnsofdice*3.5)<(numberofgames*100))
			&&((turnsofdice<numberofdiceturns)||(turnsofdice*3.5)<(turnsofgame*100)))*/
		while(turnsofdice<numberofdiceturns)
		{
				pos=Dice();
				TurnsofDice();
				if(pos>100)numberofGames();
				pos=SnakesLadders();
		}
		System.out.println("turnsofdice="+turnsofdice);
		System.out.println("turnsofgame="+turnsofgame);
		System.out.println("numberofdiceturns="+numberofdiceturns);
		System.out.println("turnsofdiceindistance="+(long)(turnsofdice*3.5));
		System.out.println("turnsasmoney="+(long)turnsasmoney);
		//System.out.println("numberofdiceturnsindistance="+(long)(numberofdiceturns*3.5));
		System.out.println("pos="+pos);
		for (int i=1;i<=11;i++ )
			System.out.println("LadderHit"+i+"="+ladderHit[i-1]);
		for (int i=1;i<=10;i++ )
			System.out.println("SnakeHit"+i+"="+snakeHit[i-1]);
		System.out.println("game over");
	}
	void getSnakesLadders(String args1)// throws IOException
	{
		FileReader fr;
		BufferedReader br;
		//BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String[] str=new String[8];
		String[] s= new String[11];
		int in;
		int tokenCount;
		try
		{
			fr=new FileReader(args1);
			br= new BufferedReader(fr);
			for(int k=0;k<8;k++)
			{
				str[k]=br.readLine();
				StringTokenizer strtkn=new StringTokenizer(str[k]);
				tokenCount=strtkn.countTokens();
				while(strtkn.hasMoreTokens())
				{
					for(int i=0;i<tokenCount;i++)s[i]=strtkn.nextToken();
				}
				try
				{
					for(int i=0;i<tokenCount;i++)
					{
						in=Integer.parseInt(s[i]);
						if(k==0)lIndex[ladderStart[in-1]]=i+1;
						if(k==1)sIndex[snakeStart[in-1]]=i+1;
						if(k==2)numberofdiceturns=in;
						if(k==3)turnsasmoney=in*3.5;
						if(k==4)basispoint=in;
						if(k==5)ladderStart[i]=in;
						if(k==6)ladderEnd[i]=in;
						if(k==7)snakeStart[i]=in;
						if(k==8)snakeEnd[i]=in;
					}
				}
				catch(Exception e){System.out.println("enter integer");}
			}
		}
		catch(IOException ioe){System.out.println("enter integer");}
		//catch(FileNotFoundException fnf){System.out.println("enter file");}
	}

	void fillLadders()
	{
		for (int i=0;i<11;i++ )
		{
			if(lIndex[ladderStart[i]]!=0)
			{
				a[ladderStart[i]]=ladderEnd[i];
				lIndex[ladderStart[i]]=i+1;
			}
		}
	}
	void fillSnakes()
	{
		for (int i=0;i<10;i++ )
		{
			if(sIndex[snakeStart[i]]!=0)
			{
				a[snakeStart[i]]=snakeEnd[i];
				sIndex[snakeStart[i]]=i+1;
			}
		}
	}
	int SnakesLadders()
	{
		if(a[pos]!=0)
		{
			if(lIndex[pos]!=0)ladderHit[lIndex[pos]-1]++;
			if(sIndex[pos]!=0)snakeHit[sIndex[pos]-1]++;
			//if(pos>a[pos])System.out.println("snakehit"+pos);
			//if(pos<a[pos])System.out.println("ladderhit"+pos);
			pos=a[pos];
		}
		return pos;
	}
	int Dice()
	{
		int d=r.nextInt(6)+1;
		//System.out.println("dice="+d);
		pos=pos+d;
		//System.out.println("position"+pos);
		return pos;
	}
	void TurnsofDice()
	{
		turnsofdice++;
		turnsofdiceforagame++;
	}
	void numberofGames()
	{
		pos=pos-100;
		//System.out.println("turnsofgame="+turnsofgame);
		//System.out.println("position="+pos);
		turnsofgame++;
		turnsasmoney=turnsasmoney*(((10000-basispoint)/10000)+(basispoint/(turnsofdiceforagame*350)));
		turnsofdiceforagame=0;
		//if(turnsofgame%35==0)numberofdiceturns=numberofdiceturns+100;
	}

}
