#include<iostream>
#include<iomanip>jose
#include<string>
#include<Windows.h>
#include<cctype>
#include<cstdlib>
#include<ctime>

using namespace std;

void maps(string , string, int& , int&,int,int);
void welcome();
string menu2();
int flight(string,int &, int &);
int quantity(string, string);
int map[15][6];
void randn();
void change(int &, int &);
void receipt(string,string,int,int);

int main()
{   int rown=0, chairn=0;
	string name;
	welcome();
	name=menu2();
	flight(name,rown,chairn);
	 system("pause");
	 return 0;
}

void welcome()
{

	cout<<"\t\t\t\t   -WELCOME-\n\n\n";
	cout<<"\t\t\txxxx      x     x      x     x \n";
	cout<<"\t\t\tx       x   x   x      x     x  \n";
	cout<<"\t\t\txxxx   x xxx x  x      x     x  \n";
    cout<<"\t\t\tx      x     x  x       x   x   \n";
	cout<<"\t\t\tx      x     x  xxxx      x     \n\n";

	cout<<"\t\t   x    xxxxx xxx   x    xxxxx  xx    x xxxxx \n";
	cout<<"\t\t x   x    x   x  x  x      x    x x   x x \n";
	cout<<"\t\tx xxx x   x   xxx   x      x    x  x  x xxx \n";
	cout<<"\t\tx     x   x   x  x  x      x    x   x x x  \n";
	cout<<"\t\tx     x xxxxx x   x xxxx xxxxx  x    xx xxxxx \n";
	
	cout<<"\n\n\n\n\tPress enter twice to buy tickets";
	cin.ignore();
	cin.get();

}

string menu2()
{   system("cls");

	string name1, name2;
	cout<<"\t\t\t\t-FALU AIRLINES-		 \n\n\n";
	cout<<"\t\t\tPlease answer the followings questions";
	cout<<"\n\n\n\t\tFirst Name --> ";
	cin>>name1;
	
	for (int i=0;i<1;i++)
	{
		name1[i]=toupper(name1[i]);

		if (!isalpha(name1[i]))
		{   system("cls");
		
		MessageBoxA(NULL,"Invalid Name","Error",MB_OK);
		menu2();
		}
	}
	cout<<"\n\n\t\tLast Name --> ";
	cin>>name2;

	for (int z=0;z<1;z++)
	{
		name2[z]=toupper(name2[z]);
		if (!isalpha(name2[z]))
		{   system("cls");
		
		MessageBoxA(NULL,"  -Invalid Name","ERROR",MB_OK);
		menu2();
		}
	}
	
	
	string both = name1 + name2;
	
	return both;
}

