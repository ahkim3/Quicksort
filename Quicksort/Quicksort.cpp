/*
Name: Andrew Kim
Date: April 26, 2021
Program: Quicksort Lab

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>

using namespace std;

void quickSort(int[], int, int, int);
void swap(int&, int&);


int main()
{
	int nums[] = { 3, 2, 4, 6, 5, 1, 4, 2 },
		size = (sizeof(nums) / sizeof(nums[0]));
	
	quickSort(nums, 0, size - 1, size);

	// Print array
	for (int i = 0; i < 8; i++)
		cout << nums[i];
}


// Sort given data collection using a quicksort algorithm
void quickSort(int nums[], int first, int last, int size)
{
	// Sorted; do nothing else
	if (size < 2)
		return;
	else if (first < last)
	{
		int pivotLoc, smallestLoc = first - 1,
			pivot = nums[last]; // Set last element to be pivot
			
		// Moves all elements smaller than pivot to its left, and all
		// elements greater than pivot to its right
		for (int i = first; i <= last - 1; i++)
		{
			if (nums[i] < pivot)
			{
				smallestLoc++;
				swap(nums[i], nums[smallestLoc]);
			}
		}

		swap(nums[last], nums[smallestLoc + 1]);

		pivotLoc = smallestLoc + 1; // Move one up

		// Split and sort
		quickSort(nums, first, pivotLoc - 1, size);
		quickSort(nums, pivotLoc + 1, last, size);
	}
}


// Swaps two elements
void swap(int& firstElement, int& secondElement)
{
	int temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}
