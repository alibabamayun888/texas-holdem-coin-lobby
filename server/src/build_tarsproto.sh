#!/bin/bash

####################
cd httpserver
make release
if [ $? -ne 0 ]; then
    echo "httpServer build failed"
    exit 0
fi
cd -

####################
cd configserver
make release
if [ $? -ne 0 ]; then
    echo "configServer build failed"
    exit 0
fi
cd -

####################
cd dbagentserver
make release
if [ $? -ne 0 ]; then
    echo "dbagentServer build failed"
    exit 0
fi
cd -

####################
cd log2dbserver
make release
if [ $? -ne 0 ]; then
    echo "log2dbServer build failed"
    exit 0
fi
cd -

####################
cd recordserver
make release
if [ $? -ne 0 ]; then
    echo "recordServer build failed"
    exit 0
fi
cd -

####################
cd globalserver
make release
if [ $? -ne 0 ]; then
    echo "globalServer build failed"
    exit 0
fi
cd -

####################
cd activityserver
make release
if [ $? -ne 0 ]; then
    echo "activityServer build failed"
    exit 0
fi
cd - 

####################
cd gmserver
make release
if [ $? -ne 0 ]; then
    echo "gmServer build failed"
    exit 0
fi
cd -

####################
cd hallserver
make release
if [ $? -ne 0 ]; then
    echo "hallServer build failed"
    exit 0
fi
cd -

####################
cd loginserver
make release
if [ $? -ne 0 ]; then
    echo "loginServer build failed"
    exit 0
fi
cd -

####################
cd orderserver
make release
if [ $? -ne 0 ]; then
    echo "orderServer build failed"
    exit 0
fi
cd -

####################
cd pushserver
make release
if [ $? -ne 0 ]; then
    echo "pushServer build failed"
    exit 0
fi
cd -

####################
cd socialserver
make release
if [ $? -ne 0 ]; then
    echo "socialServer build failed"
    exit 0
fi
cd -

####################
cd roomserver
make release
if [ $? -ne 0 ]; then
    echo "roomServer build failed"
    exit 0
fi
cd -

####################
cd routerserver
make release
if [ $? -ne 0 ]; then
    echo "routerServer build failed"
    exit 0
fi
cd -

####################
