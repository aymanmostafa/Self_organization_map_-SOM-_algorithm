//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================
// Self_organization_map_-SOM-_algorithm (data mining)
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define clr(v,d) memset(v,d,sizeof(v));

float rand_FloatRange(float a, float b) {
	return ((b - a) * ((float) rand() / RAND_MAX)) + a;
}
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
	float eta;
	int j, n;
	cout << "Enter the value of n (eata)\n";
	cin >> eta;
	cout << "Enter number of data (n)\n";
	cin >> n;
	cout << "Enter the value of j\n"; // number of W
	cin >> j;
	vector<float> x;
	vector<vector<float>> w(n);
	cout << "Enter the data\n";
	for (int r = 0; r < n; r++) {
		float t;
		cin >> t;
		x.push_back(t);
	}
	for (int r = 0; r < n; r++)
		for (int k = 0; k < j; k++) {
			w[r].push_back(rand_FloatRange(0, 1));
		}
	for (int numberOfIteration = 0; numberOfIteration < 1000;
			numberOfIteration++) {
		vector<pair<float, int>> res;
		for (int k = 0; k < j; k++) {
			float sum = 0;
			for (int r = 0; r < n; r++) {
				sum += (x[r] - w[r][k]) * (x[r] - w[r][k]);
			}
			res.push_back( { sum, k });
		}
		sort(all(res));
		cout << "Min distance is for J=" << res[0].second << endl;
		int neighbour1 = res[0].second - 1, neighbour2 = res[0].second + 1;
		if (neighbour1 < 0)
			neighbour1 = j - 1;
		if (neighbour2 >= j)
			neighbour2 = 0;
		int end = 3;
		if (neighbour1 == neighbour2)
			end = 2;
		int arr[] = { res[0].second, neighbour1, neighbour2 };
		for (int r = 0; r < end; r++)
			for (int k = 0; k < n; k++)
				w[k][arr[r]] = w[k][arr[r]] + eta * (x[k] - w[k][arr[r]]);
	}
	cout << "Values of weights after update\n";
	for (int k = 0; k < j; k++) {
		for (int r = 0; r < n; r++)
			cout << "W(" << r << ")(" << k << ")=" << w[r][k] << "  ";
		cout << endl;
	}
}
