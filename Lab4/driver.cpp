

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
			//cout << "IndexSize: " << array.getLength() << endl;
			//for (int i = 1; i <= array.getLength(); i++) // displaying inside selection
			//{
			//	cout << array.getEntry(i) << " ";
			//}
			//cout << endl;
			for (i = 1; i <= array.getLength() - 1; i++)//first loop
			{
				//cout << "first loop " << i << endl;
				minIndex = i;   //get index of minimum data
				//cout << "minIndex(i): " << minIndex << endl;
				for (j = i + 1; j <= array.getLength(); j++) //nested loop
				{
					//cout << "second loop " << j << endl;
					if (array.getEntry(j) < array.getEntry(minIndex)) //looking to see if smallest number is further down
					{
						minIndex = j;
						//cout << "minIndex(j): " << minIndex << endl;
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
	try // checking if file can be opened 
	{
		if (file.is_open()) 
		{
			int i = 0;
			int var;
			cout << "Inserting values: \t";
			while (file >> var) // inserting values into file
			{
				cout << var << ' ';
				arr.insert(i + 1, var); //inserting into array list
				list.insert(i + 1, var); //inserting into linkedlist
				i++;
			}
			cout << "\n\n";
		}
		else { throw PrecondViolatedExcep(); }
	}
	catch(...)
	{
		cout << "file did not open\n";
		exit(1);
	}
	try //array list
	{ 
		if (arr.getLength() != NULL)
		{
			cout << "Array list count: " << arr.getLength() << endl;
			cout << "preSorted List: \t";
			arr.print();
			selectionSort(arr);
			cout << "Array List Sorted: \t";
			arr.print();
		}
		else 
		{
			throw NULL;
		}
	}
	catch (...)
	{
		cout << "Array List is empty.\n";
	}
	try //linkedList
	{
		if (list.getLength() != NULL)
		{
			cout << "\n\nLinked List count: " << list.getLength() << endl;
			cout << "preSorted List: \t" ;
			list.print();
			selectionSort(list);
			cout << "LinkedList Sorted: \t";
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


//Inserting values :	2 5 8 1 5 3 4 8 6 0
// 
//Array list count : 10
//preSorted List :		2 5 8 1 5 3 4 8 6 0
//Array List Sorted :	0 1 2 3 4 5 5 6 8 8
//
//
//Linked List count : 10
//preSorted List :		2 5 8 1 5 3 4 8 6 0
//LinkedList Sorted :	0 1 2 3 4 5 5 6 8 8