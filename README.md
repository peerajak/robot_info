# The COnstruct's Checkpoint3
# Study Inheritance C++ with ROS

##This code creates 2 ROS nodes.
## First Node:
named: robot_info_node, which is publishing Robot details through a topic name: /robot_info.
To run this node, 
1. On first terminal
roscore
2. On 2nd terminal
rosrun robot_info robot_info_node
To see the result of node publishing
rostopic echo robot_info

## 2nd Node:
named: agv_robot_info_node, which is publishing Robot details through a topic name: /robot_info.
To run this node, 
1. On first terminal
roscore
2. On 2nd terminal
rosrun robot_info agv_robot_info_node
To see the result of node publishing
rostopic echo robot_info

