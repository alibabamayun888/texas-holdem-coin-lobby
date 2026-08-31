#!/bin/bash

####################
cd httpserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "httpServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd configserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "configServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd dbagentserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "dbagentServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd log2dbserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "log2dbServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd recordserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "recordServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd globalserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "globalServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
#cd aiserver
#rm -f *.tgz
#make clean && make -j2 && make release && make tar
#if [ $? -ne 0 ]; then
#    echo "aiServer build failed"
#    exit 0
#fi
#cd -

####################
cd activityserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "activityServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd - 

####################
cd gmserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "gmServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd hallserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "hallServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd loginserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "loginServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
#cd matchserver
#rm -f *.tgz
#make clean && make -j2 && make release && make tar
#if [ $? -ne 0 ]; then
#    echo "matchServer build failed"
#    exit 0
#fi
#cd -

####################
cd orderserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "orderServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd pushserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "pushServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd socialserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "socialServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd roomserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "roomServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
cd routerserver
rm -f *.tgz
make clean && make -j2 && make release && make tar
if [ $? -ne 0 ]; then
    echo "routerServer build failed"
    exit 0
fi
cp *.tgz ../build/
cd -

####################
