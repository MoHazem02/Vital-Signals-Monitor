import serial, time
from PyQt5 import QtCore
class ApplicationManager:
    def __init__(self, ui):
        self.UI = ui
        self.serial = serial.Serial('COM7', 9600)
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_data)
        self.timer.start(1000)  # Update every 1 second

    def update_data(self):
        #ToDo Read the data you need from the input and display them on the ui
        if self.serial.in_waiting > 0:
            arduino_data = self.serial.readline().decode('ascii').rstrip()
            print(arduino_data)

