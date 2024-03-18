//
// Created by Admin on 3/18/2024.
//
#include <iostream>
#include <mosquitto.h>

void on_connect(struct mosquitto *mosq, void *obj, int rc) {
    if (rc) {
        std::cout << "Error with result code: " << rc << std::endl;
    } else {
        printf("Connected\n");
        mosquitto_subscribe(mosq, NULL, "test", 0);
    }
}

void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
    if (message->payloadlen) {
        std::cout << message->topic << ": " << (char *) message->payload << std::endl;
    } else {
        std::cout << message->topic << ": (null)" << std::endl;
    }
}


