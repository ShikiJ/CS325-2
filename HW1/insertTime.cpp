#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std; 

void insertionSort(int arr[], int n) 
{
  for(int i = 1; i < n; i++) 
  {
    int j = i - 1;
    int key = arr[i];

    while(j >= 0 && key < arr[j]) 
    {
      arr[j + 1] = arr[j];
      j--;;
    }
    arr[j + 1] = key;
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
insertionSort(array,size);
cout<<"Time for running insertsort on array of size "<< size <<" is " << (clock()-start)/(double)(CLOCKS_PER_SEC / 1000) << "ms" << endl; 
//printArr(array, size);
//cout << endl; 

return 0; 

}
