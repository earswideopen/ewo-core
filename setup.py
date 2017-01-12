#!/usr/bin/env python
# -*- coding: utf-8 -*-

#  from setuptools import setup
from setuptools import setup, find_packages

with open('README.rst') as readme_file:
    readme = readme_file.read()

with open('HISTORY.rst') as history_file:
    history = history_file.read()

requirements = [
        'PyAudio>=0.2.9',
        'click>=6.7',
        ]
test_requirements = [
    # TODO: put package test requirements here
]

setup(
    name='ewo',
    version='0.2.2',
    description="Open source hearing system software",
    long_description=readme + '\n\n' + history,
    author="Matthieu Berjon",
    author_email='matthieu@berjon.net',
    url='https://github.com/earswideopen/ewo-core',
    packages=find_packages(),
    package_dir={'ewo':
                 'ewo'},
    entry_points={
        'console_scripts': [
            'ewo=ewo.cli:main'
        ]
    },
    include_package_data=True,
    install_requires=requirements,
    license="GNU General Public License v3",
    zip_safe=False,
    keywords='ewo',
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: GNU General Public License v2 (GPLv2)',
        'Natural Language :: English',
        "Programming Language :: Python :: 2",
        'Programming Language :: Python :: 2.6',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
    ],
    test_suite='nose.collector',
    tests_require=test_requirements
)
