#include <bits/stdc++.h>

using namespace std;
int processes[6] = {122, 150, 200, 10, 20, 300};
int memory[5] = {100, 350, 200, 360, 122};


int firstFitFind(int process){
	for (int i = 0; i < 5; i++){
		if (memory[i] >= process){
			memory[i] -= process;
			return i;
		}
	}
	return -1;
}

int bestFitFind(int process){
	int min = 10000000;
	int ind = -1;
	for (int i = 0; i < 5; i++){
		if (memory[i] >= process && memory[i] < min){
			ind = i;
			min = memory[i];
		}
	}
	if (ind != -1){
		memory[ind] -= process;
	}
	return ind;
}


int worstFitFind(int process){
	int ind = -1;
	int max = -9999999;
	for (int i = 0; i < 5; i++){
		if (memory[i] >= process && memory[i] > max){
			ind = i;
			max = memory[i];
		}
	}
	if (ind != -1){
		memory[ind] -= process;
	}
	return ind;
}


int main(){
	cout<<"Process index "<<" Process size "<<" Free block size"<<endl;
	// cout<<"FirstFIT"<<endl;
	// for (int i = 0; i < 6; i++){
	// 	int ind = firstFitFind(processes[i]);
	// 	if(ind != -1){
	// 		cout<<i<<"                "<<processes[i]<<"              "<<memory[ind]<<endl;
	// 	}
	// 	else{
	// 		cout<<i<<"                "<<processes[i]<<"              "<<"Not enough space"<<endl;
	// 	}
	// }
	cout<<"BestFIT"<<endl;
	for (int i = 0; i < 6; i++){
		int ind = bestFitFind(processes[i]);
		if(ind != -1){
			cout<<i<<"                "<<processes[i]<<"              "<<memory[ind]<<endl;
		}
		else{
			cout<<i<<"                "<<processes[i]<<"              "<<"Not enough space"<<endl;
		}
	}
	// cout<<"WorstFIT"<<endl;
	// for (int i = 0; i < 6; i++){
	// 	int ind = worstFitFind(processes[i]);
	// 	if(ind != -1){
	// 		cout<<i<<"                "<<processes[i]<<"              "<<memory[ind]<<endl;
	// 	}
	// 	else{
	// 		cout<<i<<"                "<<processes[i]<<"              "<<"Not enough space"<<endl;
	// 	}
	// }
	return 0;
}
