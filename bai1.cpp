#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<math.h>
#define MAX 20
using namespace std;
//
struct PT
{
    int HS[MAX];    
    int hs;
};
//
void Creatzeroarr(PT A,int hs);
void Partial(int T[],PT X,PT Y);
istream& operator>>(istream &is, PT &x);
ostream& operator<<(ostream &os, PT x);
PT operator+(PT x, PT y);
PT operator-(PT x);
PT operator*(PT x, PT y);
long operator^(PT f,int x);
PT operator-(PT x, PT y);
//
int main()
{
    PT a,b,c,d;  
    int x; 
    long f; 
    cin>>a>>b; 
    cin>>x;    
    d =(a+b); 
    f = d^x;
    cout<<d<<"\n";
    cout<<f;
}
istream& operator>>(istream &is, PT &x)
{
    cout<<"Enter degree: "; 
    cin>>x.hs; 
    for(int i =0;i<=x.hs;i++)
        is>>x.HS[i];
    return is;
}    
ostream& operator<<(ostream &os, PT x)
{
    for(int i = 0;i<=x.hs;i++)
        os<<x.HS[i]<<setw(3);
    return os;
}
PT operator-(PT x)
{
    PT t;
    for(int i =0;i<=x.hs;i++)
    {
        t.HS[i]=-x.HS[i]; 
    }
    t.hs=x.hs;
    return t;
}
PT operator+(PT x, PT y)
{
    PT t;
    int k,i;
    k = x.hs>y.hs?x.hs:y.hs;
    for(i =0;i<=k;i++)
    {
        if(x.hs>=i&&y.hs>=i)
           t.HS[i] = x.HS[i]+y.HS[i]; 
        else
           t.HS[i] = x.hs>y.hs?x.HS[i]:y.HS[i];
    }
    t.hs = i-1; 
    return t;
} 
PT operator*(PT x, PT y)
{
    PT t;
    int k,i;
    k= x.hs+y.hs;
    Creatzeroarr(x,k);    
    Partial(t.HS,x,y);
    return t;    
}
long operator^(PT f,int x)
{
    long S = 0;
    for(int i =0;i<=f.hs;i++)
        S+=pow(float(x),f.HS[i]);
    return S; 
}
PT operator-(PT x, PT y)
{
    return x+(-y);
}
void Creatzeroarr(PT A,int hs)
{
    for(int i =0;i<=hs;i++)
        A.HS[i] = 0;
    A.hs = hs;
     
}
void Partial(int T[],PT X,PT Y)
{
    for(int i =0;i<=X.hs;i++)
        for(int j =0;j<=Y.hs;j++)
            T[i+j]+=X.HS[i]+Y.HS[j];
}
