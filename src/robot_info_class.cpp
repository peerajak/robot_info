#include "robot_info/robot_info_class.h"
#include "robot_info/RobotInfo_msg.h"
#include "ros/ros.h"
#include <string>

RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::string robot_description,
                     std::string serial_number, std::string ip_address,
                     std::string firmware_version)
    : _robot_description(robot_description), _serial_number(serial_number),
      _ip_address(ip_address), _firmware_version(firmware_version) {
  this->nh = node_handle;
  init_publisher();
}
void RobotInfo::publish_data() {
  rbt_info_msg.data_field_01 = _robot_description;
  rbt_info_msg.data_field_02 = _serial_number;
  rbt_info_msg.data_field_03 = _ip_address;
  rbt_info_msg.data_field_04 = _firmware_version;
  ros::Rate loop_rate(1);
  while (ros::ok()) {
    pub.publish(rbt_info_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
void RobotInfo::init_publisher() {
  this->pub = nh->advertise<robot_info::RobotInfo_msg>("robot_info", 1000);
}