// Copyright (c) 2009-2026 The Regents of the University of Michigan.
// Part of HOOMD-blue, released under the BSD 3-Clause License.

#include "hoomd/ParticleData.h"
#include "hoomd/SystemDefinition.h"

namespace hoomd
    {
struct ParticleLoader
    {
    ParticleLoader(std::shared_ptr<SystemDefinition> sysdef)
        : m_pdata(sysdef->getParticleData()) { }
    const auto& getPositions() const
        {
        return m_pdata->getPositions();
        }
    const auto& getVelocities() const
        {
        return m_pdata->getVelocities();
        }
    const auto& getTags() const
        {
        return m_pdata->getTags();
        }
    auto getN() const
        {
        return m_pdata->getN();
        }

    private:
    std::shared_ptr<ParticleData> m_pdata; //!<  Particle data

    public:
    class VelocityMassReader
        {
        public:
        VelocityMassReader(const Scalar4* vel) : m_vel(vel) { }
        void read(Scalar3& velocity, Scalar& mass, unsigned int idx) const
            {
            const Scalar4 vel = m_vel[idx];
            velocity.x = vel.x;
            velocity.y = vel.y;
            velocity.z = vel.z;
            mass = vel.w;
            }

        private:
        const Scalar4* m_vel;
        };
    VelocityMassReader makeVelocityMassReader(const Scalar4* vel) const
        {
        return VelocityMassReader(vel);
        }
    };

    } // namespace hoomd
