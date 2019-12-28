#include<iostream>
using namespace std;


void MatrixChain(int [], int);
int *initMatrix();



int *initMatrix(int n)
{
	int *matrix = new int[n+1];
	int i = 0;

	while(true)
	{
		if( i >=n+1)
			break;
		cout << "input the number of d" << i <<":"<<endl;
		while(!(cin >> matrix[i]))
		{
		    cout << "Bad value!"<< endl;
		    cin.clear();
		    cin.ignore(1024, '\n');
		}
//		cout<<	matrix[i] << endl;	
		i+=1;
	}
	
	return matrix;
}

void MatrixChain(int *p, int n)
{
    int m[n][n] = {0};
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;    
 

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;   
                }
            }
        }
    }
	
//	int minM[n][n] = {0};
//	int save[n][n] = {0};
//	int j,min,q;
//	for(int d = 1; d<n-1; d++)
//	{
//		for(int i=1; i<n-d;i++)
//		{
//			j = i+d;
//			min = 322767;
//			for(int k = 1; k<=j-1; k++)
//			{
//				q = minM[i][k] + minM[k+1][j] + p[i-1]*p[k]*p[j];
//				if(q < min)
//				{
//					min = q;
//					save[i][j] = k;
//				}
//			}
//			minM[i][j] = min;
//		}
//	}

	
 
	for( int i = 0; i< n; i++)
	{
		for(int j=0; j < n ; j++)
			cout << m[i][j] << "\t";
		cout << endl;
	}
	cout<<endl;
	cout << m[1][n-1];
}


int main()
{
	int n;
	
	int *p;
	cout<<"please input the number of array!";
	cin >> n;
	p = initMatrix(n);
	
//	for( int i = 0; i< n+1; i++)
//	{
//		cout << p[i]<< "\t";
//	}
	cout << endl;
	MatrixChain(p, n+1);
}
