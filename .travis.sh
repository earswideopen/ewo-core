#!/bin/sh

CWD=$(pwd)
PACKAGES="\
    libtool \
    libportaudio2 \
    portaudio19-dev \
    libasound2 \
    libasound2-dev\
    checkinstall \
    "

check_sig () 
{
    if [ -n $SUM ]; then
        echo "$SUM  $NAME-$VERSION.$EXT" > $NAME-$VERSION.$EXT.sha256
        sha256sum -c $NAME-$VERSION.$EXT.sha256
    elif [ -f $NAME-$VERSION.$EXT.sha256 ]; then
        sha256sum -c $NAME-$VERSION.$EXT.sha256
        exit 1
    fi
}

# Require the GPG key for the travis-ci PPA
sudo apt-key adv --recv-keys --keyserver keyserver.ubuntu.com 6B73A36E6026DFCA
# Install all required packages existing in Ubuntu 12.04
sudo apt-get update -qq
## Specific update of autoconf and automake to avoid a bug from an obsolete command
sudo apt-get install -y $PACKAGES

# Installation of automake
NAME=automake
VERSION=1.15
EXT=tar.xz
SUM=9908c75aabd49d13661d6dcb1bc382252d22cc77bf733a2d55e87f2aa2db8636
wget https://ftp.gnu.org/gnu/$NAME/$NAME-$VERSION.$EXT
check_sig $SUM $NAME $VERSION $EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
./configure
make
#sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
sudo make install
cd $CWD

# Installation of autoconf
NAME=autoconf
VERSION=2.69
EXT=tar.xz
SUM=64ebcec9f8ac5b2487125a86a7760d2591ac9e1d3dbd59489633f9de62a57684
wget https://ftp.gnu.org/gnu/$NAME/$NAME-$VERSION.$EXT
check_sig $SUM $NAME $VERSION $EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
./configure
make
#sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
sudo make install
cd $CWD

# Installation of Cmocka framework
NAME=cmocka
VERSION=1.0.1
EXT=tar.xz
SUM=b36050d7a1224296803d216cba1a9d4c58c31bf308b2d6d6649d61aa5a36753b
wget https://cmocka.org/files/1.0/$NAME-$VERSION.$EXT
check_sig $SUM $NAME $VERSION $EXT
tar -xvf $NAME-$VERSION.$EXT
cd $NAME-$VERSION
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ..
make
#sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
sudo make install
cd $CWD

# Installation of Yajl library
NAME=yajl
VERSION=2.1.0
EXT=tar.gz
SUM=510a13e0be57cd4ba99e60ac806a3635854af51316d3131d3742a90298ccde38
wget http://github.com/lloyd/$NAME/tarball/$VERSION -O $NAME-$VERSION.$EXT
check_sig $SUM $NAME $VERSION $EXT
tar -xvf $NAME-$VERSION.$EXT
cd lloyd-yajl-66cb08c/
mkdir build
cd build
cmake ..
make
#sudo checkinstall -y --pkgname $NAME --pkgversion $VERSION
sudo make install
cd $CWD
