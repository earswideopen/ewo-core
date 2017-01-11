# *-* coding: utf-8 -*-

"""Audio module to manage I/Os and streams.

This module manages the audio I/Os of the computer and send the stream to the
speech recognition engine. It's purpose is to unify all type of sources
(physical or application streams) into one unique system without having
worriying about source types.


Note:

    At the moment, this module takes only the input from the default microphone
    of the laptop. This has to be improved in the future and find a way
    configure easily the defaults.


Todo:

    This needs to be abstracted in order to be able to select any type of
    source on the computer and send the stream to a speech_recognition class
    that will be an interface to any type of speech recognition engine.

    - Give the possibility of creating audio dump in a wav format by giving a
      flag in the command line

"""

import pyaudio
import time


p = pyaudio.PyAudio()


def callback(in_data, frame_count, time_info, status):
    """ Audio callback of the hardware

    This function is the callback (non-blocking) of the audio function and its
    purpose is to connect the input to the output.

    Returns:
        input data
        a bit at 0 in order to continue to deliver the buffers.

    Todo:
        This function should be renamed in order to have a better idea about
        its purpose. It's here as well that the signal processing should be
        done.  It would be nice in the future to be able to load whatever
        signal blocks we want and create a desired chain at startup (or even as
        hot plug).

    """
    return (in_data, pyaudio.paContinue)


def start_recording(
        width=2,
        channel_number=1,
        sample_rate=44100):
    """ Start the stream.

    This function starts the audio stream according to few parameters. It stays
    active thanks to the infinite loop.

    Todo:
        Several things need to be done:
        - Rename the function as it doesn't perform recording but more
          streaming
        - Give the possibility to add more parameters (see PyAudio
          documentation... frame size, device index, ...)
        - Write a small function for the width conversion that isn't really
          easy to handle (audiobits2bits)

    """
    stream = p.open(format=p.get_format_from_width(width),
                    channels=channel_number,
                    rate=sample_rate,
                    input=True,
                    output=True,
                    stream_callback=callback)

    stream.start_stream()

    while stream.is_active():
        time.sleep(1.1)

    stream.stop_stream()
    stream.close()

    p.terminate()
