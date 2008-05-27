project( parsek )

set( CMAKE_MODULE_PATH 
     ${PROJECT_SOURCE_DIR}/cmake
     ${CMAKE_SOURCE_DIR}/cmake
     ${CMAKE_MODULE_PATH} )

find_package( KDE4 REQUIRED )
find_package( TPProto )
macro_log_feature(TPProto_FOUND "TPProto" "" "" FALSE "" "Needed for parsek.")

if (TPPROTO_FOUND)
	include( KDE4Defaults )
	include_directories( ${KDE4_INCLUDES} ${TPPROTO_INCLUDE_DIR} )

	add_definitions( ${KDE4_DEFINITIONS} )

	add_subdirectory( src )
endif (TPPROTO_FOUND)
