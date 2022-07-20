#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2022 Michael Roe.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks

try:
  from gnuradio.golay import golay_decoder_bb
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.golay import golay_decoder_bb

class qa_golay_decoder_bb(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        instance = golay_decoder_bb()

    def test_001_zero_errors(self):
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        expected_result = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        src = blocks.vector_source_b(src_data)
        golay = golay_decoder_bb()
        dst = blocks.vector_sink_b()
        self.tb.connect(src, golay, dst)
        self.tb.run ()
        result_data = dst.data()
        self.assertEqual(result_data, expected_result)

    def test_002_zero_errors_in_data(self):
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        expected_result = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        src = blocks.vector_source_b(src_data)
        golay = golay_decoder_bb()
        dst = blocks.vector_sink_b()
        self.tb.connect(src, golay, dst)
        self.tb.run ()
        result_data = dst.data()
        self.assertEqual(result_data, expected_result)

    def test_003_one_error_in_data(self):
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        expected_result = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        src = blocks.vector_source_b(src_data)
        golay = golay_decoder_bb()
        dst = blocks.vector_sink_b()
        self.tb.connect(src, golay, dst)
        self.tb.run ()
        result_data = dst.data()
        self.assertEqual(result_data, expected_result)

    def test_004_two_errors_in_data(self):
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        expected_result = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        src = blocks.vector_source_b(src_data)
        golay = golay_decoder_bb()
        dst = blocks.vector_sink_b()
        self.tb.connect(src, golay, dst)
        self.tb.run ()
        result_data = dst.data()
        self.assertEqual(result_data, expected_result)

    def test_005_three_errors_in_data(self):
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        src_data = (1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
        expected_result = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        src = blocks.vector_source_b(src_data)
        golay = golay_decoder_bb()
        dst = blocks.vector_sink_b()
        self.tb.connect(src, golay, dst)
        self.tb.run ()
        result_data = dst.data()
        self.assertEqual(result_data, expected_result)

if __name__ == '__main__':
    gr_unittest.run(qa_golay_decoder_bb)
