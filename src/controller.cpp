#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
using namespace std;
class controller
{
public:
  controller(){
 	sub = n.subscribe("chatter", 1000, &controller::callback, this);
	pub = n.advertise<std_msgs::String>("my_topic", 1000);
}
  void callback(const std_msgs::String::ConstPtr& msg)
{
	std_msgs::String pub_str;
	
	stringstream ss;
	ss<<"controller heard:"<<msg->data.c_str();
	pub_str.data = ss.str();
	pub.publish(pub_str);
	ros::spinOnce();
}
private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};
int main(int argc, char **argv)
{
ros::init(argc,argv, "controller");
controller control;
ros::spin();
return 0;
}
