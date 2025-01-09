//main.cpp

#include "ArrayList.h"
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

void testUnOrderedArrayList(int count) 
{
 	UnOrderedArrayList list(count);
    char command;
    int value, index;

    cout << "Testing UnorderedArrayList:" << endl;

    while (true) 
	{
        cout << "Enter command (A=append, I=insert, R=replace, G=get, D=display, Q=quit): ";
        cin >> command;

        if (command == 'Q' || command == 'q') break;

        switch (command) 
		{
	        case 'A':
	            cout << "Enter value to append: ";
	            cin >> value;
	            list.append(value);
	            break;
	            
	        case 'I':
	            cout << "Enter index and value to insert: ";
	            cin >> index >> value;
	            list.insert(index, value);
	            break;
	            
	        case 'R':
	            cout << "Enter index and value to replace: ";
	            cin >> index >> value;
	            list.replace(index, value);
	            break;
	            
	        case 'G':
	            cout << "Enter index to get: ";
	            cin >> index;
	            cout << "Value at index " << index << " is ";
				list.get(index);
				cout << endl;
	            break;
	            
	        case 'D':
	            list.display();
	            break;
	            
	        default:
	            cout << "Invalid command!" << endl;
        }
    }
}

void testOrderedArrayList(int count) 
{
    OrderedArrayList list(count);
    char command;
    int value, index;

    cout << "Testing OrderedArrayList:" << endl;

    while (true) 
	{
        cout << "Enter command (V=insertByvalue, L=InsertByLocation, R=replace, D=display, Q=quit): ";
        cin >> command;

        if (command == 'Q' || command == 'q') break;

        switch (command) 
		{
	        case 'V':
	            cout << "Enter value to insert: ";
	            cin >> value;
	            list.insertByValue(value);
	            break;
	            
	        case 'L':
	        	cout << "Enter value to insert: ";
	        	cin >> value;
	        	cout << "Enter index to insert: ";
	        	cin >> index;
	        	list.insertByLocation(index, value);
	        	break;
	        	
	        case 'R':
				cout << "Enter value to replace: ";
	        	cin >> value;
	        	cout << "Enter index to replace: ";
	        	cin >> index;
	        	list.replaceAndSort(index, value);
	        	break;
				
	        case 'D':
	            list.display();
	            break;
	            
	        default:
	            cout << "Invalid command!" << endl;
        }
    }
}

int main() 
{
    char listType;
    int count = 0;
    cout << "Which list to test? (U=unordered, O=ordered): ";
    cin >> listType;
    cout << "The lenth of array: ";
    cin >> count;

    if (listType == 'U' || listType == 'u') 
        testUnOrderedArrayList(count);
    
	else if (listType == 'O' || listType == 'o') 
        testOrderedArrayList(count);
    
	else 
        cout << "Invalid list type!" << endl;

    return 0;
}
