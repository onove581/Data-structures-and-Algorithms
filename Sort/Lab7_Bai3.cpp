#include<stdio.h>	
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
 int largest = i; 
 int l = 2 * i + 1; 
 int r = 2 * i + 2; 

 if (l < n && arr[l] > arr[largest])
 largest = l;
 
 if (r < n && arr[r] > arr[largest])
 largest = r;
 
 if (largest != i)
 {
 swap(arr[i], arr[largest]);
 
 heapify(arr, n, largest);
 }
}
 
// Ham vun dong
void heapSort(int arr[], int n)
{
 // Tao mot dong (Sap xep lai mang)
 for (int i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i);
 
 for (int i = n - 1; i >= 0; i--)
 {
 swap(arr[0], arr[i]);
 
 // goi ham heapify
 heapify(arr, i, 0);
 }
}
 
void printArray(int arr[], int n)
{
 for (int i = 0; i<n; ++i)
 printf(" %d ",arr[i]);
 printf("\n");
}
 
int main()
{
 int arr[] = { 11, 3 ,5, 4, 9, 15, 19, 7
};
 int n = sizeof(arr) / sizeof(arr[0]);
 
 heapSort(arr, n);
 printf("Sorted array is \n");
 printArray(arr, n);
}
