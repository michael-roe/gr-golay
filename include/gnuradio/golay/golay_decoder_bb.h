/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_GOLAY_GOLAY_DECODER_BB_H
#define INCLUDED_GOLAY_GOLAY_DECODER_BB_H

#include <gnuradio/golay/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
namespace golay {

/*!
 * \brief <+description of block+>
 * \ingroup golay
 *
 */
class GOLAY_API golay_decoder_bb : virtual public gr::sync_decimator {
public:
  typedef std::shared_ptr<golay_decoder_bb> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of golay::golay_decoder_bb.
   *
   * To avoid accidental use of raw pointers, golay::golay_decoder_bb's
   * constructor is in a private implementation
   * class. golay::golay_decoder_bb::make is the public interface for
   * creating new instances.
   */
  static sptr make();
};

} // namespace golay
} // namespace gr

#endif /* INCLUDED_GOLAY_GOLAY_DECODER_BB_H */
