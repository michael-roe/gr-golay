/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(golay_decoder_bb.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(4dd0725e9ef90956496de58930ed3a6b)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/golay/golay_decoder_bb.h>
// pydoc.h is automatically generated in the build directory
#include <golay_decoder_bb_pydoc.h>

void bind_golay_decoder_bb(py::module& m)
{

    using golay_decoder_bb    = gr::golay::golay_decoder_bb;


    py::class_<golay_decoder_bb, gr::sync_decimator,
        std::shared_ptr<golay_decoder_bb>>(m, "golay_decoder_bb", D(golay_decoder_bb))

        .def(py::init(&golay_decoder_bb::make),
           D(golay_decoder_bb,make)
        )
        



        ;




}








