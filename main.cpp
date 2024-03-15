#include <iostream>
#include "include/mosquitto.h"

int main() {
    int rc;
    struct mosquitto *mosq;

    mosquitto_lib_init();

    mosq = mosquitto_new("publisher-test", true, NULL);

    if (mosq) {
        rc = mosquitto_connect(mosq, "localhost", 1883, 60);
        if (rc == MOSQ_ERR_SUCCESS) {
            mosquitto_publish(mosq, NULL, "test", 4, "Hello", 0, false);
            mosquitto_disconnect(mosq);
        } else {
            std::cout << "Error: " << rc << std::endl;
        }
        mosquitto_destroy(mosq);
    }

    mosquitto_lib_cleanup();

    return 0;
}
