/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_GOLAY_GOLAY_ENCODER_BB_H
#define INCLUDED_GOLAY_GOLAY_ENCODER_BB_H

#include <gnuradio/golay/api.h>
#include <gnuradio/sync_interpolator.h>

namespace gr {
namespace golay {

/*!
 * \brief <+description of block+>
 * \ingroup golay
 *
 */
class GOLAY_API golay_encoder_bb : virtual public gr::sync_interpolator
{
public:
    typedef std::shared_ptr<golay_encoder_bb> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of golay::golay_encoder_bb.
     *
     * To avoid accidental use of raw pointers, golay::golay_encoder_bb's
     * constructor is in a private implementation
     * class. golay::golay_encoder_bb::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace golay
} // namespace gr

#endif /* INCLUDED_GOLAY_GOLAY_ENCODER_BB_H */
