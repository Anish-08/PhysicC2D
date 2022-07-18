#ifndef BROADPHASE_H
#define BROADPHASE_H

#include "glm/glm.hpp"
#include "rigidbody.hpp"
#include "bvh.hpp"
#include <vector>
#include <iostream>

namespace Physicc::Broadphase
{
    struct PotentialContact
    {
        PotentialContact(RigidBody* body1, RigidBody* body2)
		: rb1(body1), rb2(body2)
		{
		}

		RigidBody* rb1; 
        RigidBody* rb2;


        /*void printcontact()
        {
            std::cout<<"{ ";
            rb1->getAABB().printit();
            std::cout<<" ";
	        rb2->getAABB().printit();
            std::cout<<" }"<<'\n';
        }*/
    };

    std::vector<PotentialContact> getPotentialContacts(BVHNode* node);
    std::vector<PotentialContact> getPotentialContacts(BVH bvh);
}


#endif