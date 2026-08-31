#!/bin/bash
cd `dirname $0`

###########################
cd protocols
make publish
if [ $? -ne 0 ]; then
    echo "libprotocol build failed"
    exit 0
fi
cd -

###########################
cd comm
make publish
if [ $? -ne 0 ]; then
    echo "libcomm build failed"
    exit 0
fi
cd -

###########################
cd util
make publish
if [ $? -ne 0 ]; then
    echo "libutil build failed"
    exit 0
fi
cd -

###########################
echo "All project compilation completed"
