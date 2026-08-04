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
    };
    } // namespace mpcd

    } // namespace hoomd
