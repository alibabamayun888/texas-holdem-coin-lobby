#!/bin/sh
sh build_clean.sh
if [ $? -ne 0 ]; then
    echo "build_clean build failed"
    exit 0
fi


sh build_comm.sh
if [ $? -ne 0 ]; then
    echo "build_comm build failed"
    exit 0
fi
sh build_tarsproto.sh
if [ $? -ne 0 ]; then
    echo "build_tarsproto build failed"
    exit 0
fi
sh build_servant.sh
if [ $? -ne 0 ]; then
    echo "build_servant build failed"
    exit 0
fi
sh build_dz.sh
if [ $? -ne 0 ]; then
    echo "build_dz build failed"
    exit 0
fi
