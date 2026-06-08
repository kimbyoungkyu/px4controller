#pragma once

#include "px4_proxy.hpp"


class PX4Controller : public PX4Proxy
{
public:
  PX4Controller(const std::string & node_name,const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
};

