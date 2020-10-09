#include "ros/ros.h"
#include "std_msgs/Float32.h"
using namespace std;
void chattercallback(const std_msgs::Float32::ConstPtr& msg)
{
cout<<"i heard:"<<msg->data<<endl;
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "listener");
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("chatter", 1000, chattercallback);
ros::spin();
return 0;
}
