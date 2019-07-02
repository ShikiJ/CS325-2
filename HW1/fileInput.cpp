#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  fstream file; 
  string line; 

  file.open("data.txt", ios::in); 
  if(!file)
  { 
      cout<<"Err"<<endl;
      return 0; 
  }

  getline(file, line); 
  while(file)
  {
    cout<<"the line is "<< line << endl; 
    getline(file, line);
  }
  file.close();

return 0; 
}