int flight(string n,int &rown , int &chairn)
{   int choice, numtickets, price, pricex, class2,class3;
    string city, city2;
	char choiceclass, choiceagain;

	system("cls");

	cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\tUser: "<<n<<"\n\n\n\t\t\t      .Flights Available.\n\n\n\t\t1 - Sanjuan(PR)\t\tto\t\tOrlando(FL)\n\n\t\t2 - Sanjuan(PR)\t\tto\t\tCalifornia(LA)";
	cout<<"\n\n\n\n\tMy choice is --> # ";
	cin>>choice;

	while (choice<0 || choice>2 ) 
	{
		MessageBoxA(NULL,"Invalid Choice","Select a valid choice",MB_OK);
		flight(n,rown,chairn);
	}

	if (choice==1)
	{
		city = "Sanjuan(PR) to Orlando(FL)";
		city2 = "SJ(PR) to Or(FL)";
	}
	else if(choice==2)
	{
		city = "Sanjua(PR) to California(LA)";
		city2 = "SJ(PR) to Ca(LA)";
	}

	system("cls");

	cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\tUser: "<<n<<"\n\n\n\t\t  Types classes: "<<city<<"\n\n";
	cout<<"\n\t\t(F) First Class - $535 per chair\n\n\t\t(B) Business Class - $409 per chair\n\n\t\t(E) Economy Class - $345 per chair\n\n";
	cout<<"\n\n\tMy choice is --> ";
	cin>>choiceclass;


	randn();
	if(toupper(choiceclass) == 'F')
	{
		system("cls");
		class2 = 0;
		class3=2;
		numtickets=quantity(n,city2);
		for(int i=0;i<numtickets;i++)
		{
			maps(n,city2,rown,chairn,class2,class3);
			
		}
		price = 535;
		pricex = price * numtickets ;

	}
	else if(toupper(choiceclass) == 'B')
	{
		system("cls");
		class2  = 3;
		class3 =  6;
		numtickets=quantity(n,city2);
		for(int i=0;i<numtickets;i++)
		{
			maps(n,city2,rown,chairn,class2,class3);
			
		}
		price = 409;
		pricex = price * numtickets;

	}
	else if(toupper(choiceclass) == 'E')
	{
		system("cls");
		class2  = 7;
		class3 =  14;
		numtickets=quantity(n,city2);
		for(int i=0;i<numtickets;i++)
		{
			maps(n,city2,rown,chairn,class2,class3);
			
		}
		price = 345;
		pricex = price * numtickets;

	}
	else
		{
			system("cls");
			MessageBoxA(NULL,"Selection Not Exist","Invalid Choice",MB_OK);
			flight(n, rown, chairn);
		}

	receipt(n,city2,price,numtickets);
	cin>>choiceagain;
	if(choiceagain == 'Y' || choiceagain == 'y')
	{
		system("cls");
		main();
	}
	else if(choiceagain == 'N' || choiceagain == 'n')
	{
		return 0;
	}
	else
	{
		cout<<"\n\n\n\n\t\t\t\t-ERROR-\n\n\t\t\t\tINVALID ANSWER\n\n\t\t\t\tI WILL BEGIN AGAIN\n\n\n";
		cout<<"Press twice enter to continue";
		cin.ignore();
		cin.get();
	}

system("pause");
return 0;

}

void maps(string n, string c, int &rown, int &chairn,int class2, int class3)
{   
	system("cls");
	int ocu=0,ava=0, ocut=0, avat=0,val=0;
	int row, selection;
	char chair;
	
	cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\t\tUser: "<<n<<"\n";
	cout<<"\t* available\t\t\t\t\tFlight: "<<c<<"\n\tX occupied\n\n\n";
	cout<<"\t\t\t.Seats.\n\n";
	cout<<"\tFirst C\n\n";
	cout<<"\tA\tB\tC\tD\tE\tF\tOccupied   Available\n"<<endl;
	for(int x=0;x<15; x++)
	{   
		if(x==4)
		{
			cout<<"\tBusiness C\n\n";
		}
		else if(x==8)
		{
			cout<<"\tEconomy C\n\n";
		}
		cout<<"Row "<<x+1;
		ava-=ava;
		ocu-=ocu;
		for(int z=0;z<6;z++)
		{   cout<<"\t";
			if(map[x][z]==0)
			{    ava +=1;
				cout<<"*";
				avat+=1;
			}
			else if(map[x][z]==1)
			{   ocu +=1;
				cout<<"X";
				ocut+=1;
			}
		
		
		}
		cout<<"\t    "<<ocu<<"\t      "<<ava;
		cout<<endl<<endl;
		
		
	}
	cout<<"\n\t\t\t\t\t\tTotal\t   "<<ocut<<"        "<<avat;
	cout<<"\n\n\t\tSelect your method chooses\n\n\t\t\t1- Automatic\n\n\t\t\t2- Manual";
	cout<<"\n\n\t\t\tMy selection --> ";
	cin>>selection;
	if(selection == 1)
	{
		srand(time(0));
		val = 14-(class3+class2);
		row = (rand()% val + class2);
		row+=1;
		chairn = (rand()%6);

		if(chairn ==0)
		chair = 'A';
		else if(chairn ==1)
		chair = 'B';
		else if(chairn ==2)
		chair = 'C';
		else if(chairn ==3)
		chair = 'D';
		else if(chairn ==4)
		chair = 'E';
		else if(chairn ==5)
		chair = 'F';
		while( map[row-1][chairn] == 1)
		{   
			srand(time(0));
		row = rand()% val + class2;
		row+=1;
		chairn = (rand()%6);
		}
	}
	if(selection == 2)
	{
		cout<<"\n\nSelect row  --> ";
		cin>>row;
		cout<<"\nSelect chair --> ";
		cin>>chair;
	
	if(chair=='A' || chair == 'a')
		chairn = 0;
	else if(chair=='B'||chair=='b')
		chairn = 1;
	else if(chair=='C'||chair=='c')
		chairn = 2;
	else if(chair=='D'||chair=='d')
		chairn = 3;
	else if(chair=='E'||chair=='e')
		chairn = 4;
	else if(chair=='F'||chair=='f')
		chairn = 5;
	else
		chairn = 10;
	
	while(row-1<0 || row>14|| chairn >5)
	{	system("cls");

	MessageBoxA(NULL,"Select a valid choice","Invalid Choice",MB_OK);
	rown=0;
	chairn=0;
	maps(n,c,rown,chairn,class2,class3);
		
	}
	while(row-1<class2 || row-1>class3)
	{
		system("cls");
		MessageBoxA(NULL,"Row out of class","Invalid Choice",MB_OK);
		rown=0;
		chairn=0;
		maps(n,c,rown,chairn,class2,class3);
	}
	while( map[row-1][chairn] == 1)
	{
		system("cls");
		MessageBoxA(NULL,"This chair is not available","Invalid Choice",MB_OK);
		rown=0;
		chairn=0;
		maps(n,c,rown,chairn,class2,class3);
		
	}
	}
	map[row-1][chairn] = 1;
	rown=row;
	cout<<"\n\t\t\t\t\t\tRow\tSeat\n";
	cout<<"\t\t\t\tChosen seat  :  "<<row-1<<"\t"<<chair;
	cout<<"\n\n\n\nPress enter twice to continue";
	cin.ignore();
	cin.get();
	
	
}



