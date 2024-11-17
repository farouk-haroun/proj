#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "proj_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block proj/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Sub_proj_16;

// For Block proj/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Pub_proj_17;

// For Block proj/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_proj_std_msgs_Float64> Pub_proj_25;

void slros_node_init(int argc, char** argv);

#endif
