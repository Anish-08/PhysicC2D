#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "glm/glm.hpp"
#include "boundingvolume.hpp"

namespace Physicc
{
    class RigidBody
    {
        public:


        BoundingVolume::AABB getAABB() const
        {
            return m_volume;
        }

        void SetThisVolume (glm::vec3 lb , glm::vec3 ub)
        {
            m_volume.setVolume(lb,ub) ;
        }

        private:
        BoundingVolume::AABB m_volume;
    };

}

#endif