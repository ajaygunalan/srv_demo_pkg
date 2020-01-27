
#include "ros/ros.h"
#include <iostream>
#include <sstream>

#include "srv_demo_pkg/srvdemo.h"

using namespace std;

bool demo_service_callback(srv_demo_pkg::srvdemo::Request &req, 
	srv_demo_pkg::srvdemo::Response &res)
{
	//std::stringstream ss;
	//ss << "Received Here";
	//res.out = ss.str();
	//ROS_INFO("From Client [%s], Server says [%s]",req.in.c_str(),res.out.c_str());
	//return true;
  std::stringstream ss;
  ss << "Received ";
  res.out = ss.str();
  string start="start";
  string stop="stop";

  ROS_INFO("From Client  [%s], Server says [%s]",req.in.c_str(),res.out.c_str());
  
  if(strcmp(req.in.c_str(), start.c_str()) == 0)
  {

    ROS_INFO("starting the cam \n");
  }
  else if(strcmp(req.in.c_str(), stop.c_str()) == 0)
  {

  	ROS_INFO("closing the cam \n");
  }
  else 
  {
    ROS_INFO("exception occured \n");
  }
  return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "demo_service_server");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("demo_service", demo_service_callback);
	ROS_INFO("Ready to receive from client.");
	ros::spin();
	return 0;
}
