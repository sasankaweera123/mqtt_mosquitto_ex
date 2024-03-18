#include <iostream>
//#include "include/mosquitto.h" // This is the include from static library
#include <mosquitto.h> // This is the correct include from dynamic library

int main() {
    int rc;
    struct mosquitto *mosq;

    std::cout << "Initializing mosquitto library" << std::endl;

    mosquitto_lib_init();

    mosq = mosquitto_new("publisher-test", true, NULL);

    if (mosq) {
        rc = mosquitto_connect(mosq, "localhost", 1883, 60);
        if (rc != 0) {
            std::cout << "Error: " << rc << std::endl;
            mosquitto_destroy(mosq);
            return -1;
        }
        std::cout << "Connected" << std::endl;
        mosquitto_publish(mosq, NULL, "test/t1", 6, "test", 0, false);
        std::cout << "Published" << std::endl;
        mosquitto_disconnect(mosq);
        mosquitto_destroy(mosq);
    }

    std::cout << "Cleaning up" << std::endl;

    mosquitto_lib_cleanup();

    return 0;
}
