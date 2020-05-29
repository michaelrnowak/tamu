#include <iostream> 
using namespace std; 

double product(double* u, double* v, int n)
{
  double sum = 0.0; 
  for (int index=0; index < n; index = index + 1){
    sum = sum + u[index] * v[index]; 
  }
  return (sum); 
} 

int main()
{
  const int MAX = 100; 
  int m; 
  double A[MAX][MAX], A2[MAX][MAX], row[MAX], col[MAX]; 

  cout << "Enter m: "; 
  cin >> m; 

  for (int i = 0; i < m; i = i + 1){
    cout << "Enter row " << i << ": "; 
    for (int j = 0; j < m; j = j + 1){
      cin >> A[i][j]; 
    }
  } 

  for (int indexrow = 0; indexrow < m; indexrow = indexrow + 1){
    // copy row indexrow of the matrix A to array row
    for(int k = 0; k < m; k = k + 1){
      row[k] = A[indexrow][k]; 
    }

    for(int indexcol = 0; indexcol < m; indexcol = indexcol + 1){
      // copy this column to array col

      for(int k = 0; k < m; k = k + 1){
	col[k] = A[k][indexcol];
      }

      A2[indexrow][indexcol] = product(row, col, m); 
    } 
  } 

  cout << "Matrix A^2: " << endl; 

  for(int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      cout << A2[i][j] << " "; 
    }
    cout << endl; 
  }

  return (0); 
} 

















  














