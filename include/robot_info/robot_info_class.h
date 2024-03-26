
#include "robot_info/RobotInfo_msg.h"
#include "ros/ros.h"
#include <string>

class RobotInfo {

public:
  RobotInfo() = default;
  RobotInfo(ros::NodeHandle *node_handle, std::string robot_description,
            std::string serial_number, std::string ip_address,
            std::string firmware_version);
  virtual void publish_data();
  virtual ~RobotInfo() = default;

protected:
  ros::NodeHandle *nh;
  ros::Publisher pub;
  void init_publisher();
  bool output_enabled = false;
  robot_info::RobotInfo_msg rbt_info_msg;

private:
  std::string _robot_description;
  std::string _serial_number;
  std::string _ip_address;
  std::string _firmware_version;
};

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo() = default;
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, double max_payload);
  virtual ~AGVRobotInfo() override = default;
  virtual void publish_data() override;

private:
  double _maximum_payload;
};
