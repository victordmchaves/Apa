#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <stdlib.h>

// Selection Sort
void selectionSort(std::vector<long> &vec)
{
	long i, j, min;
	long unsorted;

	for (i = 0; i < vec.size() - 1; i++)
	{
		min = i;
		for (j = i + 1; j < vec.size() - 1; j++)
		{
			if (vec[j] < vec[min])
			{
				min = j;
			}
		}
		std::swap(vec[min], vec[i]);
	}
}

// Insertion Sort
void insertionSort(std::vector<long> &vec)
{
	long i, j, unsorted;
	for (j = 1; j < vec.size(); ++j)
	{
		unsorted = vec[j];
		for (i = j - 1; i >= 0 && vec[i] > unsorted; --i)
			vec[i + 1] = vec[i];
		vec[i + 1] = unsorted;
	}
}
