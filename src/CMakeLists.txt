set( parsekSources
     connecttoserverdialog.cpp
     converters.cpp
     importobject.cpp
     loggerwidget.cpp
     mainwindow.cpp
     messagesmodel.cpp
     objectsitem.cpp
     objectsmodel.cpp
     parsek.cpp )

kde4_add_ui_files( parsekSources
                   connecttoserverdialog.ui
                   loggerwidget.ui )

kde4_add_executable( parsek ${parsekSources} )

target_link_libraries( parsek ${KDE4_KDEUI_LIBS} ${TPPROTO_LIBRARY} )

install( TARGETS parsek ${INSTALL_TARGETS_DEFAULT_ARGS} )
install( FILES parsek.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )

add_subdirectory( images )
