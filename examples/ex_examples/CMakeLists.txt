find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

find_package(Eigen3)
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

add_executable(main "main.cpp")
target_link_libraries( main ${Sophus_LIBRARIES} )
