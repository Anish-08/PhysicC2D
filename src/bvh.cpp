#include "bvh.hpp"

namespace Physicc
{

    //some code  to get rigid body list


    BoundingVolume::AABB BVH::computeBV(std::size_t start, std::size_t end)
    {
        BoundingVolume::AABB bv(m_rigidBodyList[start].getAABB());

        for(std::size_t i = start+1 ; i<= end ; i++ )
        {
            bv = BoundingVolume::enclosingBV(bv , m_rigidBodyList[i].getAABB());

        }
        return bv;
    }

    std::size_t BVH::BuildingLogic(std::size_t start, std::size_t end) 
    {
        return (start+end)/2; 
    }


    inline void BVH::buildTree()
	{
		buildTree(m_head, 0, m_rigidBodyList.size() - 1);
	}

    void BVH::buildTree (BVHNode* node, std::size_t start, std::size_t end )
    {
        
        if (start == end)
		{
			node->volume = m_rigidBodyList[start].getAABB();
			node->body = &m_rigidBodyList[start];

		} 
        
        else
		{
			node->volume = BoundingVolume::AABB(computeBV(start, end));

			auto leftNode = new BVHNode;
			auto rightNode = new BVHNode;

			node->left = leftNode;
			node->right = rightNode;

			leftNode->parent = node;
			rightNode->parent = node;

            std::size_t sz ;
            sz = BuildingLogic(start,end) ;

			buildTree(leftNode, start, sz);
			buildTree(rightNode, sz+1, end);
		}

    }
}