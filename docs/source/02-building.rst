Building Ears Wide Open
***********************

Operating system specific instructions for creating a build from scratch.

* On GNU/Linux
* On MacOs
* On Windows
* On \*BSD

Overview for setting up a build environment
===========================================

This section is only to list main steps you have to follow on all platforms. This
part is intended for anyone unfamiliar with the process of compiling C softwares
from sources.

* install dependencies (git, GCC),
* checkout Ears Wide Open's source code from version control,
* use Make to compile the source code into an executable.

.. todo:: 
        - Create a /lib folder to add the necessary libraries in static and compile against these
          this would maybe avoid to download or install too many things for the
          person willing to contribute and avoid as well version issues (except
          the compiler of course)

Optionnaly you can:

* install a text editor or :term:`IDE`

Build the system
================

Ears Wide Open uses the autotools chain to build its system. The first time 
you want to build the system you will need to run three main commands from the
root of the project:

        $ ./autogen.sh
        $ ./configure
        $ make

At the moment the official release build the software against GCC 5.3.0.

It' possible to run the test suite using the following command:

    $ make check

In order to work, the framework cmocka needs to be installed on the host machine.

.. todo:: 
        - Add to the main Makefile a possibility to compile the documentation

Library versions
================

Here you'll find a list of official libraries used in the project. We'll try to
use at maximum official supported version (i.e those used by official build
environments).

+-----------------------+-----------------------+
| Library               | Version               |
+=======================+=======================+
| Portaudio             | V19                   |
+-----------------------+-----------------------+

Debugging
=========

If you want to use several debugging tools such as GDB or Valgrind, you can 
use the following command with libtool

    $ libtool --mode=execute gdb src/ewo
or
    $ libtool --mode=execute valgrind src/ewo

It's eventually possible to use Valgrind (or GDB?) on the test suite. The command
would be then:

    $ make check TESTS_ENVIRONMENT=valgrind

It's a bit tedious to use this command all the time and have some drawbacks but
there is a `possible workaround`_.

Travis-ci
=========

If you brake the build too many times with Travis-ci, it is recommended to make
test locally on your machine. In order to do so, intall `Docker engine`_ and 
launch it as root. In order to know if Docker is running you can use the 
following command:

    $ docker info

Then, you can run the standard container of travis-ci using the command:

    $ docker run -it quay.io/travisci/travis-ruby /bin/bash

You know have to identify yourself as the travis user:

    $ su - travis

From there, clone the repository you are working on and make the test you need
until the necessary change for the configuration build are done and working.


.. _possible workaround:: http://fragglet.livejournal.com/14291.html
.. _Docker engine:: https://docs.docker.com/engine/installation/
