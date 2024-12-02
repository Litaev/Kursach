set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)

project(test10 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 29)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Core)


qt_add_executable(apptest10
    main.cpp
    carListElementModel.cpp carListElementModel.h
    eventListElementModel.cpp eventListElementModel.h

)

qt_add_qml_module(apptest10
    URI test10
    VERSION 1.0
    QML_FILES Main.qml ServiceWindow.qml ChooseCarWindow.qml CarWindow.qml
    SOURCES eventsWindow.h eventsWindow.cpp
        RESOURCES addNewEvent.png passatB5.jpeg 123.png

        SOURCES user.h user.cpp
        SOURCES car.h car.cpp
        SOURCES event.h event.cpp
        SOURCES date.h date.cpp
        SOURCES enums.h
        SOURCES refueling.h refueling.cpp
        SOURCES service.h service.cpp
        SOURCES chooseCarWindow.h chooseCarWindow.cpp
        SOURCES carListElement.h
        SOURCES main.cpp
        RESOURCES icons/back_black_icon.png icons/back_white_icon.png icons/car_black_icon.png icons/car_white_icon.png icons/comment_black_icon.png icons/comment_white_icon.png icons/confirm_black_icon.png icons/confirm_white_icon.png icons/date_black_icon.png icons/date_white_icon.png icons/eventType_black_icon.png icons/eventType_white_icon.png icons/fuel_black_icon.png icons/fuel_white_icon.png icons/fuelPistol_black_icon.png icons/fuelPistol_white_icon.png icons/fuelTank_black_icon.png icons/fuelTank_white_icon.png icons/mileage_black_icon.png icons/mileage_white_icon.png icons/price_black_icon.png icons/price_white_icon.png icons/text_black_icon.png icons/text_white_icon.png icons/year_black_icon.png icons/year_white_icon.png
        SOURCES enhancedqmlapplicationengine.h enhancedqmlapplicationengine.cpp
        QML_FILES CarCard.qml
        SOURCES eventlistelement.h
        RESOURCES icons/service_black_icon.png icons/service_white_icon.png
        RESOURCES icons/add_black_icon.png icons/add_white_icon.png
        QML_FILES EventsList.qml
        RESOURCES icons/add_refueling_white_icon.png icons/add_service_white_icon.png
        QML_FILES RefuelingWindow.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptest10 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptest10
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptest10
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS apptest10
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
