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

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
                           std::string serial_number, std::string ip_address,
                           std::string firmware_version, double max_payload,
                           std::string oil_temperature,
                           std::string oil_fill_level, std::string oil_pressure)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version),
      _maximum_payload(max_payload) {
  _hydraulic_system_monitor.set_hydraulic_oil_all(oil_temperature,
                                                  oil_fill_level, oil_pressure);
}

void AGVRobotInfo::publish_data() {
  std::string max_payload_string(std::to_string(this->_maximum_payload));
  std::string max_payload_header_string("maximum_payload: ");
  rbt_info_msg.data_field_05 = max_payload_header_string + max_payload_string;
  rbt_info_msg.data_field_06 =
      _hydraulic_system_monitor.get_hydraulic_oil_temperature();
  rbt_info_msg.data_field_07 =
      _hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level();
  rbt_info_msg.data_field_08 =
      _hydraulic_system_monitor.get_hydraulic_oil_pressure();
  RobotInfo::publish_data();
}
