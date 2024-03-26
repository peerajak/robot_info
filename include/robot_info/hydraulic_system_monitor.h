
#include <memory>
#include <string>

class HydraulicSystemMonitor {
public:
  HydraulicSystemMonitor();
  ~HydraulicSystemMonitor() = default;
  HydraulicSystemMonitor(std::string hydraulic_oil_temperature,
                         std::string hydraulic_oil_tank_fill_level,
                         std::string hydraulic_oil_pressure);
  std::string get_hydraulic_oil_temperature();
  std::string get_hydraulic_oil_tank_fill_level();
  std::string get_hydraulic_oil_pressure();

  void set_hydraulic_oil_temperature(std::string hot);
  void set_hydraulic_oil_tank_fill_level(std::string hotfl);
  void set_hydraulic_oil_pressure(std::string hop);
  void set_hydraulic_oil_all(std::string hot, std::string hotfl,
                             std::string hop);

private:
  std::string _hydraulic_oil_temperature;
  std::string _hydraulic_oil_tank_fill_level;
  std::string _hydraulic_oil_pressure;
};