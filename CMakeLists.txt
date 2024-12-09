set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.16)

project(test11 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 29)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Core Widgets Charts)


qt_add_executable(apptest11
    Sources/main.cpp
    Sources/carListElementModel.cpp Headers/carListElementModel.h
    Sources/eventListElementModel.cpp Headers/eventListElementModel.h

)

qt_add_qml_module(apptest11
    URI test11
    VERSION 1.0
    QML_FILES Qml/Main.qml Qml/ServiceWindow.qml Qml/ChooseCarWindow.qml Qml/CarWindow.qml
    SOURCES Headers/eventsWindow.h Sources/eventsWindow.cpp

        SOURCES Headers/user.h Sources/user.cpp
        SOURCES Headers/car.h Sources/car.cpp
        SOURCES Headers/event.h Sources/event.cpp
        SOURCES Headers/date.h Sources/date.cpp
        SOURCES Headers/enums.h
        SOURCES Headers/refueling.h Sources/refueling.cpp
        SOURCES Headers/service.h Sources/service.cpp
        SOURCES Headers/chooseCarWindow.h Sources/chooseCarWindow.cpp
        SOURCES Headers/carListElement.h
        SOURCES Sources/main.cpp
        RESOURCES icons/back_black_icon.png icons/back_white_icon.png icons/car_black_icon.png icons/car_white_icon.png icons/comment_black_icon.png icons/comment_white_icon.png icons/confirm_black_icon.png icons/confirm_white_icon.png icons/date_black_icon.png icons/date_white_icon.png icons/eventType_black_icon.png icons/eventType_white_icon.png icons/fuel_black_icon.png icons/fuel_white_icon.png icons/fuelPistol_black_icon.png icons/fuelPistol_white_icon.png icons/fuelTank_black_icon.png icons/fuelTank_white_icon.png icons/mileage_black_icon.png icons/mileage_white_icon.png icons/price_black_icon.png icons/price_white_icon.png icons/text_black_icon.png icons/text_white_icon.png icons/year_black_icon.png icons/year_white_icon.png
        SOURCES Headers/enhancedqmlapplicationengine.h Sources/enhancedqmlapplicationengine.cpp
        QML_FILES Qml/CarCard.qml
        SOURCES Headers/eventlistelement.h
        RESOURCES icons/service_black_icon.png icons/service_white_icon.png
        RESOURCES icons/add_black_icon.png icons/add_white_icon.png
        QML_FILES Qml/EventsList.qml
        RESOURCES icons/add_refueling_white_icon.png icons/add_service_white_icon.png
        QML_FILES Qml/RefuelingWindow.qml
        SOURCES
        QML_FILES Qml/StatisticsWindow.qml
        SOURCES Sources/statistics.cpp
        SOURCES Headers/statistics.h
        RESOURCES icons/stats_black_icon.png icons/stats_white_icon.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptest11 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptest10
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptest11
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Core
    PRIVATE Qt6::Widgets
    PRIVATE Qt6::Charts

)

include(GNUInstallDirs)
install(TARGETS apptest11
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
