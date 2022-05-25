#include "bvh.hpp"
#include <vector>
#include <iostream>

namespace Physicc
{

    
    BVH::BVH(std::vector<RigidBody> rigidBodyList)
		: m_rigidBodyList(std::move(rigidBodyList)) 
	{
        auto m_head = new BVHNode;
	}

    BoundingVolume::AABB BVH::computeBV(std::size_t start, std::size_t end)
    {
        BoundingVolume::AABB bv{m_rigidBodyList[start].getAABB()};

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


    void BVH::buildTree()
	{
        BVHNode* new_m_head = new BVHNode;
        m_head = new_m_head;
		buildTree(new_m_head, 0, m_rigidBodyList.size() - 1);
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
            
            BoundingVolume::AABB sample;
			sample = computeBV(start, end);
            
            node->volume = sample ;
            std::cout<<node->volume.getVolume()<<'\n';
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