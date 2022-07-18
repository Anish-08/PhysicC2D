#include<iostream>
#include "rigidbody.hpp"
#include <vector>
#include "bvh.hpp"
#include "broadphase.hpp"
#include "testcases.hpp"
#include<chrono>

using namespace std;
using namespace std::chrono;



int main()
{ 

	int x = 50000;
	std::vector<Physicc::RigidBody> mylist ;
	mylist = testcases(x);
	std::vector<Physicc::Broadphase::PotentialContact> variable;
	Physicc::BVH mybvh{mylist};

	auto start = high_resolution_clock::now();
	mybvh.buildTree();
	//variable = Physicc::Broadphase::getPotentialContacts(mybvh);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


	auto stort = high_resolution_clock::now();

	variable = Physicc::Broadphase::getPotentialContacts(mybvh);

	auto stap = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stap - stort);
	

	int n = variable.size();
	//cout<<"Number of collisions : " <<n<<'\n';

	auto what = high_resolution_clock::now();

	int ans = 0;
	for(int i = 0 ; i < x ; i++){
		for(int j = i+1; j<x ; j++){
			if(mylist[i].getAABB().overlapsWith(mylist[j].getAABB())) ans++;
		}
	}

	auto which = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(which - what);
	//cout<<"Number of collisions 1 : " <<ans<<'\n';

	cout << "Time taken by bvh: "<< duration.count() << " microseconds" << endl;
	cout << "Time taken by broad: "<< duration3.count() << " microseconds" << endl;
	cout << "Time taken by brute force: "<< duration1.count() << " microseconds" << endl;
	
	if(n == ans){cout<<"Yeah it worked"<<endl;}
	return 0;

	/*for(int i = 0 ; i< n ; i++)
	{
		variable[i].printcontact();
	}*/
}