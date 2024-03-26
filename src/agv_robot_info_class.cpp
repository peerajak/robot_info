#include "robot_info/RobotInfo_msg.h"
#include "robot_info/robot_info_class.h"
#include "ros/ros.h"
#include <string>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
                           std::string serial_number, std::string ip_address,
                           std::string firmware_version, double max_payload)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version),
      _maximum_payload(max_payload) {}

void AGVRobotInfo::publish_data() {
  std::string max_payload_string(std::to_string(this->_maximum_payload));
  std::string max_payload_header_string("maximum_payload: ");
  rbt_info_msg.data_field_05 = max_payload_header_string + max_payload_string;
  RobotInfo::publish_data();
}