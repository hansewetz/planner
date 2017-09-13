# setup some paths for where to find stuff
# (used in some makefiles)

# build environment root and project root
export ENV_ROOT=`pwd`
export PROJECT_ROOT=${ENV_ROOT}/..

# option for gcc compiler (see: makerules/build.rules)
# (this is setup so that we can compile against gcc-=version 7)
export STDFLAG="-std=c++14"                                      # must be c++14 or c+17
export GCC_ERROR_IGNORE=""
export GCC_ERROR_IGNORE="-Wno-deprecated -Wno-register"        # we get some warnings (which are turned into errors) with c++17
export GCC_USE_GLIBCXX11_ABI="-D_GLIBCXX_USE_CXX11_ABI=0"      # gcc5+ uses a different ABI - we must specify this to avoid link errors

# pick up paths to gcc+libs
export CPPHOME1=/opt/rh/devtoolset-3/root/usr

# lib+inc path for building
export BUILD_LIB_PATH="-L${CPPHOME1}/lib"
export BUILD_INC_PATH="-I${CPPHOME1}/include"

# amend exe library path
export PATH=${CPPHOME1}/bin:${PROJECT_ROOT}/artefacts/bin:${PATH}
export LD_LIBRARY_PATH=${CPPHOME1}/lib:${CPPHOME1}/lib64:${PROJECT_ROOT}/artefacts/lib:${LD_LIBRARY_PATH}
