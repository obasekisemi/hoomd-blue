// Copyright (c) 2009-2026 The Regents of the University of Michigan.
// Part of HOOMD-blue, released under the BSD 3-Clause License.

#include "hoomd/SystemDefinition.h"
#include "hoomd/mpcd/ParticleData.h"

namespace hoomd
    {
namespace mpcd
    {
struct ParticleLoader
    {
    ParticleLoader(std::shared_ptr<SystemDefinition> sysdef)
        : m_mpcd_pdata(sysdef->getMPCDParticleData())
        {
        }
    const auto& getPositions() const
        {
        return m_mpcd_pdata->getPositions();
        }
    const auto& getVelocities() const
        {
        return m_mpcd_pdata->getVelocities();
        }
    const auto& getTags() const
        {
        return m_mpcd_pdata->getTags();
        }
    auto getN() const
        {
        return m_mpcd_pdata->getN();
        }

    private:
    std::shared_ptr<mpcd::ParticleData> m_mpcd_pdata; //!< MPCD particle data

    public:
    class VelocityMassReader
        {
        public:
        VelocityMassReader(const Scalar4* velcell, Scalar mass) : m_velcell(velcell), m_mass(mass)
            {
            }
        void read(Scalar3& velocity, Scalar& mass, unsigned int idx) const
            {
            const Scalar4 velcell = m_velcell[idx];
            velocity.x = velcell.x;
            velocity.y = velcell.y;
            velocity.z = velcell.z;
            mass = m_mass;
            }

        private:
        const Scalar4* m_velcell;
        Scalar m_mass;
        };
    VelocityMassReader makeVelocityMassReader(const Scalar4* velcell) const
        {
        return VelocityMassReader(velcell, m_mpcd_pdata->getMass());
        }
    };
    } // namespace mpcd

    } // namespace hoomd
