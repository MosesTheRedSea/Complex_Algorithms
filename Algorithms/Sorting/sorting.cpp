#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>	
#include <array>	
#include <time.h>
#include <time.h>	
#include <time.h>
#include <bits/stdc++.h>
	
// Built Data Structures	
#include <unordered_map>	
#include <map>	
#include <queue>	
#include <stack>	
#include <vector>	
#include <unordered_set>
#include <set> 
using namespace std;

/*
█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀
*/


// Adaptibility - Stability - In Place
// Sorting Algorithms 
void printVector(vector<int> nums) {
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
// Comparison-based Sorting

// Bubble Sort - O(n^2)
vector<int> bubbleSort(vector<int> values) {
	for (int i = 0; i < values.size() - 1; ++i ) {
		for (int j = 0; j < values.size() - i - 1; ++j) {
			if (values[j] > values[j + 1]) {
				int hold = values[j + 1];
				values[j + 1] = values[j];
				values[j] = hold;
			}
		}
	}
	return values;
}

// Selection Sort - O(n^2)
vector<int> selectionSort(vector<int> values) {
	for (int i = 0; i < values.size() - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < values.size(); ++j) {
			if (values[j] < values[min]) {
				min = j;
			}
			int temp = values[min];
			values[min] = values[j];
			values[j] = temp;
		}
	}
	return values;
}

// Insertion Sort - O(n^2)
vector<int> insertionSort(vector<int> values) {
	for (int i = 0; i < values.size(); ++i) {
		int j = i;
		while (j > 0 && values[j - 1] > values[j]) {
			int temp = values[j-1];
			values[j-1] = values[j];
			values[j] = temp;
			j--;
		}
	}
	return values;
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Merge Sort - O(log n)
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int partition(int arr[], int start, int end) {
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot) {
			count++;
		}
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);
	int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

// Quick Sort 
// O(n log(n)) - Best 
// O(n^2) - Worst
void quickSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

// Heap Sort

// Non-comparison-based Sorting

// Counting Sort - O(n + k)
vector<int> countSort(vector<int>& inputArray)
{
    int N = inputArray.size();
    int M = 0;
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
    vector<int> countArray(M + 1, 0);
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
        countArray[inputArray[i]]--;
    }
    return outputArray;
}

// Radix Sort



// Bucket Sort
int main() {

	int val[] = {64, 34, 25, 12, 22, 11, 90, 5};

	countSort(val);

	return 0;
}