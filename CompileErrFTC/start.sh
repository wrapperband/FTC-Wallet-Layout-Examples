make clean
rm configure
./autogen.sh
autoupdate
./configure --with-incompatible-bdb  --enable-tests=no --with-gui=qt5 --enable-upnp-default --with-qrcode=yes
time make  STATIC=1
qmake-project
