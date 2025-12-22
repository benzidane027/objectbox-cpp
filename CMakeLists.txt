cmake_minimum_required(VERSION 3.15)

project(demo LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(${PROJECT_NAME}
    src/main.cpp
    generated
    src/database/database.cpp
    src/widget/ui.cpp
    src/repository/repository.cpp
    )

target_precompile_headers(${PROJECT_NAME}
    PRIVATE
        utils/headers.h
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/generated/include
)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(OBX_GEN_DIR ${CMAKE_SOURCE_DIR}/generated)


target_compile_definitions(${PROJECT_NAME}
    PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
)

if(NOT TARGET objectbox) # Using "if" in case a (potential) parent project already defined "objectbox"
    include(FetchContent)
    FetchContent_Declare(
        objectbox
        GIT_REPOSITORY https://github.com/objectbox/objectbox-c.git
        GIT_TAG v5.0.0 # For latest versions, check https://github.com/objectbox/objectbox-c/releases
    )
    FetchContent_MakeAvailable(objectbox)

    if((WIN32 OR CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
        AND CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "^(arm|aarch64|ARM|AARCH64)")
        message(STATUS "Skipping ObjectBox Generator integration, which is not yet supported on this platform (${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR})")
    else()
        find_package(ObjectBoxGenerator REQUIRED)
        add_obx_schema(
            TARGET ${PROJECT_NAME}
            SCHEMA_FILES data/task.fbs
            INSOURCE
            OUTPUT_DIR ${OBX_GEN_DIR}
            OUTPUT_DIR_HEADERS ${OBX_GEN_DIR}/include
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} objectbox)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
