#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int arr[4] = {-1};
int priority[4] = {0};
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
			if(arr[i] == x) priority[i]++;
			else priority[i]--;
		}
	}
	else{
		int min_priority = priority[0];
		int min_ind = 0;
		for (int i = 1; i < 4; i++){
			if (priority[i] < min_priority){
				min_priority = priority[i];
				min_ind = i;
			}
		}
		arr[min_ind] = x;
		priority[min_ind] = 0;
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