#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <sstream>
using namespace std;
int main(int argc, char **argv)
{
ros::init(argc, argv, "talker");
ros::NodeHandle n;
ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("chatter", 1000);
ros::Rate loop_rate(10);
int count = 0;
while(ros::ok())
{
std_msgs::Float32 msg;

msg.data = 32.4;
cout<<msg.data<<endl;
chatter_pub.publish(msg);
ros::spinOnce;
loop_rate.sleep();
++count;

}
return 0;
}
