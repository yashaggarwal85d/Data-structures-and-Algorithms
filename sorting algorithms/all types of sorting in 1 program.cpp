#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void selection(int arr[],int n)
{
	int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++) 
		{ 
        	if (arr[j] < arr[min_idx])  
            min_idx = j;  
		}
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }
}
void bubble(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
	{ 
    	for (j = 0; j < n-i-1; j++)
		{  
        	if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
		}
	}
}

void insertion(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void heap(int *a,int n)
{
    int i;
    priority_queue<int> pq;
    for(i=0;i<n;i++)
    pq.push(a[i]);
    for(i=n-1;i>=0;i--)
    {
        a[i]=pq.top();
        pq.pop();
    }
}

//quick sort starts
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quick(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quick(arr, low, pi - 1);  
        quick(arr, pi + 1, high);  
    }  
}  
//quick sort ends

//merge sort starts
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergesort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergesort(arr, l, m); 
        mergesort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

//merge sort ends


int main() 
{
	int a[10],n,x;
	cout<<"\n1.selection sort\n2.bubble sort\n3.insertion sort\n4.heap sort\n5.quick sort\n6.merge sort\n";
	cin>>x;
	cout<<"\nenter the size\n";
	cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
	switch(x)
	{
		case 1:selection(a,n);
		       break;
		case 2:bubble(a,n);
		       break;
		case 3:insertion(a,n);
		       break;
		case 4:heap(a,n);
		       break;
		case 5:quick(a,0,n-1);
		       break;
		case 6:mergesort(a,0,n-1);
		       break;
	}
    for(int i=0;i<n;i++)
    cout<<a[i];
}