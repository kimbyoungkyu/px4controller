#include "px4_controller.hpp"
#include <cmath>
#include <chrono>

using namespace std::chrono_literals;

inline rclcpp::QoS ReliableControlQoS()
{
  return rclcpp::QoS(rclcpp::KeepLast(50)).reliable().durability_volatile();
}

inline rclcpp::QoS BestEffortTelemetryQoS()
{
  return rclcpp::QoS(rclcpp::KeepLast(100)).best_effort().durability_volatile();
}

PX4Controller::PX4Controller(const std::string & node_name,const rclcpp::NodeOptions & options):PX4Proxy(node_name,options)
{
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
  RCLCPP_INFO(get_logger(), "PX4Controller initialized");
}


void PX4Controller::onPX4Updated(uint32_t flags){
RCLCPP_INFO(get_logger(), "onPX4Updated");
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PX4Controller>("PX4Controller"));
  rclcpp::shutdown();
  return 0;
}