void randn()
{
	srand(time(0));
	
	for(int i=0 ; i<15; i++)
	{
		for(int a=0;a<6;a++)
		{
			map[i][a] = (rand()%2);
		}
	}
}

void change(int &rown, int &chairn)
{
	
	map[rown][chairn] = (rand()%2);
}

int quantity(string n , string c)
{
	system("cls");
	int tickets;
	cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\t\tUser: "<<n<<"\n";
	cout<<"\t\t\t\t\t\t\tFlight: "<<c;
	cout<<"\n\n\n\t\tHow much tickets you want to buy?";
	cout<<"\n\n\t\tTickets --> ";
	cin>>tickets;

	while(isalnum(tickets))
	{
		system("cls");
		MessageBoxA(NULL,"Enter a number","Invalid Choice",MB_OK);
		cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\t\tUser: "<<n<<"\n";
		cout<<"\t\t\t\t\t\t\tFlight: "<<c;
		cout<<"\n\n\n\t\tHow much tickets you want to buy?";
		cin>>tickets;
	}
	return tickets;
}

void receipt(string n, string c, int p, int nt)
{
	system("cls");
	int ivu = (p*nt)*0.07;
	cout<<"\t\t\t\t-FALU AIRLINES-\n\t\t\t\t\t\t\tUser: "<<n<<"\n";
	cout<<"\t\t\t\t\t\t\tFlight: "<<c<<"\n\n\n";
	cout<<"\t\t\t\t   .RECEIPT.\n\n";
	cout<<"\t\t\t\t 1-800-AIR-FALU\n\t\t\t\t   Sanjuan(PR)\n\t\t\t\t   16/12/2013\n\n";
	cout<<"\t\t\t  Price per seat -- $ "<<p<<endl;
	cout<<"\t\t\t  Tickets sold   --   "<<nt<<endl;
	cout<<"\t\t\t  Ivu	0.07%   -- $ "<<ivu<<endl;
	cout<<"\t\t\t  Total Amount   -- $ "<<(p*nt)+ ivu;
	cout<<"\n\n\n\t\tWant a buy another ticket?(Y/N)";

	
}