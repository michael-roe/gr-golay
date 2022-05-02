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
 * \brief Encode bits using the extended binary Golay code
 * \ingroup golay
 * \details
 * For each twelve bits of input, the output is the 12 input bits followed by
 * 12 bits of error correction.
 * 
 * The error correction bits are formed by regarding the input bits as a
 * polynomial over GF(2), multiplying it by x**11 and taking the remainder after
 * division by x**11+x**9+x**7+x**6+x**5+x+1. The error correction bits are the
 * coefficients of the remainder followed by a parity bit to give the 24 bit
 * output block even parity.
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
