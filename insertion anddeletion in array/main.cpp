#include <iostream>
#include<string.h>
using namespace std;
int a[100];
int length()
{int l=0;
while(a[l]!=NULL)
l=l+1;
return(l);
}
void print()
{
for(int i=0;i<length();i++)
cout<<a[i]<<" ";
cout<<"\n";}
void inser()
{int h,j,k;
cout<<"\nInsertion";
cout<<"\nenter the value to be inserted";
cin>>h;
if(length()==0)
a[0]=h;
else
{cout<<"\nenter the postion to be inserted max till "<<length()+1;
cin>>j;
for(k=length();k>j-1;k--)
a[k]=a[k-1];
a[j-1]=h;
cout<<"\nelement has been inserted\n";
print();}}
void del()
{int e,r,t=0,k;
cout<<"\n deletion";
cout<<"\n1.position";
cout<<"\n2.value";
cin>>e;
if(e==1)
{cout<<"\nenter position max till "<<length();
cin>>r;
for(k=r-1;k<length();k++)
a[k]=a[k+1];
}
else
{cout<<"\nenter value";
cin>>r;
for(k=0;k<length();k++)
{if(a[k]==r)
t=1;
if(t==1)
a[k]=a[k+1];
}
}
a[length()]=NULL;
print();
}
int main()
{
int g;
while(1)
    {
    cout<<"1. insertion";
    cout<<"\n2. deletion";
    cout<<"\n3.exit";
    cin>>g;
    if(g==1)
    inser();
    else if(g==2)
    {
    if(length()==0)
    cout<<"\nno element\n";
    else
    del();
    }
    else if(g==3)
    return 0;
    else
    cout<<"\nwrong choice";
    }
}
