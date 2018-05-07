#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int x;
	cin>>x;
	vector<int> dates;      //to contain numbers, because max_element can work only with vector
	map<int,string> people;	//to contain numbers and names, bacause in the end we have to print name of number
	for(int i=0;i<x;i++){
		
		string name;cin>>name;
		int day,month,year;
		cin>>day>>month>>year;
		int sum = year*10000+month*100+day; //to change the order of elder one, for example
											// 1999.01.01 and 1999.01.02
											//code turns them into big int
											// 19990101 and 19990102
		dates.push_back(sum);
		people.insert(pair<int,string>(sum,name));		
	}
	auto max = min_element(dates.begin(), dates.end());//return pointer
	auto min = max_element(dates.begin(), dates.end());
	
	int pmax = *max; // to get the value of pointer
	int pmin = *min;
	
	//auto it = ;
	//auto it2 = people.find(pmin);
	
	cout<<people.find(pmin)->second<<endl;//using number print name of this number
	cout<<people.find(pmax)->second<<endl;

	return 0;	
}