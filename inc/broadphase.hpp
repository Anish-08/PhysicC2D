#ifndef BROADPHASE_H
#define BROADPHASE_H

#include "glm/glm.hpp"
#include "rigidbody.hpp"
#include "bvh.hpp"
#include <vector>

namespace Physicc::Broadphase
{
    struct PotentialContact
    {
        PotentialContact(RigidBody* body1, RigidBody* body2)
		: rb1(body1), rb2(body2)
		{
		}
        //Proper constructor not present ?

		RigidBody* rb1; 
        RigidBody* rb2;

    };

    std::vector<PotentialContact> getPotentialContacts(BVHNode* node);
}


#endif