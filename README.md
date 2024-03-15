# mqtt_mosquitto_ex
Basic Example for MQTT using mosquoitto broker

## Setup

- step 01 -> Dowload and install [Mosquitto](https://mosquitto.org/download/) based on your OS.

- step 02 -> Check if the Mosquitto Brocker present in your services & check the status.

- step 03 -> Open up your cmd in Administrator and type `net start mosquitto` command to run the brocker and check service's status change into `Running`.

- step 04 -> In order to check `stat` about brocker run the `netstat -a` command.

*Defult the brocker use: `127.0.0.1:1883`.*

## Example Test

*MQTT use Publisher/Subscribe*

- open up new cmd and run a command: `mosquitto_pub -t test_sensor_data -h localhost` : Client Subscribe to the data.
  
- Open up new cmd and run a command: `mosquitto_pub -t test_sensor_data -h localhost -m "sasanka"` : Client publish data.

Brocker `test_sensor_data` use as topic and send the -m `message` to relevant client.

1st terminal show the message as `sasanka` every time execute the second command in second terminal. *MQTT successfully connected*.
