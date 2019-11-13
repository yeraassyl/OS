#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int arr[3] = {-1};
int pages[15] = {1, 2, 3, 3, 6, 9, 66, 2, 45, 66, 9, 8, 13, 12, 11};
 

void print(bool found){
	if(found) cout<<"Found!\n";
	else cout<<"Page fault\n";
	cout<<"Memory state: \n | ";
	for (int i = 0; i < 3; i++){
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

int main(){
	int index = 0;
	for(int i = 0; i < 15; i++){
		if (!exists(pages[i])){
			arr[index] = pages[i];
			index++;
			index %= 3;
			print(false);
		}else{
			print(true);
		}

	}
}