#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int x;
	cin>>x;
	vector<int> ints; 
	for(int i=0;i<x;i++){
		int n;
		cin>>n;
		ints.push_back(n);
	}
	
	//set<int> an;
	for(int i=0;i<x;i++){
		int sum=0;
		int n = ints[i];
		bool ok = true;
		
		while(ok){
			sum=0;
			
			while(n!=0){
				sum+=(n%10)*(n%10);
				n=n/10;
				
			}
			n=sum;
			//cout<<n<<endl;
			if(sum==1 or sum==4)
				ok=false;
		}
		if(sum==1)
		cout<<"Case #"<<i+1<<": "<< ints[i]<<" is a Happy number."<<endl;
		if(sum==4)
		cout<<"Case #"<<i+1<<": "<< ints[i]<<" is an Unhappy number."<<endl;
	}
	
	return 0;
}