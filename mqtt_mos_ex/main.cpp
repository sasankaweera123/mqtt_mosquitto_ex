#include <iostream>
//#include "include/mosquitto.h" // This is the include from static library
#include <mosquitto.h> // This is the correct include from dynamic library]
#include "mqtt_sub_pub.h"

int main() {
    int rc;
    int id = 12;
    struct mosquitto *mosq;

    std::cout << "Initializing mosquitto library" << std::endl;

    mosquitto_lib_init();

    mosq = mosquitto_new("publisher-test", true, &id);

    if (mosq) {
        mosquitto_connect_callback_set(mosq, mqtt_sub_pub::on_connect);
        mosquitto_message_callback_set(mosq, mqtt_sub_pub::on_message);
        rc = mosquitto_connect(mosq, "localhost", 1883, 60);
        if (rc != 0) {
            std::cout << "Error: " << rc << std::endl;
            return -1;
        }
        std::cout << "Connected" << std::endl;
        mosquitto_loop_start(mosq);
        std::cout << "Press Enter to exit" << std::endl;
        getchar();
        mosquitto_loop_stop(mosq, true);
//        mosquitto_publish(mosq, NULL, "test/t1", 6, "test", 0, false);
//        std::cout << "Published" << std::endl;
        std::cout << "Cleaning up" << std::endl;
        mosquitto_disconnect(mosq);
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();

    }
    return 0;
}
