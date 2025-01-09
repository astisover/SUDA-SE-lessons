//main.cpp
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

void allPrint(Queue<int> &p1, Queue<int> &p2, Stack<int> &cardBoard)
{
	cout << "p1: ";
	p1.printOut();
	
	cout << "p2: ";
	p2.printOut();
	
	cout << "cardBoard: ";
	cardBoard.printOut();
	
	cout << endl;
}


void catFishingGame()
{
	map<int, int> mymap;
	Queue<int> p1, p2;
	Stack<int> cardBoard, cardBasket;
	int n1, n2, card1, card2, card;
	
	cout << "This is cat fishing game. You should make sure about the rules.\n";
	cout << "2-10: 2-10, J-A: 11 12 13 1\n";
	cout << "The numbers of cards of p1: ";
	cin >> n1;
	cout << "The cards of p1:\n";
	for(int i = 0; i < n1; i ++)
	{
		cin >> card1;
		p1.push(card1);
	}
	
	cout << "The numbers of cards of p2: ";
	cin >> n2;
	cout << "The cards of p2:\n";
	for(int i = 0; i < n2; i ++)
	{
		cin >> card2;
		p2.push(card2);
	}
	
	cout << endl;
	allPrint(p1, p2, cardBoard);
	
	if(p1.isEmpty())
		cout << "p1 win the game!\n";
	else if(p2.isEmpty())
		cout << "p2 win the game!\n";
		
	while(!p1.isEmpty() && !p2.isEmpty())
	{
		card1 = p1.pop();
		if(mymap.count(card1))
		{
			while(cardBoard.peek() != card1)
				cardBasket.push(cardBoard.pop());
			cardBasket.push(cardBoard.pop());
			
			while(!cardBasket.isEmpty())
			{
				card = cardBasket.pop();
				p1.push(card);
				mymap.erase(card);
			}	
			p1.push(card1);
			
			cout << "p1 get\n";
			allPrint(p1, p2, cardBoard);
		}
		
		else
		{
			if(p1.isEmpty())
			{
				cout << "p1 win the game!\n";
				break;
			}	
			mymap[card1] = 1;
			cardBoard.push(card1);
		}
		
		card2 = p2.pop();
		if(mymap.count(card2))
		{
			while(cardBoard.peek() != card2)
				cardBasket.push(cardBoard.pop());
			cardBasket.push(cardBoard.pop());
			
			while(!cardBasket.isEmpty())
			{
				card = cardBasket.pop();
				p2.push(card);
				mymap.erase(card);
			}	
			p2.push(card2);
			
			cout << "p2 get\n";
			allPrint(p1, p2, cardBoard);
		}
		
		else
		{
			if(p2.isEmpty())
			{
				cout << "p2 win the game!\n";
				break;
			}
			mymap[card2] = 1;
			cardBoard.push(card2);
		}
	}
}


int main(int argc, char** argv) 
{
	catFishingGame();
	return 0;
}
