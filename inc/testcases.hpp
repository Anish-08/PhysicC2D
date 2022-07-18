#include "rigidbody.hpp"
#include "glm/glm.hpp"

std::vector<Physicc::RigidBody> testcases(int x)
{
    std::vector<Physicc::RigidBody> mylist;
	glm::vec3 lb[x+1] , ub[x+1];
	Physicc::RigidBody a[x+1];
    srand(time(0));
	for(int i = 0; i < x; i++){
        lb[i].x = -100 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(200)));
        lb[i].y = -100 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(200)));
        ub[i].x = lb[i].x + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100)));
        ub[i].y = lb[i].y + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100)));
		a[i].SetThisVolume(lb[i],ub[i]);
		mylist.push_back(a[i]);
	}

    return mylist;
}