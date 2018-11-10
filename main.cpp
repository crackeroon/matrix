#include <stdlib.h>
#include <iostream>
//В матрице удалите столбцы с положительными суммами элементов,
//а затем в качестве первого вставьте столбец из минимальных элементов соответствующих строк.
using namespace std;

int main()
{
    int** a;
    int n,m;
    cout<<"input n: ";
    cin>>n;
    cout<<"input m: ";
    cin>>m;
// www.itmathrepetitor.ru
    a=new int* [n];

    for (int i=0; i<n; i++)
      a[i]=new int [m+1];

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        a[i][j]=-5+rand()%12;

    cout<<"Start matrix: "<<endl;
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
        cout<<a[i][j]<<" ";
      cout<<endl;
    }
// www.itmathrepetitor.ru
    for (int j=0; j<m; j++)
    {
       int sum=0;
       for (int i=0; i<n; i++)
          sum+=a[i][j];
       cout<<"sum = "<<sum<<endl;
       if (sum>0)
       {
          //удаление j столбца
          for (int k=j+1; k<m; k++)
          {
             for (int i=0; i<n; i++)
                a[i][k-1]=a[i][k];
          }
          m--;
          j--;
       }
    }

    for (int j=m-1; j>=0; j--)
    {
        for (int i=0; i<n; i++)
          a[i][j+1]=a[i][j];
    }
    m++;

    for (int i=0; i<n; i++)
    {
        int min=a[i][1];
        for (int j=1; j<m; j++)
          if (a[i][j]<min)
            min=a[i][j];

        a[i][0]=min;
    }

    cout<<"End matrix: "<<endl;
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
        cout<<a[i][j]<<" ";
      cout<<endl;
    }

// каз матрицы на экран

	for (int i=0; i<n; i++)
		delete [] a[i];
	delete [] a;
}
