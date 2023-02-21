# Scan 2 VL53L0X on Arduino
 Arduino program that uses two VL53L0X sensors to scan for distances simultaneously

Note that this code uses the Adafruit VL53L0X library for communication with the sensors, which makes it easier to interact with the sensors compared to using the raw I2C communication protocol.

This code sets up two instances of the Adafruit_VL53L0X class, lox1 and lox2, to represent the two sensors. In the setup function, it initializes both sensors by calling the begin method on each instance, passing in the I2C address of each sensor as an argument. In the loop function, it calls the rangingTest method on each sensor to obtain a distance measurement and then prints the results to the serial monitor.
