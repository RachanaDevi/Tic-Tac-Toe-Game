#include<iostream>
//intitalization of board
//showing the board
//inserting X O in board
//to see if game has ended
//to declare the winner
using namespace std;
char board[3][3];
char *move[10];
void showBoard();
bool gameEnded();
void initializeBoard();
bool diagonalWin();
bool columnWin();
bool rowWin();
void display();
bool occupied();
int flag=0;

class person  
{
	protected:
   // int chance;
	char input;
	public:
	person(/*int c,*/char i)
	{
		input=i;
	//	chance=c; 
		//chance of player is 1
		
	}
	char returnInput()
	{
		return input;
	}
	void makeMove(int);
};
bool occupied()//CODE TO CHECK IF IT HAS RESULTED IN DRAW SO TRAVERSE ALL INDICES AND CHECK IF ALL ' ' OR NOT
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			
			if(board[i][j]!='O' && board[i][j]!='X')
			{
			
			return false;
		    }
		}
	}
	flag=1;
	cout<<"\nflag value="<<flag;
	return true;
	
	//AFTER WRITING THIS CHANGE THE MAIN CODE A LITTLE BIT AS IT STILL SHOWS WHICH PLAYER WON
}
bool gameEnded()
{
	if(columnWin()|| diagonalWin()||  rowWin() || occupied()) 
	return true;
	
	return false; 
}
bool diagonalWin()
{
	if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])
	||((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])))
	return true;
	
	return false;
}

bool columnWin()
{
   for(int i=0;i<3;i++)
   {
   		if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i]))
   		return true;

   }
	return false;
}

bool rowWin()
{
   for(int i=0;i<3;i++)
   {
   		if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2]))
   		return true;

   }
	return false;
}
void display()
{ printf("\n\n");
     
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);
}
void initializeBoard()
{
	int k=1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=k+'0';
			move[k]=&board[i][j];
			k++;
			
		}
		
	}
	
}
void person::makeMove(int block)
{
	char block1=block+'0';
	cout<<"VALUE OF BLOCK1="<<block1;
	//cout<<endl<<"MOVE BLOCK's value'="<<*move[block]<<endl<<block+'0'<<" is it same?="<<(*move[block]==block)+'0';
   if(*move[block]==block1)
   {
   	 *move[block]=returnInput();
   }
   else
   {
   	cout<<"\nAlready occupied!!\nEnter another block";
   	cin>>block;
   	makeMove(block);
   }
	
}

int main()
{
	int i=0,block;
	initializeBoard();
	person p[2]={person('X'),person('O')}; //First object of computer or for now 1st player ,2nd object of 2nd player
   do
	{
		system("cls");
		display();

		
	
		jmp:cout<<"PLAYER "<<i+1<<" TURN";
		cout<<"\nEnter the block in which you want to enter";
		cin>>block;
			if(block >9)
			{
				goto jmp;
			}
		p[i].makeMove(block);
		if(gameEnded())
		break;
		i=i?0:1;
    
	  

		
	}while(!gameEnded());
	system("cls");
	display();
	if(flag==0)
	cout<<"\nGame Ended!!The player who has won is  "<<i+1;
	else
	cout<<"\nGame Ended!!Its a draw ";
	
	
	
}
