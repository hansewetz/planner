# setup some paths for where to find stuff
# (used in some makefiles)

# build environment root and project root
export ENV_ROOT=`pwd`
export PROJECT_ROOT=${ENV_ROOT}/..

# option for gcc compiler (see: makerules/build.rules)
# (this is setup so that we can compile against gcc-=version 7)
export STDFLAG="-std=c++17"                                      # must be c++14 or c+17
export GCC_ERROR_IGNORE=""
export GCC_ERROR_IGNORE="-Wno-deprecated -Wno-register"        # we get some warnings (which are turned into errors) with c++17
export GCC_USE_GLIBCXX11_ABI="-D_GLIBCXX_USE_CXX11_ABI=0"      # gcc5+ uses a different ABI - we must specify this to avoid link errors
  
# pick up gcc+libs
export SHAREDDRIVE=/ec/dgt/shared/exodus
export INSTALL_HOME0=${SHAREDDRIVE}/local/CppEnv-V2.0
export INSTALL_HOME=${SHAREDDRIVE}/local/CppEnv-V1.0

# boost stuff
export BOOST_INC=${INSTALL_HOME}/include
export BOOST_LIB=${INSTALL_HOME}/lib

# amend exe library path
export PATH=${INSTALL_HOME0}/bin:${INSTALL_HOME}/bin:${PATH}:${PROJECT_ROOT}/bin/bin:${PROJECT_ROOT}/artefacts/bin
export LD_LIBRARY_PATH=${INSTALL_HOME0}/lib:${INSTALL_HOME}/lib:${INSTALL_HOME0}/lib64:${INSTALL_HOME}/lib64:${LD_LIBRARY_PATH}:${PROJECT_ROOT}/artefacts/lib
