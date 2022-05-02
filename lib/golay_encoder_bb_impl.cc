/* -*- c++ -*- */
/*
 * Copyright 2019-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "golay_encoder_bb_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace golay {

golay_encoder_bb::sptr golay_encoder_bb::make()
{
    return gnuradio::make_block_sptr<golay_encoder_bb_impl>();
}


/*
 * The private constructor
 */
golay_encoder_bb_impl::golay_encoder_bb_impl()
    : gr::sync_interpolator(
          "golay_encoder_bb",
          gr::io_signature::make(1, 1, sizeof(char)),
          gr::io_signature::make(1, 1, sizeof(char)), 2)
{
}

/*
 * Our virtual destructor.
 */
golay_encoder_bb_impl::~golay_encoder_bb_impl() {}

int golay_encoder_bb_impl::work(int noutput_items,
                                gr_vector_const_void_star& input_items,
                                gr_vector_void_star& output_items)
{
    char *in = (char *)input_items[0];
    char *out = (char *)output_items[0];
    int i;

    for (i=0; i<noutput_items/2; i++)
    {
      out[i+i] = in[i];
      out[i+i+1] = in[i];
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace golay */
} /* namespace gr */
