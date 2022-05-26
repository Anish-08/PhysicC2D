#include<iostream>
#include "rigidbody.hpp"
#include <vector>
#include "bvh.hpp"
#include "broadphase.hpp"
#include "BuildLogics.hpp"

int main()
{ 
	Physicc::RigidBody a1,a2,a3,a4; 
	glm::vec3 v1{0,0,0}, v10{8,4,0} , v2{3,8,0}, v20{8,10,0} , v3{5,3,0}, v30{7,9,0},v4{10,2,0},v40{14,4,0};
	
	a1.SetThisVolume(v1,v10);
	a2.SetThisVolume(v2,v20);
	a3.SetThisVolume(v3,v30);
	a4.SetThisVolume(v4,v40);

	std::vector<Physicc::RigidBody> mylist;
	mylist.push_back(a1);
	mylist.push_back(a2);
	mylist.push_back(a3);
	mylist.push_back(a4);
	
	// Physicc::Method1::sorter(&mylist);

	Physicc::BVH mybvh{mylist};
	mybvh.buildTree();
	
	std::vector<Physicc::Broadphase::PotentialContact> variable;
	variable = Physicc::Broadphase::getPotentialContacts(mybvh);
	int n = variable.size();
	std::cout<<"Number of collisions : " <<n<<'\n';
	for(int i = 0 ; i< n ; i++)
	{
		variable[i].printcontact();
	}
	std::cout<<"Yeah it worked";
	
	return 0;
}