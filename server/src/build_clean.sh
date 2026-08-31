#!/bin/bash
cd `dirname $0`
rm -rf /tars_data/tars_cpp/app_log/
rm -rf /tars_data/tars_cpp/app_log/
###########################
cd protocols
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "libprotocols clean failed"
    exit 0
fi
cd -

###########################
cd util
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "libutil clean failed"
    exit 0
fi
cd -

###########################
cd comm
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "libcomm clean failed"
    exit 0
fi
cd -

###########################
cd activityserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "activityserver clean failed"
    exit 0
fi
cd - 

###########################
cd configserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "configserver clean failed"
    exit 0
fi
cd -

###########################
cd dbagentserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "dbagentserver clean failed"
    exit 0
fi
cd -

###########################
cd globalserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "globalserver clean failed"
    exit 0
fi
cd -

###########################
cd gmserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "gmserver clean failed"
    exit 0
fi
cd -

###########################
cd hallserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "hallserver clean failed"
    exit 0
fi
cd -

###########################
cd httpserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "httpserver clean failed"
    exit 0
fi
cd -

###########################
cd log2dbserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "log2dbserver clean failed"
    exit 0
fi
cd -

###########################
cd loginserver
rm -f *.tgz
make clean
if [ $? -ne 0 ]; then
    echo "loginserver clean failed"
    exit 0
fi
cd -

###########################
echo "All project compilation completed"
