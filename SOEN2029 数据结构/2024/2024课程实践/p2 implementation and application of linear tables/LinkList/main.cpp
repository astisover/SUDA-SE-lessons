//main.cpp

#include "LinkList.h"
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

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Create SingleLink\n";
    cout << "2. Create IterSingleLink\n";
    cout << "3. Create DoubleLink\n";
    cout << "4. Insert Element\n";
    cout << "5. Delete Element by Index\n";
    cout << "6. Delete Element by Value\n";
    cout << "7. Display List\n";
    cout << "0. Exit\n";
}

void testFunction()
{
    LinkList* list = nullptr;
    int choice;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                vector<int> nums;
                int num;
                cout << "Enter numbers (end with -1): ";
                while (true)
                {
                    cin >> num;
                    if (num == -1) break;
                    nums.push_back(num);
                }
                list = new SingleLink(nums);
                cout << "SingleLink created." << endl;
                break;
            }
            
            case 2:
            {
                vector<int> nums;
                int num;
                cout << "Enter numbers (end with -1): ";
                while (true)
                {
                    cin >> num;
                    if (num == -1) break;
                    nums.push_back(num);
                }
                list = new IterSingleLink(nums);
                cout << "IterSingleLink created." << endl;
                break;
            }
            
            case 3:
            {
                vector<int> nums;
                int num;
                cout << "Enter numbers (end with -1): ";
                while (true)
                {
                    cin >> num;
                    if (num == -1) break;
                    nums.push_back(num);
                }
                list = new DoubleLink(nums);
                cout << "DoubleLink created." << endl;
                break;
            }
            
            case 4:
            {
                if (!list)
                {
                    cout << "Please create a list first!" << endl;
                    break;
                }
                int ind, val;
                cout << "Enter index and value to insert: ";
                cin >> ind >> val;
                list->insert(ind, val);
                break;
            }
            
            case 5:
            {
                if (!list)
                {
                    cout << "Please create a list first!" << endl;
                    break;
                }
                int ind;
                cout << "Enter index to delete: ";
                cin >> ind;
                list->deleteByIndex(ind);
                break;
            }
            
            case 6:
            {
                if (!list)
                {
                    cout << "Please create a list first!" << endl;
                    break;
                }
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                list->deleteByNum(val);
                cout << "Deleted element with value " << val << "." << endl;
                break;
            }
            
            case 7:
            {
                if (!list)
                {
                    cout << "Please create a list first!" << endl;
                    break;
                }
                cout << "Current list: ";
               	list->display();
                cout << endl;
                break;
            }
            
            case 0:
                cout << "Exiting..." << endl;
                delete list;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


void cardsInput(stringstream &ss, vector<int> &color, vector<int> &cards)
{
	int number;
	while(ss >> number)
	{
		color[number] ++;
		cards.push_back(number);
	}
	sort(cards.begin(), cards.end());
}

void cardsDisplay(int n, vector<vector<SingleLink*> > &allCards)
{
	for(int i = 0; i < n; i ++)
	{
		cout << "the " << i << "-th card" << endl;
		for(int j = 0; j < 4; j ++)
		{
			switch (j)
			{
				case 0:
					cout << "spade:";
					break;
					
				case 1:
					cout << "heart:";
					break;
					
				case 2:
					cout << "club:";
					break;
						
				case 3:
					cout << "diamond:";
					break;
			}
			ListNode* p = allCards[i][j]->dummyHead->next;
			while(p != nullptr)
			{
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
		cout << endl;
	}
}

void cardsCount(string &filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cerr << "Unable to open the file for reading!" << endl;
		return;
	}
	
	string line;
	int n, count;  
	ifs >> n;
	getline(ifs, line);
	vector<vector<SingleLink*> > allCards(n, vector<SingleLink*>(4));	
	vector<int> spade(14, 0);
	vector<int> heart(14, 0);
	vector<int> club(14, 0);
	vector<int> diamond(14, 0);
	
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < 4; j ++)
		{
			getline(ifs, line);
			vector<int> cards;
			stringstream ss(line);
			ss >> count;
			switch (j)
			{
				case 0:
					cardsInput(ss, spade, cards);
					break;
					
				case 1:
					cardsInput(ss, heart, cards);
					break;
					
				case 2:
					cardsInput(ss, club, cards);
					break;
						
				case 3:
					cardsInput(ss, diamond, cards);	
					break;
			}
			allCards[i][j] = new SingleLink(cards);
		}
	}
	
	int minNum = n;
	vector<vector<int> > arrays = {spade, heart, club, diamond};
	for(const auto& array : arrays)
	{
		for(int i = 1; i < 14; i ++)
		{
			if(array[i] < minNum)
				minNum = array[i];
			cout << array[i] << " ";
		}
		cout << endl;
	}
	cardsDisplay(n, allCards);

	cout << minNum << endl;
	
	vector<vector<int> > cardsUtil(4, vector<int>(13, minNum));
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < 4; j ++)
		{
			for(int k = 0; k < 13; k ++)
			{
				if(cardsUtil[j][k] > 0)
				{
					if(allCards[i][j]->deleteByNum(k + 1))
						cardsUtil[j][k] --;
				}
			}
		}
	}
	
	cardsDisplay(n, allCards);
}	

int main()
{
    //testFunction();
    string filename = "cards.txt";
    cardsCount(filename);
    
    return 0;
}
