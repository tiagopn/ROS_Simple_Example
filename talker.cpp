/*

 no' = "talker"
 topico = chatter

*/

#include <iostream>
#include <vector>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){

    // Inicializa o ROS. Aqui a gente especifica o nome do no' a ser inicializado.
    ros::init(argc, argv, "talker");
    
    // Cria um handle pra processar o no.
    ros::NodeHandle n;

    // Diz ao mestre que iremos publicar (atraves da funcao advertise()) uma mensagem do 
    //      tipo std_msgs/String no topico chatter.
    // O mestre, por sua vez, avisa a qualquer no que esteja "ouvindo" o chatter que iremos
    //      publicar algo neste topico. Aqui, 1000 e' o tamanho do buffer.
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // Aqui, a frequencia de publicacao e' setada em 10hz.
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()){

        // Aqui vem os dados que quero publicar

        std_msgs::String msg;

        std::stringstream ss;
        ss << "Mensagem a ser publicada" << count;
        msg.data = ss.str();

        // imprime a mensagem no terminal
        ROS_INFO("I published %s\n",msg.data.c_str());

        // Publica efetivamente a msg atraves da funcao publish()
        chatter_pub.publish(msg);

        // Caso receba callbacks (i.e. ter um subscriber), precisamos dessa funcao pra chamar as
        //         subscriptions.
        ros::spinOnce();

        // Necess'ario para atingir os desejados 10 Hz
        loop_rate.sleep();
        ++count;
    }

    return 0;
}