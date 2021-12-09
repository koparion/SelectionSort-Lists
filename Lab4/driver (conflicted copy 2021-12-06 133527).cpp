//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "ArrayList.h" // ADT list operations
#include <iostream>
#include <string>
#include "LinkedList.h"
#include <fstream>

using namespace std;

// selection sort
void selectionSort(ListInterface<int> &array) 
{
	int i, j, minIndex;
		if (array.getLength() != NULL)
		{
			cout << "IndexSize: " << array.getLength() << endl;
			for (int i = 1; i <= array.getLength(); i++) // displaying inside selection
			{
				cout << array.getEntry(i) << " ";
			}
			cout << endl;
			for (i = 1; i <= array.getLength() - 1; i++)//first loop
			{
				//cout << "first loop " << i << endl;
				minIndex = i;   //get index of minimum data
				cout << "minIndex(i): " << minIndex << endl;
				for (j = i + 1; j <= array.getLength(); j++) //nested loop
				{
					//cout << "second loop " << j << endl;
					if (array.getEntry(j) < array.getEntry(minIndex)) //looking to see if smallest number is further down
					{
						minIndex = j;
						cout << "minIndex(j): " << minIndex << endl;
					}
				}
				int swap = array.getEntry(i);
				array.replace(i, array.getEntry(minIndex));
				array.replace(minIndex, swap);
			}
		}
		else 
		{
			cout << "list is empty, can't be sorted\n";
		}
}

int main()
{
	ArrayList<int> arr; //arraylist instance
	LinkedList<int> list; //linkedlist instance
	fstream file;
	
	file.open("file.txt");
	
	/*if (file.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }*/
	try {
		if (file.is_open()) 
		{
			int i = 0;
			int var;

			while (file >> var)
			{
				cout << "inserting " << var << " inside list." << endl;
				arr.insert(i + 1, var);
				list.insert(i + 1, var);
				i++;
			}
		}
		else { throw PrecondViolatedExcep(); }
	}
	catch(...)
	{
		cout << "file did not open\n";
		//exit(1);
	}
	try {
		if (arr.getLength() != NULL)
		{
			cout << "\nArray list count: " << arr.getLength() << endl;
			arr.print();
			selectionSort(arr);
			cout << "Array List Sorted: \n";
			arr.print();
		}
		else 
		{
			throw NULL;
		}
	}
	catch (int)
	{
		cout << "Array List is empty.\n";
	}
	
	try
	{
		if (list.getLength() != NULL)
		{
			cout << "\n\nLinked List count: " << list.getLength() << endl;
			list.print();
			selectionSort(list);
			cout << "LinkedList Sorted: \n";
			list.print();
		}
		else
		{
			throw NULL;
		}
	}
	catch (...)
	{
		cout << "LinkedList is empty.\n";
	}
	

	file.close();

   return 0;
}  // end main
