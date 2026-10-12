// Copyright (c) 2009-2026 The Regents of the University of Michigan.
// Part of HOOMD-blue, released under the BSD 3-Clause License.

#include "ParticleLoader.h"
#include "hoomd/ParticleLoader.h"
#include "hoomd/md/ReverseNonequilibriumShearFlowGPU.cuh"

namespace hoomd
    {
namespace mpcd
    {
namespace gpu
    {

template cudaError_t rnes_filter_particles<hoomd::mpcd::ParticleLoader::IndexReader,
                                           hoomd::mpcd::ParticleLoader::VelocityMassReader>(
    Scalar2* d_particles_lo,
    Scalar2* d_particles_hi,
    unsigned int* d_num_lo_hi,
    const Scalar4* d_pos,
    const Scalar4* d_vel,
    const hoomd::mpcd::ParticleLoader::IndexReader&,
    consthoomd::mpcd::ParticleLoader::VelocityMassReader&,
    const Scalar2& pos_lo,
    const Scalar2& pos_hi,
    const unsigned int num_lo_alloc,
    const unsigned int num_hi_alloc,
    const unsigned int N,
    const unsigned int block_size);

template cudaError_t rnes_swap_particles<hoomd::mpcd::ParticleLoader::VelocityMassReader>(
    Scalar4* d_vel,
    Scalar* d_momentum_sum,
    const Scalar2* d_particles_staged,
    const hoomd::mpcd::ParticleLoader::VelocityMassReader&,
    const unsigned int num_staged,
    const unsigned int block_size);

    } // end namespace gpu
    } // end namespace mpcd
    } // end namespace hoomd
