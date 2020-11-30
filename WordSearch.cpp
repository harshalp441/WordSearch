#include <iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;


string random_array[15];
int p=0;

bool condition=false;

class Words
{	public:
	string words_arr[15];
	

	
	Words(string s_array[])
	{
		for(int i=0;i<15;i++)
		{
			words_arr[i]=s_array[i];
		}
	}
};



class Grid
{	public:
	char arr[15][15];
	char solution[15][15];
	void arrange_words(Words);
	void print_solution();
	void print_grid(char[]);

};


void Grid::arrange_words(Words ob)
{	
	
		memset(arr, '0', 225);
		
		for(int a=0;a<10;a++)
	
	{		int ch;
			ch=rand()%2;
			switch(ch)
		{          case 0:
						{
						
		
							
							A:	
								int i=rand()%15;
								int stored_i=i;
								int j=rand()%15;
								int stored_j=j;
								int x=0;
								if(15-j>=ob.words_arr[a].length())
								{	for(j,x;ob.words_arr[a][x]!='\0';j++,x++)
										{
											if(arr[i][j]=='0' || arr[i][j]==ob.words_arr[a][x])
											condition=true;
											else
											goto A;
										}
								
								}
								
								else 
								goto A;	
								
								
								if(condition==true)
								{	
									random_array[p]=ob.words_arr[a];
									
									p++; 
									
									
									
									
									for(stored_j,x=0;ob.words_arr[a][x]!='\0';stored_j++,x++)
									{
										arr[stored_i][stored_j]=ob.words_arr[a][x];
									}
								}
							
						}
						break;
						
						
						
						
						
						
						
						case 1:
							{	
							B:	 
								 int i=rand()%15;
								 int stored_i=i;
								 int j=rand()%15;
								 int stored_j=j;
								 int x=0;
								if(15-i>=ob.words_arr[a].length())
								{	for(i,x;ob.words_arr[a][x]!='\0';i++,x++)
										{
											if(arr[i][j]=='0' || arr[i][j]==ob.words_arr[a][x])
											condition=true;
											else
											goto B;
										}
										
								
								}
								
								else 
								goto B;	
								
								
								if(condition==true)
								
								{   random_array[p]=ob.words_arr[a];
								    
									p++;  
									
								
									for(stored_i,x=0;ob.words_arr[a][x]!='\0';stored_i++,x++)
									{
										arr[stored_i][stored_j]=ob.words_arr[a][x];
									}
								}
								
								
								
							}
							break;
		
		
		
		}
			
	}
	
	
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			solution[i][j]=arr[i][j];
		}
	}		
		
}


void Grid::print_grid(char character_arr[])
{
		
			   for(int i=0;i<15;i++)
			{	
			    for(int j=0;j<15;j++)
			    {	if(arr[i][j]=='0')
			        arr[i][j]=character_arr[rand()%26];
			    }
			}
					
			
			
			
			
			   
				for(int i=0;i<15;i++)
			{	cout<<setw(60);
			    for(int j=0;j<15;j++)
			    {
			        cout<<arr[i][j]<<" ";
			    }
			    cout<<endl;
			}
}

void Grid::print_solution()
{
		for(int i=0;i<15;i++)
			{	cout<<setw(60);
			    for(int j=0;j<15;j++)
			    {
			        cout<<solution[i][j]<<" ";
			    }
			    cout<<endl;
			}
}





int main()
{	
	srand(time(NULL));


	string user_word;
	int choice;
	char character_arr[]="abcdefghijklmnopqrstuvwxyz";

	
	
	cout<<"\n\nWelcome to The word search game!!!\n";

	
	Grid g;
	
	
	
	
		
	string festivals_array[]={"diwali","dussehra","holi","halloween","pongal","eid","christmas","onam","navaratri","bihu"};
	string animals_array[]={"lion","tiger","elephant","cow","giraffe","zebra","dog","cat","yak","monkey"};
	string countries_array[]={"india","australia","nepal","bangladesh","egypt","france","indonesia","newzealand","brazil","mexico"};
	string cities_array[]={"indore","bhopal","mumbai","ujjain","kolkata","pune","ahmedabad","surat","chennai","haridwar"};
	string fruits_array[]={"apple","mango","banana","pineapple","guava","grapes","kiwi","strawberry","papaya","watermelon"};
	string stationery_array[]={"pencil","pen","scale","eraser","rounder","divider","protractor","scissors","",""};


    int choice1;
    choice1=rand()%6;
    
    switch(choice1)
    {
    			{
				case 0:
			    Words w1(festivals_array);
				g.arrange_words(w1);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Festivals";
				break;
		    	}
				
				{
				case 1:
			    Words w2(animals_array);
				g.arrange_words(w2);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Animals";
				break;
				}
				
				{
				case 2:
			    Words w3(countries_array);
				g.arrange_words(w3);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Countries";
				break;
				}
				{
				case 3:
				Words w4(cities_array);
				g.arrange_words(w4);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Cities";
				break;
				}
				
				{
				case 4:
				Words w5(fruits_array);
				g.arrange_words(w5);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Fruits";
				break;
				}
				
				{
				case 5:
				Words w6(stationery_array);
				g.arrange_words(w6);
				cout<<"\n\n\t\t\t\t\t\t\tCategory: Stationery tools";
				break;
				}
	}

	

	
	
	
	
	cout<<"\n\nFind 10 words related to category in the grid:\n\n";
	g.print_grid(character_arr);

	

	float score=0;
	for(int i=0;i<10;i++)
	{	condition=false;
		cout<<"\n\t\t\t\t\t\tPress '0' to surrender";
		cout<<"\nEnter word: ";
		cin>>user_word;
		if(user_word=="0")
		break;
		for(int j=0;j<10;j++)
		{
			if(random_array[j]==user_word)
			{
			condition=true;
			score++;
			break;
			}
		}
			
			if(condition==false)
			{
			cout<<"wrong word(doesn't match the category)";
			
			}
			
			cout<<"\t"<<10-i-1<<" moves left.";
			
	}
		

	
	cout<<"\n\nFinal Score(%): "<<(score/10)*100<<endl<<endl;
	
    g.print_solution();
			
	

	return 0;
}
