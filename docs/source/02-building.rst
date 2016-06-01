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

Blender uses Make build system through a Makefile. In order to perform the build
you have to go to the /source folder and launch the command:

        $ make

At the moment the official release build the software against GCC 5.3.0.

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
