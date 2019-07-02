#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

fstream file;
ofstream ofile;
int size=0; 
string line;
//istringstream istr; 
file.open("data.txt", ios::in);
ofile.open("merge.txt");
file >> size; 
getline(file, line);
while(file)
{
//cout << size <<endl;
//cout << line << endl;
//cout << "-------------"<<endl;
int array[size]; 
//istr.str(line);
istringstream istr(line);
for(int i =0; i< size; i++)
{
 istr >> array[i];
// cout << array[i] << " ";
}
MergeSort(array, 0, size-1);
printArr(array, size);
for(int i=0; i < size; i++)
{
  ofile << array[i] << " ";
}
ofile << "\n";
//cout << endl; 

file >> size;
getline(file,line);
}

file.close();
ofile.close();
return 0; 

}
