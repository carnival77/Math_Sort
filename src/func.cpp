#include "header.h"

vector<float> fileToList(ifstream& file)
{
	vector<float> list;
	string dummy;
	float element;
	while (file >> dummy)
	{
		try
		{
			element = stof(dummy);
		}
		catch(const std::exception& e)
		{
			cerr << "Invalid characters\n";
			vector<float> empty;
			file.close();
			return empty;
		}
		list.push_back(element);
	}
	file.close();
	return list;
}

bool compare(float x, float y, int* comp)
{
	(*comp)++;
	return x < y;

}

void swap(vector<float> &list, int posA, int posB)
{
	float temp = list[posA];
	list[posA] = list[posB];
	list[posB] = temp;
}

void printVector(vector<float> list)
{
	for (float x : list)
		cout << x << " ";
	cout << "\n";
}

int selectionSort(vector<float> list)
{
	int nElements = list.size(), posMin;
	int i, j, comparisons = 0;
	for (i = 0; i < nElements; i++)
	{
		posMin = i;
		for (j = i + 1; j < nElements; j++)
			if(compare(list[j], list[posMin], &comparisons)) 
				posMin = j;
		swap(list, i, posMin);
	}
	return comparisons;
}

int insertionSort(vector<float> list)
{
	int j, k, comparisons = 0;
	float dummy;
	for (int i = 1; i < (int)list.size(); i++)
	{
		j = 0; //Index to serach for correct position
		dummy = list[i];
		while (j < i && !compare(dummy, list[j], &comparisons)) //Search position left to right
		{
			j++;
		}
		k = i;
		while (k > j) //Make space for the element
		{
			list[k] = list[k - 1];
			k--;
		}
		list[j] = dummy; //Insert the element in the spot
	}
	return comparisons;
}

int bubbleSort(vector<float> list)
{
	int nElements = list.size();
	int i, j, comparisons = 0;
	for (i = 0; i < nElements; i++)
	{
		for (j = 0; j < nElements - i - 1; j++)
			if (compare(list[j], list[j + 1], &comparisons)) 
				swap(list, j, j + 1);
	}
	return comparisons;
}

int quickStable(vector<float>& list)
{
	int comparisons = 0;
	list = quickStableRecursive(list,&comparisons);
	return comparisons;
}

vector<float> quickStableRecursive(vector<float> list, int* comp)
{
	if (list.size() < 2)
		return list;
	float pivot = list[0];
	vector<float> lower, greater;
	for (int i = 1; i < (int)list.size(); i++)
		if (compare(list[i], pivot, comp))
			lower.push_back(list[i]);
		else
			greater.push_back(list[i]);

	lower = quickStableRecursive(lower, comp);
	greater = quickStableRecursive(greater, comp);
	lower.push_back(pivot);
	lower.insert(lower.end(), greater.begin(), greater.end());
	return lower;
}

int mergeSort(vector<float> list)
{
	int comparisons = 0;
	MergeSortRecursive(&list, 0, list.size() - 1, &comparisons);
	return comparisons;
}

void MergeSortRecursive(vector<float>* list, int start, int end, int * comparisons)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSortRecursive(list, start, mid, comparisons);
		MergeSortRecursive(list, mid + 1, end, comparisons);
		Merge(list, start, mid, end, comparisons);
	}
}

void Merge(vector<float>* list, int start, int mid, int end, int * comparisons)
{
	int i = start;
	int j = mid + 1;
	vector<float> sorted;
	int tam = end - start + 1;
	for (int x = 0; x < tam; x++)
	{
		if (j > end) //Si la sublista [mitad+1...fin] esta vacia cogemos todos los elementos de la otra sublista
		{
			sorted.push_back((*list)[i]);
			i++;
		}
		else if (i > mid) //Si la sublista [inicio...mitad] esta vacia cogemos todos los elementos de la otra sublista
		{
			sorted.push_back((*list)[j]);
			j++;
		}
		else //Caundo hay elementos en ambas sublistas
		{
			//Elegimos el menos y lo guardamos en la sublista temporal
			if (compare((*list)[j] , (*list)[i],comparisons))
			{
				sorted.push_back((*list)[j]);
				j++;
			}
			else
			{
				sorted.push_back((*list)[i]);
				i++;
			}
		}
	}

	/*while (i <= mid && j <= end)
	{
		(*comparisons)++;
		if ((*list)[i] <= (*list)[j])
			sorted.push_back((*list)[i++]);
		else
			sorted.push_back((*list)[j++]);
	}
	if (i > mid)
		for (int l = j; l <= end; l++)
			sorted.push_back((*list)[l]);
	else 
		for (int l = i; l <= mid; l++)
			sorted.push_back((*list)[l]);*/

	for (int i = 0, a = start; i < (int)sorted.size(); i++, a++)  (*list)[a] = sorted[i];
}