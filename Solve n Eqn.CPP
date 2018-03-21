#include<stdio.h>
#include<iostream>
#include<conio.h>
//#include<iomanip.h>
#include<math.h>
using namespace std;

const int max_val = 25;
float determinant(float a[max_val][max_val], float);
void cofactor(float num[max_val][max_val], float f);
void transpose(float num[max_val][max_val], float fac[max_val][max_val], float nv);
int main()
{
    //clrscr();
    float A[max_val][max_val], nv, det;
	int i, j;
    cout<<"Enter number of unknowns"<<endl;
	cin>>nv;
	cout<<"Enter only the coefficients of unknowns"<<endl;
	for(i=0; i<nv; i++)
	{
	    for(j=0; j<nv; j++)
		{
		    cin>>A[i][j];
        }
    }
    det = determinant(A,nv);
    cout<<"Determinant of matrix is"<<det<<endl;
    if (det==0)
        cout<<"Math error"<<endl;
    else
        cofactor(A,nv);
    getch();
}
//DETERMINANT OF GIVEN MATRIX
float determinant(float A[max_val][max_val], float nv)
{
    float s = 1, det = 0, b[max_val][max_val];
	int i, j, m, n, c;
	if(nv==1)
	{
	    return(A[0][0]);
    }
	else
	{
	    det = 0;
		for(c=0; c<nv; c++)
		{
		    m = 0;
			n = 0;
            for(i=0; i<nv; i++)
			{
			    for(j=0; j<nv; j++)
				{
				    b[i][j]=0;
					if(i!=0&&j!=c)
					{
					    b[m][n]=A[i][j];
                        if(n<(nv-2))
						{
						    n++;
                        }
						else
						{
						    n=0;
							m++;
                        }
                    }
                }
            }
			det = det + s*(A[0][c]*determinant(b,nv-1));
			s = -1*s;
        }
    }
	return(det);
}
//COFACTOR OF GIVEN MATRIX
void cofactor(float num[max_val][max_val], float f)
{
    float b[max_val][max_val], fac[max_val][max_val];
	int p, q, m, n, i, j;
	for(q=0; q<f; q++)
	{
	    for(p=0; p<f; p++)
		{
		    m=0;
			n=0;
			for(i=0; i<f; i++)
			{
			    for(j=0; j<f; j++)
				{
				    if(i!=q&&j!=p)
					{
					    b[m][n]=num[i][j];
						if(n<(f-2))
                            n++;
						else
						{
						    n=0;
							m++;
                        }
                    }
                }
            }
            fac[q][p]=pow(-1,q+p)*determinant(b,f-1);
        }
    }
    transpose(num, fac, f);
}
//TRANSPOSE OF COFACTOR MATRIX
void transpose(float num[max_val][max_val], float fac[max_val][max_val], float nv)
{
    int i, j;
	float b[max_val][max_val], inverse[max_val][max_val], det;
	for(i=0; i<nv; i++)
	{
	    for(j=0; j<nv; j++)
		{
		    b[i][j]=fac[j][i];
        }
    }
	det=determinant(num,nv);
	for(i=0; i<nv; i++)
	{
	    for(j=0; j<nv; j++)
		{
		    inverse[i][j]=b[i][j]/det;
        }
    }
	cout<<"inverse of matrix"<<endl;
	for(i=0; i<nv; i++)
	{
	    for(j=0; j<nv; j++)
		{
		    cout<<"\t"<<inverse[i][j];
        }
		cout<<endl;
    }
//SOLUTION OF SYSTEM OF EQUATIONS
	float cons[max_val][1], sol[max_val][1];
	cout<<"enter constants"<<endl;
	for(i=0; i<nv; i++)
	{
	    cin>>cons[i][0];
    }
	cout<<"The solution is"<<endl;
	for(i=0; i<nv; i++)
	{
	    sol[i][0]=0;
		for(int k=0; k<nv; k++)
		{
		    sol[i][0]=sol[i][0]+(inverse[i][k]*cons[k][0]);
			if(k==(nv-1))
                cout<<"value of x"<<i+1<<" = "<<sol[i][0]<<"\t";
        }
		cout<<"\n";
    }
}

