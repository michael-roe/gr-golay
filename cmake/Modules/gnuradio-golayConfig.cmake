find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_GOLAY gnuradio-golay)

FIND_PATH(
    GR_GOLAY_INCLUDE_DIRS
    NAMES gnuradio/golay/api.h
    HINTS $ENV{GOLAY_DIR}/include
        ${PC_GOLAY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_GOLAY_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-golayTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_GOLAY DEFAULT_MSG GR_GOLAY_LIBRARIES GR_GOLAY_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_GOLAY_LIBRARIES GR_GOLAY_INCLUDE_DIRS)
