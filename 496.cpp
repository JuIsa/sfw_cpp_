#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(){
	string line;
	
	int which=0;
	// здесь немного запутанее, по условию надо считывать каждые две линии
	// и чтобы различать их я добавил int which который инкрементиурется каждый различать
	// и если этот инт четный то числа пушатся в первый массив если нет то во второй
	vector<int> numsA;
	vector<int> numsB;
	while(getline(cin,line)){
		
		int x;	
		istringstream sinp(line);
		if(which%2==0){								// вот здесь все происходит
			while(sinp>>x){
				numsA.push_back(x);
			}
		}else{
			while(sinp>>x){
				numsB.push_back(x);
			}
		}
			
		// и вот, если считалась вторая строка, то начинается анализ
		if(which%2!=0){
			
		int asize = numsA.size();		// определяю размер чтобы понять который тупо больше чтобы в большем из них искать меньшее
		int bsize = numsB.size();
		
		sort(numsA.begin(), numsA.end()); // нужно для бинароного поиска
		sort(numsB.begin(), numsB.end());
		
		int count=0;
		if(asize==bsize){  //если размер одинаковый то безразницы где что искать
			for(int i=0; i<asize; i++){
				if(binary_search(numsB.begin(),numsB.end(), numsA[i])){
					count++;
				}	
			}
		}
		if(asize<bsize){//если второй больше то ищем значения первого во втором
			for(int i=0; i<asize; i++){
				if(binary_search(numsB.begin(),numsB.end(), numsA[i])){
					count++;
				}	
			}
		}
		if(asize>bsize){
			for(int i=0; i<bsize; i++){
				if(binary_search(numsA.begin(),numsA.end(), numsB[i])){
					count++;
				}	
			}
		}
		// все возможные условия > < =
		if(count==asize and count==bsize)
			cout<<"A equals B"<<endl;
		if(count==0)
			cout<<"A and B are disjoint"<<endl;
		if(count>0 and count < asize and count<bsize)
			cout<<"I'm confused!"<<endl;
		if(count==asize and count<bsize)
			cout<<"A is a proper subset of B"<<endl;
		if(count==bsize and count<asize)
			cout<<"B is a proper subset of A"<<endl;

		numsA.clear();
		numsB.clear();
		}
		
		
		which++;
	}
	return 0;
}