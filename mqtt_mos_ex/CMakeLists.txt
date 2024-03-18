cmake_minimum_required(VERSION 3.27)
project(mqtt_mos_ex)

set(CMAKE_CXX_STANDARD 17)

# Specify the path to the directory containing the Mosquitto dynamic library
set(MOSQUITTO_DIR "C:/Program Files/mosquitto")

# Add the directory containing the Mosquitto dynamic library to the include path
include_directories(${MOSQUITTO_DIR}/devel)

add_executable(mqtt_mos_ex main.cpp
        mqtt_sub.cpp
)

# Link the Mosquitto dynamic library to the executable
if(WIN32)
    # In Windows, the Mosquitto dynamic library is called mosquitto.dll
    target_link_libraries(mqtt_mos_ex ${MOSQUITTO_DIR}/mosquitto.dll)
endif()


