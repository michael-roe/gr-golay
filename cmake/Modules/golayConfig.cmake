INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_GOLAY golay)

FIND_PATH(
    GOLAY_INCLUDE_DIRS
    NAMES golay/api.h
    HINTS $ENV{GOLAY_DIR}/include
        ${PC_GOLAY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GOLAY_LIBRARIES
    NAMES gnuradio-golay
    HINTS $ENV{GOLAY_DIR}/lib
        ${PC_GOLAY_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/golayTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GOLAY DEFAULT_MSG GOLAY_LIBRARIES GOLAY_INCLUDE_DIRS)
MARK_AS_ADVANCED(GOLAY_LIBRARIES GOLAY_INCLUDE_DIRS)
