#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#define MAX 20
using namespace std;
//
struct MT
{
    float PT[MAX][MAX];    
    int lv; 
};
struct VT
{
    float PTV[MAX];
    int lv;
};
//
MT operator!(MT x);
int Det(MT x);
void Tranposition(MT &xTra, MT x);
void EnterArr(MT &x);
istream& operator>>(istream& is, MT& x);
void EnterArr(VT &x);
MT operator*(MT x, MT y);
void SetMatrix(MT &T, int xflag, int yflag, MT x);
MT operator*(float nB, MT x);
ostream& operator<<(ostream& os, MT x);
ostream& operator<<(ostream& os,VT x);
istream& operator>>(istream& is, VT& x);
//
int main()
{
    MT x,y,r,s;
    VT u;
    cin>>x;
    x= !x; 
    cout<<x; 
    return 0; 
}
void EnterArr(MT &x)
{
    for(int i =1;i<=x.lv;i++)
        for(int j =1;j<=x.lv;j++)
            cin>>x.PT[i][j];
}
void EnterArr(VT &x)
{
     for(int i =1;i<=x.lv;i++)
              cin>>x.PTV[i];
}
istream& operator>>(istream& is, MT& x)
{
    cout<<"Enter MT level : ";
    is >> x.lv;
    EnterArr(x);
    return is;
}
istream& operator>>(istream& is, VT& x)
{
    cout<<"Enter VT level: ";
    is >> x.lv;    
    EnterArr(x);        
    return is;
}
ostream& operator<<(ostream& os, MT x)
{
   cout<<"Matrix: "<<endl; 
   for(int i =1 ; i<=x.lv;i++)
       for(int j =1;j<=x.lv;j++)
           cout<<x.PT[i][j]<<setw(3);
    return os;
}
ostream& operator<<(ostream& os,VT x)
{
    cout<<"Vector: "<<endl; 
    for(int i = 1 ; i<=x.lv;i++)
        cout<<x.PTV[i]<<setw(3);
    return os; 
}
void SetMatrix(MT &T, int xflag, int yflag, MT x)
{
   int xT =1;
   int yT =1;
   for(int i =1;i<=x.lv;i++)
   { 
       for(int j =1;j<=x.lv;j++)
        {
            if(i!=xflag&&j!=yflag)
                T.PT[xT][yT++]=x.PT[i][j];
        }
       ++xT; 
   } 
}
int Det(MT x)
{
    if(x.lv == 2)
        return  x.PT[1][1]*x.PT[2][2]-x.PT[1][2]*x.PT[2][1];
    MT T;
    T.lv = x.lv - 1;
    static int i = 1; 
       for(int j =1;j<=x.lv;j++) 
        { 
            SetMatrix(T,i,j,x);  
            return x.PT[i][j]*pow(-1,i+j)*Det(T); 
        }    
    return -999999; 
}
void Tranposition(MT &xTra, MT x)
{
    MT T;
    for(int i =1;i<=x.lv;i++)
       for(int j =1;j<=x.lv;i++)
       {
            SetMatrix(T,i,j,x);     
            xTra.PT[i][j] = x.PT[i][j]*pow(-1,i+j)*Det(T);  
       } 
}
MT operator*(MT x, MT y)
{
    MT t;
    if(x.lv == y.lv) 
        for(int i = 1;i<=x.lv;i++)
            for(int j =1;j<=y.lv;j++)
               t.PT[i][j] = x.PT[i][j]*y.PT[j][i]; 
    return t; 
}   
MT operator*(float nB, MT x)
{
    MT t; 
    for(int i =1;i<=x.lv;i++)
        for(int j =1;j<=x.lv;j++)
            t.PT[i][j] = nB*x.PT[i][j];
    return t; 
}
MT operator!(MT x)
{
    MT y,xTra;
    Tranposition(xTra,x); 
    y = (1/Det(x))*xTra;
    return y; 
} 
