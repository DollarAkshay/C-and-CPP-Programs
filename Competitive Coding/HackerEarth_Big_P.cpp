
// BFS Search 

//http://www.hackerearth.com/problem/algorithm/big-p-and-party-1/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> partner[100];
int check[1000],luck[1000];

void calcLuck(int n){
	
	int i;
	queue<int> q;

	for (i = 0; i < n; i++)
		luck[i] = -1;
	luck[0] = 0;

	// Pushing Big P to the Queue
	check[0] = 1;
	q.push(0);
	
	while(!q.empty()){
		i = q.front();
		q.pop();
		for (int j = 0; j < partner[i].size(); j++){
			if (check[partner[i][j]] == 0){
				luck[partner[i][j]] = luck[i] + 1;
				check[partner[i][j]] = 1;
				q.push(partner[i][j]);
			}
		}
	}

}

int main(){

	int n, d,a,b;
	scanf("%d%d", &n,&d);
	for (int i = 0; i < d; i++){
		scanf("%d%d", &a, &b);
		partner[b].push_back(a);
		partner[a].push_back(b);
	}
	
	calcLuck(n);

	for (int i = 1; i < n; i++)
		printf("%d\n", luck[i]);
	return 0;
}

// Solved
