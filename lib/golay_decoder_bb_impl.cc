/* -*- c++ -*- */
/*
 * Copyright 2019-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "golay_decoder_bb_impl.h"
#include <gnuradio/io_signature.h>
#include <volk/volk.h>

namespace gr {
namespace golay {

golay_decoder_bb::sptr golay_decoder_bb::make() {
  return gnuradio::make_block_sptr<golay_decoder_bb_impl>();
}

/*
 * The private constructor
 */
golay_decoder_bb_impl::golay_decoder_bb_impl()
    : gr::sync_decimator(
          "golay_decoder_bb",
          gr::io_signature::make(1, 1, sizeof(char)),
          gr::io_signature::make(1, 1, sizeof(char)), 2)
{
  set_output_multiple(12);
  d_offset = 0;
  d_parity_error_key = pmt::string_to_symbol("parity_error");
}

/*
 * Our virtual destructor.
 */
golay_decoder_bb_impl::~golay_decoder_bb_impl() {}

static int onebit[12] = {
  3189,
  1595,
  3944,
  1972,
  986,
  3481,
  1741,
  871,
  3526,
  2711,
  2366,
  2283
};

static int transpose[12] = {
  2639,
  3944,
  1972,
  986,
  493,
  2745,
  3859,
  3526,
  1763,
  2366,
  1183,
  3189
};

int golay_decoder_bb_impl::work(int noutput_items,
                                gr_vector_const_void_star &input_items,
                                gr_vector_void_star &output_items)
{
  char *in = (char *)input_items[0];
  char *out = (char *)output_items[0];
  int i;
  int j;
  int k;
  int parity;
  int found;
  unsigned int s;
  unsigned int t;
  unsigned int w1;
  unsigned int bits;

  w1 = 1 | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 10) | (1 << 11);

  for (i=0; i<noutput_items/12; i++)
  {
    parity = 0;
    s = 0;
    for (j=11; j>=0; j--)
    {
      parity ^= in[24*i + j] & 0x1;
      s ^= (in[24*i + j] & 0x1);
      if (s & 0x1)
      {
        s ^= w1;
      }
      s = s >> 1;
      out[12*i + j] = in[24*i + j];
    }
    for (j=12; j<23; j++)
    {
      if (s & (1 << (22 - j)))
      {
        parity ^= 1;
      }
      if (in[24*i+j] & 0x01)
      {
        s ^= (1 << (22 - j));
      }
    }
    parity ^= in[24*i+23] & 0x1;
    s = (s << 1) | parity;
    if (s == 0)
    {
      /* no errors, nothing to do */
    }
    else
    {
      volk_32u_popcnt(&bits, s);
      if (bits <= 3)
      {
        /* errors only in the check bits, nothing to do */
      }
      else
      {
        found = 0;
        for (j=0; j<12; j++)
	{
          volk_32u_popcnt(&bits, s^onebit[j]);
	  if (bits <= 2)
	  {
	    out[12*i + j] ^= 0x1;
	    found = 1;
	    break;
	  }
	}
	if (found == 0)
	{
          t = 0;
	  for (j=0; j<12; j++)
          {
            if (in[i*24 + j + 12])
	    {
	      t ^= transpose[j];
	    }
          }
	  for (j=0; j<12; j++)
	  {
            if (in[i*24 + j])
	    {
              t ^= 1 << (11 - j);
	    }
          }
	  volk_32u_popcnt(&bits, t);
	  if (bits <= 3)
	  {
	    for (j=0; j<12; j++)
	    {
	      if (t & (1 << (11 - j)))
	      {
	        out[12*i + j] ^= 0x1;
	      }
	    }
	  }
	  else
          {
	    found = 0;
	    for (j=0; j<12; j++)
	    {
	      volk_32u_popcnt(&bits, t^transpose[j]);
	      if (bits <= 2)
	      {
	        found = 1;
	        t ^= transpose[j];
		for (k=0; k<12; k++)
		{
	          if (t & (1 << (11 - k)))
	          {
	            out[12*i + k] ^= 0x1;
		  }
	        }
	        
		break;
              }
	    }
	    if (found == 0)
	    {
              add_item_tag(0, d_offset+12*i, d_parity_error_key, pmt::PMT_T);
	    }
          }
        }
      }
    }
  }

  d_offset += noutput_items;

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace golay */
} /* namespace gr */
