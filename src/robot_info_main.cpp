#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <string>

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot_manager_using_composition");
  ros::NodeHandle nh;
  std::string robot_description = "robot_description: Mir100";
  std::string serial_number = "serial_number: 567A359";
  std::string ip_address = "ip_address: 169.254.5.180";
  std::string firmware_version = "firmware_version: 3.5.8";

  RobotInfo rbt_info_publisher(&nh, robot_description, serial_number,
                               ip_address, firmware_version);
  rbt_info_publisher.publish_data();
  ros::spin();

  return 0;
}
