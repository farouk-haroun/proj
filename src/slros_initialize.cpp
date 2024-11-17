#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "proj";

// For Block proj/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Sub_proj_16;

// For Block proj/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Pub_proj_17;

// For Block proj/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Pub_proj_25;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

