cmake_minimum_required( VERSION 3.5 )
project( pcl_showCloud )

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLags "-std=11")


find_package( VTK REQUIRED)
include_directories(${VIK_INCLUDE_DIRS})

find_package( Boost REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS})


find_package( PCL 1.8 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

add_executable(showPointCloud showPointCloud.cpp)
target_link_libraries(showPointCloud 
                     ${PCL_LIBRARIES}
                     ${VTK_LIBRARIES}
                     ${Boost_LIBRARIES})