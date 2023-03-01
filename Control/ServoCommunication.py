import serial
import time
if __name__ == '__main__':

    # '/dev/ttyACM0' refers to the Serial device name for the Arduino
    # 9600 is the baud rate for the arduino
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) 
    ser.reset_input_buffer()

    x = 0

    while True:
        ser.write(b"Hello from Raspberry Pi!\n")
        line = ser.readline().decode('utf-8').rstrip()
        print(line)

        while x == 0:
            changeX = input("Insert a X value:")
            changeY = input("Insert a Y value:")

            ser.write(changeX + "\n")
            ser.write(changeY + "\n")

        time.sleep(1)
