#include <iostream>
#include <string>


using namespace std; 

void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}
                        
void printArr(int arr[],  int n)
{
  for(int i =0; i < n; i++)
  {
      cout<< arr[i]<<" ";
  }
  cout<<endl;
}
 

int main()
{
int min =0; 
int max =10000;
int size=0; 
cout<<"enter size of array"<<endl; 
cin >> size; 
int array[size]; 
for(int i =0; i< size; i++)
{
  array[i] = min + (rand() % static_cast<int>(max - min + 1));
}
clock_t start;
start = clock();
MergeSort(array, 0, size-1);
cout<<"Time for running mergesort on array of size "<< size <<" is " << (clock()-start)/(double)(CLOCKS_PER_SEC / 1000) << "ms" << endl; 
//printArr(array, size);

return 0; 

}
