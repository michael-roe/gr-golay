/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_GOLAY_GOLAY_ENCODER_BB_IMPL_H
#define INCLUDED_GOLAY_GOLAY_ENCODER_BB_IMPL_H

#include <gnuradio/golay/golay_encoder_bb.h>

namespace gr {
namespace golay {

class golay_encoder_bb_impl : public golay_encoder_bb
{
private:
    // Nothing to declare in this block.

public:
    golay_encoder_bb_impl();
    ~golay_encoder_bb_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace golay
} // namespace gr

#endif /* INCLUDED_GOLAY_GOLAY_ENCODER_BB_IMPL_H */
