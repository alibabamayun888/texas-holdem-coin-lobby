#!/bin/bash

####################
cd dz
#make clean
rm -f build/*.so
make -j2
cp build/*.so ../build/
cd ..

####################
