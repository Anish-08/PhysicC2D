#include "broadphase.hpp"

namespace Physicc::Broadphase
{
    namespace BroadphaseImpl
    {
        inline bool isLeaf(BVHNode* node)
        {
            return (node->left == nullptr)&&(node->right == nullptr) ;

        }
        
        void getPotentialContactsWith(BVHNode* node1, BVHNode* node2, std::vector<PotentialContact>& collisionArray)
		{

            if (! node1->volume.overlapsWith(node2->volume))
            {
                return;
            }


			if (isLeaf(node1) && isLeaf(node2))
			{
				collisionArray.push_back(PotentialContact(node1->body, node2->body));
			} 
            else if (isLeaf(node1) && !isLeaf(node2))
			{
			
				getPotentialContactsWith(node1, node2->left, collisionArray);
				getPotentialContactsWith(node1, node2->right, collisionArray);
				
			} 
            
            else if (!isLeaf(node1) && isLeaf(node2))
			{
				getPotentialContactsWith(node1->left, node2, collisionArray);
				getPotentialContactsWith(node1->right, node2, collisionArray);
			} 
            else
			{
			
	
				getPotentialContactsWith(node1->left, node2, collisionArray);
				getPotentialContactsWith(node1->right, node2, collisionArray);
				

			}
		}


        void getPotentialContacts(BVHNode* node, std::vector<PotentialContact>& collisionArray)
		{
			if (isLeaf(node)) return;
			
			BroadphaseImpl::getPotentialContacts(node->left, collisionArray);
			BroadphaseImpl::getPotentialContacts(node->right, collisionArray);

			BroadphaseImpl::getPotentialContactsWith(node->left, node->right, collisionArray);
			
		}
    }

    std::vector<PotentialContact> getPotentialContacts(BVHNode* node)
	{
		std::vector<PotentialContact> v;
		BroadphaseImpl::getPotentialContacts(node, v);
		return v;
	}

	std::vector<PotentialContact> getPotentialContacts(BVH bvh){
		return getPotentialContacts(bvh.getHeadNode());
	}
}