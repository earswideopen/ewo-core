#!/bin/sh

ROOT_PWD=$(pwd)
PACKAGES="\
    libtool \
    libportaudio2 \
    portaudio19-dev \
    libasound2 \
    libasound2-dev\
    checkinstall \
    "

# Install all required packages existing in Ubuntu 12.04
sudo apt-get update -qq
## Specific update of autoconf and automake to avoid a bug from an obsolete command
sudo apt-get install -y $PACKAGES

# Installation of automake
NAME=automake
VERSION=1.15
EXT=tar.gz
wget https://ftp.gnu.org/gnu/$NAME/$NAME-$VERSION.$EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
./configure
make
sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
cd $ROOT_PWD

# Installation of autoconf
NAME=autoconf
VERSION=2.69
EXT=tar.xz
wget https://ftp.gnu.org/gnu/$NAME/$NAME-$VERSION.$EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
./configure
make
sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
cd $ROOT_PWD

# Installation of Cmocka framework
NAME=cmocka
VERSION=1.0.1
EXT=tar.xz
wget https://cmocka.org/files/1.0/$NAME-$VERSION.$EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ..
make
sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
cd $ROOT_PWD

# Installation of Yajl library
NAME=yajl
VERSION=2.1.0
EXT=tar.gz
wget http://github.com/lloyd/$NAME/tarball/$VERSION -O $NAME-$VERSION.$EXT
tar -xvf $NAME-$VERSION.$EXT
cd lloyd-yajl-66cb08c/
mkdir build
cd build
cmake ..
make
sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
cd $ROOT_PWD
