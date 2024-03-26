#include "robot_info/RobotInfo_msg.h"
#include "robot_info/hydraulic_system_monitor.h"
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
  AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, double max_payload);

  AGVRobotInfo(ros::NodeHandle *nh, std::string robot_description,
               std::string serial_number, std::string ip_address,
               std::string firmware_version, double max_payload,
               std::string oil_temperature, std::string oil_fill_level,
               std::string oil_pressure);
  virtual ~AGVRobotInfo() override = default;
  virtual void publish_data() override;

private:
  double _maximum_payload;
  HydraulicSystemMonitor _hydraulic_system_monitor;
};
