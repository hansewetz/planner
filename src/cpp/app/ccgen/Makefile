# To be built
LOCAL_TARGET    = $(PROJECT_ROOT)/artefacts/bin/ccgen
LOCAL_SOTARGET  = 
LOCAL_OBJS      = ccgen.o Operation.o NopOperation.o BasicTuOperation.o

# Control.
LOCAL_LIBS      = -lccgen -lutils \
	                -lboost_log -lboost_program_options \
	                -licuuc -licui18n -licudata -lpthread
LOCAL_LIBPATH   = -L${PROJECT_ROOT}/artefacts/lib
LOCAL_INCPATH   =
LOCAL_DEFINES   = 
LOCAL_CXXFLAGS  =
LOCAL_CPPFLAGS  =
LOCAL_LDFLAGS   =
LOCAL_LDSOFLAGS =
  
include $(ENV_ROOT)/makerules/build.rules
