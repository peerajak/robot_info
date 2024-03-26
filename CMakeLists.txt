cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
  message_generation
)

add_message_files(
      FILES
      RobotInfo_msg.msg
    )

generate_messages(
      DEPENDENCIES
      std_msgs
) # Dont Forget to uncoment here TOO

catkin_package(
 CATKIN_DEPENDS roscpp std_msgs message_runtime   
)


include_directories(
   include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_info_node src/robot_info_main.cpp src/robot_info_class.cpp src/agv_robot_info_class.cpp)
add_dependencies(robot_info_node ${robot_info_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_info_node
   ${catkin_LIBRARIES}   
 )
add_dependencies(robot_info_node robot_info_generate_messages_cpp)


add_executable(agv_robot_info_node src/agv_robot_info_main.cpp src/robot_info_class.cpp src/agv_robot_info_class.cpp)
add_dependencies(agv_robot_info_node ${agv_robot_info_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(agv_robot_info_node
   ${catkin_LIBRARIES}   
 )
add_dependencies(agv_robot_info_node robot_info_generate_messages_cpp)