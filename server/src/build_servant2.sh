#!/bin/bash

####################
cd httpserver
if [ ! -f "httpserver.tgz" ]; then
    make -j2 && make release && make tar
    if [ $? -ne 0 ]; then
        echo "httpServer build failed"
        exit 0
    fi
fi
cd -

####################
cd configserver
if [ ! -f "*.tgz" ]; then
    make -j2 && make release && make tar
    if [ $? -ne 0 ]; then
        echo "configServer build failed"
        exit 0
    fi
fi
cd -

####################
cd dbagentserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "dbagentServer build failed"
    exit 0
fi
fi
cd -

####################
cd log2dbserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "log2dbServer build failed"
    exit 0
fi
fi
cd -

####################
cd recordserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "recordServer build failed"
    exit 0
fi
fi
cd -

####################
cd globalserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "globalServer build failed"
    exit 0
fi
fi
cd -

####################
cd aiserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "aiServer build failed"
    exit 0
fi
fi
cd -

####################
cd activityserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "activityServer build failed"
    exit 0
fi
fi
cd - 

####################
cd gmserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "gmServer build failed"
    exit 0
fi
fi
cd -

####################
cd hallserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "hallServer build failed"
    exit 0
fi
fi
cd -

####################
cd loginserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "loginServer build failed"
    exit 0
fi
fi
cd -

####################
cd matchserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "matchServer build failed"
    exit 0
fi
fi
cd -

####################
cd orderserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "orderServer build failed"
    exit 0
fi
fi
cd -

####################
cd pushserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "pushServer build failed"
    exit 0
fi
fi
cd -

####################
cd socialserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "socialServer build failed"
    exit 0
fi
fi
cd -

####################
cd roomserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "roomServer build failed"
    exit 0
fi
fi
cd -

####################
cd routerserver
if [ ! -f "*.tgz" ]; then
make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "routerServer build failed"
    exit 0
fi
fi
cd -

####################
