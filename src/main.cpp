#include "header.h"

int main(int argc, char *argv[])
{
	if(argc <= 1 || argc > 2) //Check if there are any arguments
	{
		cerr << "Error: arguments\n";
		return 84;
	}
	else if (strcmp(argv[1], "-h") == 0) //Check for the -h command
	{
		cout << "USAGE\n\t./301dannon file\nDESCRIPTION\n\tfile\tfile that contains the numbers to be sorted, seperated by spaces" << endl;
		return 0;
	}

	ifstream file(argv[1]);
	vector<float> list;
	if(file) //Check if the file exists
		list = fileToList(file);
	else 
	{
   		cerr << "File Error\n";
		return 84;
	}
	
	if(list.size() == 0) //Check for file invalid
		return 84;
	cout << list.size(); //Print element/s
	if(list.size() > 1)
		cout << " elements\n";
	else
		cout << " element\n";

	//Test each alg and print comparisons
	cout << "Selection sort: "<< selectionSort(list) << " comparisons\n";
	cout << "Insertion sort: " << insertionSort(list) << " comparisons\n";
	cout << "Bubble sort: " << bubbleSort(list) << " comparisons\n";
	cout << "Quicksort: " << quickStable(list) << " comparisons\n";
	cout << "Merge sort: " << mergeSort(list) << " comparisons\n";

	return 0;
}