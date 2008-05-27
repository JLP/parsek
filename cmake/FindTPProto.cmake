# - Try to find TPProto library
# Once done this will define:
#
#  TPPROTO_FOUND - system has TPProto library
#  TPPROTO_INCLUDE_DIR - TPPtoto include directory
#  TPPROTO_LIBRARY - link this to use TPProto library

FIND_PATH(TPPROTO_INCLUDE_DIR gamelayer.h /usr/include/tpproto /usr/local/include/tpproto)

FIND_LIBRARY(TPPROTO_LIBRARY NAMES tpproto ) 


include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TPPROTO DEFAULT_MSG TPPROTO_LIBRARY TPPROTO_INCLUDE_DIR )

IF (TPPROTO_FOUND)
   SET(TPPROTO_LIBRARIES ${TPPROTO_LIBRARY})
ENDIF (TPPROTO_FOUND)
