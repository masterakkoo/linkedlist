#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t!=0)
	{
	    long long int n;
	    cin>>n;
	    long long int a[n];
	   long long int b[n];
       long long int x=0,y=0;
	    for (long long int i = 0; i < n; i++) 
	    {
	        cin>>a[i];
            x=x+a[i];
	    }	   
	    for (long long int i = 0; i < n; i++) 
	    {
	        cin>>b[i];
            y=y+b[i];
	    }
	    long long int m=0;
	    if(x==y)
	   {
	       for (long long int i = 0; i < n; i++) 
	    {
	        if(a[i]>b[i])
	        {
	            if(m<(a[i]-b[i]))
	            m=(a[i]-b[i]);
	        }
	        else
	        {
	            if(m<(b[i]-a[i]))
	            m=(b[i]-a[i]);
	        }
	    }
	    cout<<m<<endl;
	   }
	   else
	   cout<<"-1"<<endl;
	    t--;
	}
	return 0;
}
