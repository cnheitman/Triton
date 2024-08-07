#!/usr/bin/env python3
# coding: utf-8
"""Tester for examples."""
import glob
import itertools
import os
import platform
import subprocess
import sys
import unittest

EXAMPLE_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "examples", "python")

ARGS = {
    "small_x86-64_symbolic_emulator.py":                [os.path.join(EXAMPLE_DIR, "samples", "sample_1"), "hello"],
}


class TestExample(unittest.TestCase):
    """Holder to run examples as tests."""

for i, example in enumerate(itertools.chain(glob.iglob(os.path.join(EXAMPLE_DIR, "*.py")),
                                            glob.iglob(os.path.join(EXAMPLE_DIR, "*", "*.py")),
                                            glob.iglob(os.path.join(EXAMPLE_DIR, "*", "*", "*.py")),
                                            glob.iglob(os.path.join(EXAMPLE_DIR, "*", "*", "*", "*.py")))):

    def _test_example(self, example_name=example):
        """Run example and show stdout in case of fail."""
        args = [v for k, v in list(ARGS.items()) if k in example_name]
        assert len(args) <= 1
        if len(args) == 1:
            args = args[0]

        if ('TRAVIS' in os.environ or 'APPVEYOR' in os.environ) and example_name.find('hackcon-2016-angry-reverser') >= 0:
            # FIXME: Doesn't work on Travis and Appveyor...
            return
        if ('APPVEYOR' in os.environ or not 'COMPILE_RISCV' in os.environ) and example_name.find('riscv') >= 0:
            return

        p = subprocess.Popen([sys.executable, example_name] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = p.communicate()
        self.assertEqual(p.returncode, 0, "\n".join((str(out), str(err), str(p.returncode))))

    # Define an arguments with a default value as default value is capture at
    # lambda creation so that example_name is not in the closure of the lambda
    # function.
    setattr(TestExample, "test_" + str(i) + "_" + os.path.basename(example), _test_example)
