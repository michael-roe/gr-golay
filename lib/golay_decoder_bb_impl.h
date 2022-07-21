/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_GOLAY_GOLAY_DECODER_BB_IMPL_H
#define INCLUDED_GOLAY_GOLAY_DECODER_BB_IMPL_H

#include <gnuradio/golay/golay_decoder_bb.h>

namespace gr {
namespace golay {

class golay_decoder_bb_impl : public golay_decoder_bb
{
private:
    unsigned long long d_offset;
    pmt::pmt_t d_parity_error_key;

public:
    golay_decoder_bb_impl();
    ~golay_decoder_bb_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace golay
} // namespace gr

#endif /* INCLUDED_GOLAY_GOLAY_DECODER_BB_IMPL_H */
