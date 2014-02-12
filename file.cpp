#include <vector>
#include <iostream>
using namespace std;

int vertices = 5;
vector<vector<int>> a(vertices, vector<int>(vertices,999999999)); //array containing the shortest distances
vector<vector<int>> v(vertices, vector<int>(vertices,-1));  // the predecessor matrix
vector<vector<vector<int>>> route; // array containing all the vertices in the path between i and j

void path(int i, int j){
	if (i==j){
		cout<<v[i][j]<<endl;
	}
	int k=0;
	if (i!=j) {
			path(i,v[i][j]);
			route[i][j][k]=v[i][j];
			k++;
	}
}

void initialise(){
	// initialize diagonal
		for(int i=0; i < vertices; i++)
			a[i][i]=0;

	// initialize distances
		a[0][1]=20;
		a[0][2]=10;
		a[0][4]=5;
		a[2][3]=10;
		a[3][1]=3;
		a[4][2]=2;
		a[4][3]=4;

		for(int i = 0; i < vertices; i++)
			for(int j = 0; j < vertices; j++)
				if(i!=j && a[i][j]<999999999){
					v[i][j] = i;
				}
}

void flyodwarshall(){
		for(int k = 0; k < vertices; k++)
			for(int i = 0; i < vertices; i++)
				for(int j = 0; j < vertices; j++)
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
						v[i][j]=v[k][j];
					}

		// Print out final distance matrix
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		// Print out final predecessor matrix
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++)
				if(v[i][j]==-1)
					cout << -1 << " ";
				else
					cout << v[i][j]+1 << " ";
			cout << endl;
		}
		cout << endl;
}

int main(){
	initialise();
	flyodwarshall();
	path(4,2);
	return 0;
}
