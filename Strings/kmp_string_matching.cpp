#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Returns the 1st indext where the pattern matches in the text otherwise -1.
int kmp(string text,string ptrn)
{
    int m=ptrn.size(),n=text.size();
   int pt[m];       //Prefix table creation
   for(int k=0;k<m;k++)
        pt[k]=0;          //initialize with zeros
   int j=0,i;
    for(i=1;i<m;)
    {
        if(ptrn[j]==ptrn[i])
        {
            pt[i]=j+1;
            i++;
            j++;
        }
        else if(j>0)
            j=pt[j-1];
        else
            i++;
    }
    i=0;
    j=0;
    for(int k=0;k<m;k++)
        cout<<pt[k]<<" ";
    cout<<endl;
    while(i<n)
    {
        if(text[i]==ptrn[j])
        {
            if(j==m-1)
                return i-j;
            i++;
            j++;
        }
        else if(j>0)
            j=pt[j-1];
        else
            i++;
    }
    return -1;
}
int main()
{
    string text,ptrn;
    cin>>text>>ptrn;
   int index= kmp(text,ptrn);
   cout<<"Pattern is present at: "<<index<<endl;
    return 0;
}
