#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

#include "srv_demo_pkg/srvdemo.h"
#include <iostream>
#include <sstream>
#include <chrono>


//Defining namespace using in this code
using namespace std;
//using namespace ros;
//using namespace std_msgs;
//using namespace mastering_ros_demo_pkg;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_client");


  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  ros::ServiceClient client = n.serviceClient<srv_demo_pkg::srvdemo>("demo_service");

	while (ros::ok())
	{


	  srv_demo_pkg::srvdemo srv;
	  std::stringstream ss;
	  ss << "start";
	  srv.request.in = ss.str();


	  if (client.call(srv))
	  {

	    ROS_INFO("From Client  [%s], Server says [%s]",srv.request.in.c_str(),srv.response.out.c_str());

	  }

	  else
	  {
	    ROS_ERROR("Failed to call service");
	    return 1;
	  }

	  std::this_thread::sleep_for(std::chrono::milliseconds(15000));

	  ss.str(std::string());
	  ss << "stop";
	  srv.request.in = ss.str();

	  if (client.call(srv))
	  {

	    ROS_INFO("From Client  [%s], Server says [%s]",srv.request.in.c_str(),srv.response.out.c_str());

	  }

	  else
	  {
	    ROS_ERROR("Failed to call service");
	    return 1;
	  }

	  std::this_thread::sleep_for(std::chrono::milliseconds(15000));

	  ros::spinOnce();
	//Setting the loop rate
	  loop_rate.sleep();

	}
  return 0;
}