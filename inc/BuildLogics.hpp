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
        bool operator()(const RigidBody& a,const RigidBody& b) const { return a.getAABB().IsGreater(b.getAABB()); }
        } customGreaterThan;

        void sorter(std::vector<RigidBody>& m_rigidBodyList, std::size_t start, std::size_t end)
        {
            std::sort(std::next(m_rigidBodyList.begin(), start),
			          std::next(m_rigidBodyList.begin(), end), customGreaterThan);
        }
    }
}

#endif
