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
void Remove(MT &x, int yflag, int i);
MT Tranpos(MT x);
void Remove(MT &x, int xflag);
void EnterArr(MT &x);
void Optimization(MT &x);
istream& operator>>(istream& is, MT& x);
void EnterArr(VT &x);
MT operator*(MT x, MT y);
void SetMatrix(MT &T, int xflag, int yflag, MT x);
MT operator*(float nB, MT x);
ostream& operator<<(ostream& os,const MT& x);
ostream& operator<<(ostream& os,const VT& x);
istream& operator>>(istream& is, VT& x);
//
int main()
{
    MT x,y,r,s;
    VT u;
    cin>>x;
    y= !x; 
    cout<<y; 
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
istream& operator>>(istream& is, MT &x)
{
    cout<<"Enter MT level : ";
    is >> x.lv;
    EnterArr(x);
    return is;
}
istream& operator>>(istream& is, VT &x)
{
    cout<<"Enter VT level: ";
    is >> x.lv;    
    EnterArr(x);        
    return is;
}
void Optimization(MT &x)
{
    for(int i = 1; i<= x.lv ;i++)
        for(int j =1 ;j<=x.lv;j++)
               if(x.PT[i][j]==-0)
                   x.PT[i][j]=0;
}
ostream& operator<<(ostream& os,const MT& x)
{
   cout<<"Matrix: "<<endl;
   os<<setiosflags(ios::showpoint)<<setprecision(5); 
   for(int i =1 ; i<=x.lv;i++)
   {
       for(int j =1;j<=x.lv;j++)
           os<<x.PT[i][j]<<" ";
        cout<<endl;
   }
    return os;
}
ostream& operator<<(ostream& os,const VT& x)
{
    os<<setiosflags(ios::showpoint)<<setprecision(5);
    cout<<"Vector: "<<endl; 
    for(int i = 1 ; i<=x.lv;i++)
        os<<x.PTV[i]<<setw(3);
    cout<<endl;
    return os; 
}
void Remove(MT &x, int xflag)
{
    for(int i = 1;i<=x.lv;i++)
        x.PT[xflag][i] = x.PT[xflag+1][i];
}
void Remove(MT &x, int yflag, int i)
{
    for(i ;i<=x.lv;i++)
        x.PT[i][yflag] = x.PT[i][yflag+1];
}
void SetMatrix(MT &T, int xflag, int yflag, MT x)
{
    Remove(x,xflag); 
    Remove(x,yflag,1); 
    x.lv = x.lv - 1; 
    T = x; 
}
int Det(MT x)
{
    if(x.lv == 2)
        return  (x.PT[1][1]*x.PT[2][2])-(x.PT[1][2]*x.PT[2][1]);
    if(x.lv ==1)
        return x.PT[1][1];
    MT T;
    int S = 0; 
    static int i = 1; 
       for(int j =1;j<=x.lv;j++) 
        { 
            SetMatrix(T,i,j,x);  
            S+= x.PT[i][j]*pow((-1),i+j)*Det(T); 
        }    
    cout<<S<<"abc";
    return S; 
}
void Tranposition(MT &xTra, MT x)
{
    MT T,xpos;
    xTra.lv = x.lv; 
    xpos = Tranpos(x); 
    // cout<<xTra; 
    for(int i =1;i<=x.lv;i++)
       for(int j =1;j<=x.lv;j++)
       {
            SetMatrix(T,i,j,xpos);     
            xTra.PT[i][j] = pow((-1),i+j)*Det(T);  
       } 
}
MT Tranpos(MT x)
{
    MT t; 
    t.lv = x.lv; 
    for(int i = 1;i<=x.lv;i++)
          for(int j =1;j<=x.lv;j++)
                t.PT[i][j]=x.PT[j][i];
    return t; 
}
MT operator*(MT x, MT y)
{
    MT t;
    if(x.lv == y.lv) 
        for(int i = 1;i<=x.lv;i++)
            for(int j =1;j<=y.lv;j++)
               t.PT[i][j] = x.PT[i][j]*y.PT[j][i]; 
    t.lv = x.lv;
    return t; 
}   
MT operator*(float nB, MT x)
{
    MT t; 
    for(int i =1;i<=x.lv;i++)
        for(int j =1;j<=x.lv;j++)
            t.PT[i][j] = nB*x.PT[i][j];
    t.lv = x.lv;
    return t; 
}
MT operator!(MT x)
{
    MT y,xTra; 
    int det = Det(x); 
    Tranposition(xTra,x); 
    cout<<xTra; 
    if(det==0)
        cout<<"Error"<<endl;
    else 
        y = (float(1)/det)*xTra;
    return y; 
} 
