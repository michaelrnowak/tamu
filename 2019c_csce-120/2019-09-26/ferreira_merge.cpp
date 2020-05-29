#include <iostream> 
using namespace std; 

void merge(int* u, int n1, int* v, int n2)
{
  int indu = 0, indv = 0; 
  while(indu < n1 && indv < n2){
    if (u[indu] < v[indv]){
      cout << u[indu] << " "; 
      indu = indu + 1; 
    }
    else{
      cout << v[indv] << " "; 
      indv = indv + 1; 
    }
  }
  while (indu < n1){
    cout << u[indu] << " ";
    indu = indu + 1; 
  } 
  while (indv < n2){
    cout << v[indv] << " "; 
    indv = indv + 1; 
  }
  cout << endl; 
} 

int main()
{
  const int MAX = 100; 
  int a[MAX], b[MAX], na, nb; 

  cout << "Enter number of elements of a: "; 
  cin >> na; 
  cout << "Enter elements: "; 
  for(int i = 0; i < na; i = i + 1){
    cin >> a[i]; 
  } 

  cout << "Enter number of elements of b: "; 
  cin >> nb; 
  cout << "Enter elements: "; 
  for(int i = 0; i < nb; i = i + 1){
    cin >> b[i]; 
  } 

  merge(a, na, b, nb); 
  return (0); 
} 















