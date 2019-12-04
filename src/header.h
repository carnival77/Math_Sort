#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

//Recieve file name with a list of numbers
//Return the list of numbers in a vector type list
//Close the file at the end
vector<float> fileToList(ifstream&);

void swap(vector<float>&, int posA, int posB);

//Add 1 comparison
//Returns true if x < y
//Mode = false --> x > y
bool compare(float x, float y, int* comp);

void printVector(vector<float>);

int selectionSort(vector<float>);
int insertionSort(vector<float>);
int bubbleSort(vector<float>);

int quickStable(vector<float>& list);
vector<float> quickStableRecursive(vector<float> list, int* comp);

int mergeSort(vector<float> list);
void MergeSortRecursive(vector<float>* list, int start, int end, int * comparisons);
void Merge(vector<float>* list, int start, int mid, int end, int * comparisons);