//
// Created by Admin on 3/18/2024.
//

#ifndef MQTT_MOS_EX_MQTT_SUB_PUB_H
#define MQTT_MOS_EX_MQTT_SUB_PUB_H


class mqtt_sub_pub {
public:
    static void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);
    static void on_connect(struct mosquitto *mosq, void *obj, int rc);
    static void on_publish(struct mosquitto *mosq, void *obj, int mid);
};


#endif //MQTT_MOS_EX_MQTT_SUB_PUB_H
