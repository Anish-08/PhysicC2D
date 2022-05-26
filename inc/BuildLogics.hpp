#ifndef H_BUILDLOGICS
#define H_BUILDLOGICS

#include "rigidbody.hpp"
#include <vector>
#include<algorithm>

namespace Physicc
{
    namespace Method1
    {
        // Sorting using custom 
        struct {
        bool operator()(const RigidBody& a,const RigidBody& b) const { return a.getAABB().isGreater(b.getAABB()); }
        } customGreaterThan;

        void sorter(std::vector<RigidBody>& m_rigidBodyList)
        {
            std::sort(std::next(m_rigidBodyList.begin(), 0),
			          std::next(m_rigidBodyList.begin(), m_rigidBodyList.size), customGreaterThan);
        }
    }
}

#endif
