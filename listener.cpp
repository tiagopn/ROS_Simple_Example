#include <iostream>
#include <vector>

#include "ros/ros.h"
#include "std_msgs/String.h"

// Funcao que sera chamada toda vez que uma nova mensagem chegar no topico chatter.
void chatterCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){

    ros::init(argc, argv, "listner");
    ros::NodeHandle n;

    // Subscreve do topico chatter com o master.
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    // inicia um loop de chamada de msg o mais rapido possivel.
    ros::spin();

    return 0;
}
