option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/assimp)

include_directories(${CMAKE_SOURCE_DIR}/third_party/assimp/include)