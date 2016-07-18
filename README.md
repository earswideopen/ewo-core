# Ear Wide Open

Build status (branch develop): [![Build Status](https://travis-ci.org/earswideopen/ewo.svg?branch=develop)](https://travis-ci.org/earswideopen/ewo)

## Vision

The project aims to create and propose, as a community, an open source hearing
aid system (software and hardware) with the idea of giving the control back to
its user and help him in everyday life situations that he may encounter.

## Language

The development language is English. All comments and documentation should be
written in English, so that we don't end up with “franglais” methods, and so we
can share our learnings with developers around the world.

## History

The project has been thought around February 2015 but really started only in
March 2016.

## Installation

The source code is mainly written in ANSI-C and requires the following program
or libraries for the compilation:

- [gcc](https://gcc.gnu.org/) >= 5.3.0
- [autoconf](https://www.gnu.org/software/autoconf/autoconf.html) >= 2.69
- [GNU Make](https://www.gnu.org/software/make/) >= 4.1
- [Portaudio](http://www.portaudio.com/) >= V19
- [cmocka](https://cmocka.org/) (to run the tests; should be optional)

Once these dependencies are satisfied, you can compile the program using the following
commands from the root of the project:

```
$ ./autogen.sh
$ ./configure
$ make
```

TODO:
- describe the documentation compilation

## Contributing

We’re really happy to accept contributions from the community, that’s the main
reason why we open-sourced it! There are many ways to contribute, even if
you’re not a technical person.

We’re using the infamous [simplified Github workflow][l1] to accept
modifications (even internally), basically you’ll have to:

* create an issue related to the problem you want to fix (good for traceability
  and cross-reference)
* fork the repository
* create a branch (optionally with the reference to the issue in the name)
* hack hack hack
* commit incrementally with readable and detailed commit messages
* submit a pull-request against the master branch of this repository

We’ll take care of tagging your issue with the appropriated labels and answer
within a week (hopefully less!) to the problem you encounter.

If you’re not familiar with open-source workflows or our set of technologies,
do not hesitate to ask for help! We can mentor you or propose good first bugs
(as labeled in our issues). Also welcome to add your name to Credits section 
of this document.

### Submitting bugs

You can report issues directly on Github, that would be a really useful
contribution given that we lack some user testing on the project. Please
document as much as possible the steps to reproduce your problem (even better
with screenshots).

### Discussing strategies

We’re trying to develop this project in the open as much as possible. We have a
dedicated mailing-list where we discuss each new strategic change and invite
the community to give a valuable feedback. You’re encouraged to subscribe to it
and participate.

### Adding documentation

We’re doing our best to document each usage of the project but you can improve
it or add you own sections. The documentation is available in the [documentation
folder](/docs). You don’t have to build anything, we’ll take care of it once your
changes are merged.

### Improving User eXperience

There is no GUI at the moment but we hope to build something based on HTML and
CSS.

## Versioning

We are in the prototyping phase but we'll follow the 
[Semantic versioning][l2] approach.


## Financing

We accept donations, please contact us for any more details at 
[contact@earswideopen.net][l3]

## License

We’re using the [GNU General Public License Version 2](LICENSE). Please refer to the
LICENSE file for more information.

## Credits

- [Matthieu Berjon][l4]


[l1]: http://scottchacon.com/2011/08/31/github-flow.html
[l2]: http://semver.org/
[l3]: mailto:contact@earswideopen.net
[l4]: https://berjon.net/matt
