cmake_minimum_required(VERSION 2.8.12)
project(EvaluationMetrixx)


set(HEADER_FILES
   initMyPlugin.h
   InjectorPositioningMetrics.h
   ui_dialog.h
ui_mydialog.h
   ObjectHandlingMetrics.h
   SphereHandlingMetrics.h
   ICSISimulationMetrics.h
   dialog.h
scoredialog.h
ui_scoredialog.h
InjectorHandlingMetrics.h
   SuspendedCellsMetrics.h
  AdherentCellsMetrics.h
CapillaryMicroCellInjectionMetrics.h
mydialog.h
)

set(SOURCE_FILES
    initMyPlugin.cpp
    InjectorPositioningMetrics.cpp
   mydialog.cpp
    ObjectHandlingMetrics.cpp   
    SphereHandlingMetrics.cpp
moc_mydialog.cpp
    ICSISimulationMetrics.cpp
   dialog.cpp
scoredialog.cpp
moc_scoredialog.cpp
   moc_dialog.cpp
   SuspendedCellsMetrics.cpp
  AdherentCellsMetrics.cpp
CapillaryMicroCellInjectionMetrics.cpp

InjectorHandlingMetrics.cpp
  )
set(UI_FILES
dialog.ui
mydialog.ui
scoredialog.ui
)



find_package(Qt5 COMPONENTS Core REQUIRED)

if(Qt5Core_FOUND)
    message("Simedix: Using Qt5")
    set(QT5_NO_LINK_QTMAIN 1)

    find_package(Qt5 COMPONENTS Gui OpenGL Network Core Multimedia REQUIRED)

    set(EXT_QT_INCLUDES ${Qt5Core_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5Multimedia_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS})
    #target_include_directories(${EXT_QT_INCLUDES})

    set(EXT_QT_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Multimedia_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5OpenGL_LIBRARIES})

    qt5_wrap_cpp(MOC_FILES ${MOC_HEADER_FILES})
    set(MOC_FILES_GROUP "Generated")
    qt5_wrap_ui(FORM_FILES ${UI_FILES})
    set(FORM_FILES_GROUP "Generated")
endif()



find_package(SofaFramework REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${UI_FILES})
target_link_libraries(${PROJECT_NAME} SofaCore SofaMisc SofaMiscCollision SofaBaseVisual SofaExporter SofaLoader SofaOpenglVisual SofaMiscEngine SofaMiscFem SofaMiscForceField SofaMiscMapping SofaMiscSolver SofaMiscTopology SofaGuiCommon)
target_link_libraries(${PROJECT_NAME} ${EXT_QT_LIBRARIES})
  

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DSOFA_BUILD_EVALUATIONMETRIXX")
install(TARGETS EvaluationMetrixx
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES ${HEADER_FILES} DESTINATION "include/sofa/gui")
