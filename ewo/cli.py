# -*- coding: utf-8 -*-

""" Command line module

Give the possibility to use the program through a simple command line system.

Note:
    It could be interesting to have a kind of group command to select the type
    of AudioSource and have the right range of parameters that goes with it.

    .. code-block:: bash
        
        $ ewo microphone -s 44100
        $ ewo microphone -o outputfile.wav

"""

from __future__ import absolute_import

import click
import logging
import sys

from . import __version__


logging.basicConfig(filename='ewo-core.log', level=logging.DEBUG)


def version_msg():
    """ Return the program version, location and python version.

    Returns:
        return the version the program as well as the Python version

    """
    python_version = sys.version[:3]
    message = 'ewo-core %(version)s (Python {})'
    return message.format(python_version)


@click.command(context_settings=dict(help_option_names=['-h', '--help']))
@click.version_option(
        __version__,
        '-V',
        '--version',
        message=version_msg(),
        help='Version of this application')
def main(args=None):
    """Console script for ewo"""
    click.echo("Replace this message by putting your code into "
               "ewo.cli.main")
    click.echo("See click documentation at http://click.pocoo.org/")


if __name__ == "__main__":
    main()
