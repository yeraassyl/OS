#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int arr[4] = {-1};
int aging[4] = {0};
bool second_chance[4] = {true};
int pages[15] = {1, 2, 3, 3, 6, 9, 66, 2, 45, 66, 9, 8, 13, 12, 11};
vector<int>  v;

void print(bool found){
	if(found) cout<<"Found!\n";
	else cout<<"Page fault\n";
	cout<<"Memory state: \n | ";
	for (int i = 0; i < 4; i++){
		cout<<arr[i]<<" | ";
	}
	cout<<endl;
}

bool exists(int x){
	for(int i = 0; i < 3; i++){
		if(arr[i] == x) return true;
	}
	return false;
}

void priorityDetection(int x, bool found){
	if(found){
		for (int i = 0; i < 4; i++){
			if(arr[i] == x) aging[i] = 0;
			else aging[i]++;
		}
	}
	else{
		int max_age = aging[0];
		int max_ind = 0;
		for (int i = 1; i < 4; i++){
			if (aging[i] > max_age && !second_chance[i]){
				max_age = aging[i];
				max_ind = i;
				break;
			}
			else{
				second_chance[i] = false;
			}
		}
		arr[max_age] = x;
		aging[max_ind] = 0;
	}
}


int main(){
	int index = 0;
	for(int i = 0; i < 15; i++){
		if (exists(pages[i])){
			priorityDetection(pages[i], true);
			print(true);
		}else if(index > 3){
			priorityDetection(pages[i], false);
			print(false);
		}
		else{
			arr[index] = pages[i];
			index++;
			print(false);
		}
	}
}