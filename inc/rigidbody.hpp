#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "glm/glm.hpp"
#include "boundingvolume.hpp"

namespace Physicc
{
    class RigidBody
    {
        public:


        BoundingVolume::AABB getAABB()
        {
            return m_volume;
        }

        private:
        BoundingVolume::AABB m_volume;
    };

}

#endif