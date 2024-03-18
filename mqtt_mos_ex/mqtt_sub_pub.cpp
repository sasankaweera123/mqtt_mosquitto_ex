//
// Created by Admin on 3/18/2024.
//

#include "mqtt_sub_pub.h"
#include <iostream>
#include <mosquitto.h>

void mqtt_sub_pub::on_connect(struct mosquitto *mosq, void *obj, int rc) {
    if (rc) {
        std::cout << "Error: " << rc << std::endl;
    } else {
        std::cout << "Connected" << std::endl;
        mosquitto_subscribe(mosq, NULL, "test/t1", 0);
    }
}


void mqtt_sub_pub::on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
    if (message->payloadlen) {
        std::cout << message->topic << ": " << (char *) message->payload << std::endl;
    } else {
        std::cout << message->topic << ": (null)" << std::endl;
    }
}

void mqtt_sub_pub::on_publish(struct mosquitto *mosq, void *obj, int mid) {
    std::cout << "Published" << std::endl;
}

