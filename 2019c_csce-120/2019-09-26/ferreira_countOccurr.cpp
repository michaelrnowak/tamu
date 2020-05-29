#include <iostream> 
using namespace std; 

int count (int* v, int n, int x)
{
  int c = 0; 
  for (int i = 0; i < n; i = i + 1){
    if (v[i] == x){
      c = c + 1; 
    }
  }
  return(c); 
} 

int main()
{
  const int MAX = 1000; 
  int v[MAX], n; 
  bool appears; 

  cout << "Enter 0 < n < 1000: "; 
  cin >> n; 

  cout << "Enter elements: "; 
  for (int i = 0; i < n; i++){
    cin >> v[i]; 
  } 

  for(int i = 0; i < n; i++){
    // check if the number appeared before
    appears = false; 
    for(int j = 0; j < i; j++){
      if (v[j] == v[i]){
	appears = true; 
      } 
    }
    if (!appears){
      cout << v[i] << " appears " << count(v, n, v[i]) << " times." << endl; 
    }
  }

  return(0); 
} 
  
