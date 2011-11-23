#include <vector>
#include <iostream>

int main(){

    using namespace std;

    vector<int> vi;
    
    for(int i=0;i<100;i++)
	vi.push_back(i);

    for(int i=-100;i<vi.size();i++)
	cout << vi[i] << endl;

    cout << vi.front() << ":" << vi.back() << endl;
    return 0;
}
