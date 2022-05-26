#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H

#include "glm/glm.hpp"
#include "glm/gtc/epsilon.hpp"
#include <iostream>

namespace Physicc
{
    namespace BVImpl
    {
        struct AABB
        {

            AABB() = default; // This is needed so that compiler will for sure create the default constructor

            
            AABB(const glm::vec3& lb, const glm::vec3& ub) : lowerBound(lb), upperBound(ub)
			{
			}

            //The two variables in this structure
            glm::vec3 lowerBound;
            glm::vec3 upperBound;
        };

        class BaseBV
        {
            // Lots of stuff I don't understand
        };
        
        class BoxBV: public BaseBV
        {
            public:

            BoxBV() = default;

            BoxBV(glm::vec3 lbound , glm::vec3 ubound) 
            {
                m_volume.lowerBound = lbound;
                m_volume.upperBound = ubound;
            }
    
            //Some constructors 


            inline void setVolume(const AABB& volume)
            {
                m_volume = volume;
            }

            inline void setVolume(const glm::vec3& lowerBound, const glm::vec3& upperBound)
            {
                m_volume = {lowerBound,upperBound} ;
            }

            inline void printit()
            {
                std::cout<<"("<<m_volume.lowerBound.x<<","<<m_volume.lowerBound.y<<" ; "<<m_volume.upperBound.x<<","<<m_volume.upperBound.y<<")";
            }
            inline float getVolume() const
            {
                return (m_volume.upperBound.x - m_volume.lowerBound.x) 
                *(m_volume.upperBound.y - m_volume.lowerBound.y) ;
            }

            inline bool overlapsWith(const BoxBV& bv) const
            {
                return ((m_volume.lowerBound.x <= bv.m_volume.upperBound.x)
                        && (m_volume.upperBound.x >= bv.m_volume.lowerBound.x))
                    && ((m_volume.lowerBound.y <= bv.m_volume.upperBound.y)
                        && (m_volume.upperBound.y >= bv.m_volume.lowerBound.y));
            }

            inline BoxBV enclosingVolume(const BoxBV bv) const
            {
                glm::vec3 minvec = glm::min(m_volume.lowerBound,bv.m_volume.lowerBound);
                glm::vec3 maxvec = glm::max(m_volume.upperBound,bv.m_volume.upperBound);
                return {minvec,maxvec};
            }

            inline bool IsGreater(const BoxBV bv) const
            {
                if((m_volume.lowerBound.x+m_volume.upperBound.x)!= (bv.m_volume.lowerBound.x+bv.m_volume.upperBound.x))
                {
                    return (m_volume.lowerBound.x+m_volume.upperBound.x)> (bv.m_volume.lowerBound.x+bv.m_volume.upperBound.x);
                }
                else return (m_volume.lowerBound.y+m_volume.upperBound.y)> (bv.m_volume.lowerBound.y+bv.m_volume.upperBound.y);
            }

            private:

            AABB m_volume;
        };
        
    }

    namespace BoundingVolume
    {
        typedef BVImpl::BoxBV AABB;


        auto inline enclosingBV(const BVImpl::BoxBV& volume1,const BVImpl::BoxBV& volume2)
		{

			return volume1.enclosingVolume(volume2);
		}
    }
}

#endif 