#!/bin/sh

PWD=$(pwd)
PACKAGES="\
    libtool \
    libportaudio2 \
    portaudio19-dev \
    libasound2 \
    libasound2-dev\
    "

# Install all required packages existing in Ubuntu 12.04
sudo add-apt-repository ppa:dns/gnu -y
sudo apt-get update -qq
## Specific update of autoconf and automake to avoid a bug from an obsolete command
sudo apt-get -y upgrade 
sudo apt-get install -y $PACKAGES

# Installation of Cmocka framework
wget https://cmocka.org/files/1.0/cmocka-1.0.1.tar.xz
tar -xvf cmocka-1.0.1.tar.xz
cd cmocka-1.0.1
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
cd $PWD

# Installation of Yajl library
wget http://github.com/lloyd/yajl/tarball/2.1.0 -O yajl-2.1.0.tar.gz
tar -xvf yajl-2.1.0.tar.gz
cd lloyd-yajl-66cb08c/
mkdir build
cd build
cmake ..
make
sudo make install
cd $PWD
