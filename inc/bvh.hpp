#ifndef BVH_H
#define BVH_H

#include "glm/glm.hpp"
#include "boundingvolume.hpp"
#include "rigidbody.hpp"
#include "vector"

namespace Physicc
{
	struct BVHNode
	{
		BoundingVolume::AABB volume;
		RigidBody* body = nullptr;

		BVHNode* parent = nullptr;
		BVHNode* left = nullptr;
		BVHNode* right = nullptr;
	};

	class BVH
	{
		public:
			BVH(std::vector<RigidBody> rigidBodyList);

            void buildTree();

			BVHNode* getHeadNode()
			{
				return m_head;
			}
			
		private:
			BVHNode* m_head;
			std::vector<RigidBody> m_rigidBodyList;

			BoundingVolume::AABB computeBV(std::size_t start, std::size_t end);

			void buildTree(BVHNode* node, std::size_t start, std::size_t end);

            std::size_t BuildingLogic(std::size_t start, std::size_t end) ;
		
	};
}

#endif