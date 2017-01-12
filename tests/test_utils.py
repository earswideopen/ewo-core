import pytest

from ewo import utils


def test_ms2smp():
    assert utils.ms2smp(1000, 44100) == 44100
