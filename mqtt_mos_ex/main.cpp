#include <iostream>
//#include "include/mosquitto.h" // This is the include from static library
#include <mosquitto.h> // This is the correct include from dynamic library]
#include "mqtt_sub_pub.h"

int main() {
    int rc,choice;
    int id = 12;
    struct mosquitto *mosq;

    std::cout << "--------------- What do you want to do ? ---------------" << std::endl;
    std::cout << "1. Publish" << std::endl;
    std::cout << "2. Subscribe" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "Initializing mosquitto library" << std::endl;

    mosquitto_lib_init();

    mosq = mosquitto_new(choice == 1 ? "publisher-test" : "subscriber-test", true, choice == 1 ? NULL : &id);


    if (mosq) {
        if (choice == 2) {
            mosquitto_connect_callback_set(mosq, mqtt_sub_pub::on_connect);
            mosquitto_message_callback_set(mosq, mqtt_sub_pub::on_message);
        }

        rc = mosquitto_connect(mosq, "localhost", 1883, 60);
        if (rc != 0) {
            std::cout << "Error: " << rc << std::endl;
            return -1;
        }
        std::cout << "Connected" << std::endl;
        if (choice == 1) {
            mosquitto_publish(mosq, NULL, "test/t1", 6, "test", 0, false);
            std::cout << "Published" << std::endl;
        }
        if (choice == 2) {
            mosquitto_loop_start(mosq);
            int exit;
            std::cout << "Press 0 to exit" << std::endl;
            std::cin>>exit;
            if(exit == 0)
            mosquitto_loop_stop(mosq, true);
        }
        std::cout << "Cleaning up" << std::endl;
        mosquitto_disconnect(mosq);
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();

    }
    return 0;
}
