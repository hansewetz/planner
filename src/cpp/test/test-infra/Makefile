# To be built
LOCAL_TARGET    =  test1
LOCAL_SOTARGET  =
LOCAL_OBJS      = test1.o 

# Control.
LOCAL_LIBS      = -ltask -lutils \
	          -ltask-persist-sqlite3  \
                  -lsqlite3utils -lsqlite-modern \
	          -lboost_filesystem -lboost_system -lboost_log \
	          -lpthread -ldl

LOCAL_LIBPATH   = -L${PROJECT_ROOT}/artefacts/lib
LOCAL_INCPATH   = 
LOCAL_DEFINES   = 
LOCAL_CXXFLAGS  = 
LOCAL_CPPFLAGS  = -g
LOCAL_LDFLAGS   =
LOCAL_LDSOFLAGS =

include $(ENV_ROOT)/makerules/build.rules
