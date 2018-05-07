#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int num_of_course, num_of_cat;
	while(cin>>num_of_course>>num_of_cat and num_of_course!=0){
	vector<int> courses;
	for(int i=0; i<num_of_course;i++){
		int x;cin>>x;
		courses.push_back(x);
	}
	bool yes = true;
	for(int j=0;j<num_of_cat;j++){
		int num_of_req; cin>>num_of_req;
		int num_to_take; cin>>num_to_take;
		vector<int> req;
		for(int i=0; i<num_of_req;i++){
			int x;cin>>x;
			req.push_back(x);
		}
		int count=0;
		sort(courses.begin(), courses.end());
		for(int i=0;i<num_of_req; i++){
			if(binary_search(courses.begin(), courses.end(), req[i])){
				count++;
			}
		}
		if(count<num_to_take){
			yes=false;
		}
			
	}
	if(yes)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	}

	return 0;
}