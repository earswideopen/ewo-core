# -*- coding: utf-8 -*-


def ms2smp(ms, sample_rate):
    """Milliseconds to samples converter.

    Simple converter in order to compute the number of samples for a given
    time frame in milliseconds and the sampling rate.

    Args:

        ms (int):           Number of milliseconds.
        sample_rate (int):  Sampling rate in Hertz.

    Returns:
        Return the number of sample (forced as an int).

    """
    # The factor of 0.001 is to convert the value in milliseconds into seconds.
    # This is done because a sample rate is given in seconds.
    return int(ms * sample_rate * 0.001)
