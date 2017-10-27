#include <iostream>
#include <vector>
#include <algorithm>

bool next_combination(std::vector<int>& v, int n) {
	int k = v.size();
	int p = k - 1;
	if (v[p] >= n) return false;
	while (p >= 0 && ++v[p] >= n - (k - p - 1)) --p;
	if (p < 0) return false;
	++p;
	while (p < k) {
		v[p] = v[p - 1] + 1;
		++p;
	}
	return true;
}

int main(){
    int n = 6;
    std::vector<int> v(3);
    std::iota(v.begin(), v.end(), 0);
    
    do{
        for(auto x : v){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }while(next_combination(v, n));
    
    return 0;
}

/*
 *0 1 2 
0 1 3 
0 1 4 
0 1 5 
0 2 3 
0 2 4 
0 2 5 
0 3 4 
0 3 5 
0 4 5 
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
みたいになる

*/
