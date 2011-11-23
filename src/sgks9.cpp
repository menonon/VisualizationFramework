#include <vector>
#include <iostream>


struct pos3d{
public:
    double pos[3];

    pos3d(double a,double b, double c){pos[0]=a;pos[1]=b;pos[2]=c;}
};

int main(){


    using namespace std;
    
    vector<vector<pos3d> > vecvecd3;

    pos3d d31(0,1,2);
    pos3d d32(3,4,5);
    vector<pos3d> vecd3;

    vecd3.push_back(d31);
    vecvecd3.push_back(vecd3);
    
    vecd3.push_back(d32);
    vecvecd3.push_back(vecd3);


    for(int j=0;j<vecvecd3.size();++j)
	for(int k=0;k<vecvecd3[j].size();++k)
	    for(int i=0;i<3;++i){
		cout << j << "," << k << "," << i << ":" << vecvecd3[j][k].pos[i]<< endl;
	    }

    cout << endl;

    int i=0;
    for(double* ptr = &vecvecd3[0][0].pos[0];i<6;++ptr){
	cout << (*ptr) << endl;
	i++;
    }

    cout << endl;

    vector<double> ddd;
    ddd.push_back(1);
    ddd.push_back(2);
    ddd.push_back(3);
    ddd.push_back(4);

    int h=0;
    for(double* ptr= &ddd[0];h<4;++ptr){
	cout << (*ptr) << endl;
	++h;
    }

    cout << endl;

    vector<vector<double> > vvd;
    vector<double> vd;
    for(int m=0;m<10;++m)vd.push_back(m);
    vector<double> dv;
    for(int m=10;m>0;--m)dv.push_back(m);
    vvd.push_back(vd);vvd.push_back(dv);
    for(vector<vector<double> >::iterator itt = vvd.begin();itt!=vvd.end();itt++){
	int cap[2];
	cap[0] = vvd.capacity();
	cout << (*itt).size() << endl;
	vector<double>::iterator it = (*itt).end();
	it--;
	cout << (*it) <<endl;
	it--;
	cout << (*it) <<endl;
	it--;
	cout << (*it) <<endl;
	cap[1] = vvd.capacity();

	(*itt).push_back(cap[0]);
	(*itt).push_back(cap[1]);
	(*itt).push_back(cap[0]);
	(*itt).push_back(cap[1]);
	(*itt).push_back(cap[0]);
	(*itt).push_back(cap[1]);
	(*itt).push_back(cap[0]);
	(*itt).push_back(cap[1]);
	(*itt).push_back(cap[0]);
	(*itt).push_back(cap[1]);
    }


    
    return 0;

}
