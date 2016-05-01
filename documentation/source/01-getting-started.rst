Developer information
*********************

Version of this manual: |version|.

Welcome to the developer documentation. You will find here I hope most of the
information to contribute to the code without any issue. Nevertheless is you
have any questions, there is several channels to ask your questions. Please,
see `Communication`_ section.


Communication
=============

Most communication happens on the mailing list and IRC channel. See the `contact`_
page for more information.

No spamming or flaming is allowed on the lists or IRC channels. Please, stay on
topic in the lists and follow the net etiquette. Also, do not send html message
on the mailing lists.

If necessary, regular online meetings can be organised if enough people shows an
interest. Contact us to let us know.


Getting started
===============

Building Ears Wide Open
-----------------------

See :doc:`02-building` chapter.


Decisions
---------

Because the project is very tiny at the moment, the decisions are taken by the
main contributors and/or users. This could evolve with the project evolution.

Bug fixing
----------

One of the easiest way to get involved in the project is by fixing bugs. Bug-fixing
let you focus on a small part of the project rather than trying to understand
it all at once. There is a list of current bugs on `Github issues`_. So pick
an area of interest and start fixing! Once you have got it, `make a patch and
submit it`_

Navigating the code
-------------------

Have a look at the file structure and code layout diagram.

+-----------------------+-------------------------------------------------------+
| Directory             | Use                                                   |
+=======================+=======================================================+
| /documentation/       | Document generation (sphinx), man page                |
+-----------------------+-------------------------------------------------------+
| /sources/             | Main source code directory for code maintained by     |
|                       | Ears Wide Open developers.                            |
+-----------------------+-------------------------------------------------------+
| /tools/               | Different scripts or programs useful for the          |
|                       | development and configuration of the project.         |
+-----------------------+-------------------------------------------------------+
| README.md             | Readme file of the project. If you need anything, it's|
|                       | usually a good place where to start.                  |
+-----------------------+-------------------------------------------------------+
| LICENSE               | Complete license description used in the project.     |
+-----------------------+-------------------------------------------------------+

Coding guideline
----------------

The coding guideline chosen corresponds to the Linux kernel. For the specifics,
please refer to the :doc:`03-coding-guideline`.

Development process
-------------------


- Getting started

  - building [DONE]
  - diving into the code (explanation of the tree in a dedicated page) [WIP]
  - coding guideline (develop all the code guideline in a dedicated page) [DONE]
  - debugging
  - development process

    - atlassian git flow (+ sign-off) (update the README accordingly
    - pick up an issue
    - how to submit a patch through email or pull-request

  - technical documentation 
    - algo design, 
    - optimisation, 
    - complexity, 
    - C-fixed, 
    - ...

- contributions
- autodoc


.. _contact: https://earswideopen.net/support#contact
