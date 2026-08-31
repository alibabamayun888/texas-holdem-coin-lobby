
#-----------------------------------------------------------------------

APP           := XGame
TARGET        := RouterServer
CONFIG        := 
STRIP_FLAG    := N
TARS2CPP_FLAG := 
CFLAGS        += -lm
CXXFLAGS      += -lm

INCLUDE   += -I. -I/usr/local/cpp_modules/wbl/include
LIB       += -L/usr/local/cpp_modules/wbl/lib -lwbl

INCLUDE   += -I/usr/local/cpp_modules/protobuf/include
LIB       += -L/usr/local/cpp_modules/protobuf/lib -lprotobuf

INCLUDE   += -I./external
LIB       += 

#
LOCAL_SRC += external/AsyncLoginCallback.cpp \
		external/AsyncLogoutCallback.cpp \
		external/AsyncGetUserCallback.cpp \
		external/AsyncUserStateCallback.cpp

#-----------------------------------------------------------------------
include /home/tarsproto/XGame/OrderServer/OrderServer.mk
include /home/tarsproto/XGame/SocialServer/SocialServer.mk
include /home/tarsproto/XGame/Comm/Comm.mk
include /home/tarsproto/XGame/protocols/protocols.mk
include /home/tarsproto/XGame/LoginServer/LoginServer.mk
include /home/tarsproto/XGame/ConfigServer/ConfigServer.mk
include /home/tarsproto/XGame/RoomServer/RoomServer.mk
include /home/tarsproto/XGame/HallServer/HallServer.mk
include /home/tarsproto/XGame/GlobalServer/GlobalServer.mk
include /home/tarsproto/XGame/PushServer/PushServer.mk
include /home/tarsproto/XGame/MatchServer/MatchServer.mk
include /home/tarsproto/XGame/ActivityServer/ActivityServer.mk
include /home/tarsproto/XGame/GameRecordServer/GameRecordServer.mk
include /home/tarsproto/XGame/RedDotServer/RedDotServer.mk
include /home/tarsproto/XGame/PushServer/PushServer.mk
include /home/tarsproto/XGame/AIServer/AIServer.mk
include /home/tarsproto/XGame/RouterServer/RouterServer.mk
include /usr/local/tars/cpp/makefile/makefile.tars

#-----------------------------------------------------------------------

xgame:
	cp -f $(TARGET) /usr/local/app/tars/tarsnode/data/XGame.RouterServer/bin/
