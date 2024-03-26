#include "robot_info/hydraulic_system_monitor.h"
#include <memory>
#include <string>

HydraulicSystemMonitor::HydraulicSystemMonitor()
    : _hydraulic_oil_temperature(""), _hydraulic_oil_tank_fill_level(""),
      _hydraulic_oil_pressure("") {}

HydraulicSystemMonitor::HydraulicSystemMonitor(
    std::string hydraulic_oil_temperature,
    std::string hydraulic_oil_tank_fill_level,
    std::string hydraulic_oil_pressure) {
  _hydraulic_oil_temperature = hydraulic_oil_temperature;
  _hydraulic_oil_tank_fill_level = hydraulic_oil_tank_fill_level;
  _hydraulic_oil_pressure = hydraulic_oil_pressure;
}

std::string HydraulicSystemMonitor::get_hydraulic_oil_temperature() {
  return _hydraulic_oil_temperature;
}
std::string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() {
  return _hydraulic_oil_tank_fill_level;
}
std::string HydraulicSystemMonitor::get_hydraulic_oil_pressure() {
  return _hydraulic_oil_pressure;
}

void HydraulicSystemMonitor::set_hydraulic_oil_temperature(std::string hot) {
  _hydraulic_oil_temperature = hot;
}
void HydraulicSystemMonitor::set_hydraulic_oil_tank_fill_level(
    std::string hotfl) {
  _hydraulic_oil_tank_fill_level = hotfl;
}
void HydraulicSystemMonitor::set_hydraulic_oil_pressure(std::string hop) {
  _hydraulic_oil_pressure = hop;
}

void HydraulicSystemMonitor::set_hydraulic_oil_all(std::string hot,
                                                   std::string hotfl,
                                                   std::string hop) {
  _hydraulic_oil_temperature = hot;
  _hydraulic_oil_tank_fill_level = hotfl;
  _hydraulic_oil_pressure = hop;
}