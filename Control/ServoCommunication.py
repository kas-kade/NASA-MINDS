import serial
import time
if __name__ == '__main__':

    # '/dev/ttyACM0' refers to the Serial device name for the Arduino
    # 9600 is the baud rate for the arduino
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) 
    ser.reset_input_buffer()

    while True:
        ser.write(b"Hello from Raspberry Pi!\n")
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(1)
