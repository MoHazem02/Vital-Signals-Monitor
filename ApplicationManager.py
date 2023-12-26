import serial
from PyQt5 import QtCore


class ApplicationManager:
    def __init__(self, ui):
        self.UI = ui
        self.serial = serial.Serial('COM8', 9600)
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_data)
        self.timer.start(500)  # Update every 0.5 second

    def update_data(self):
        if self.serial.in_waiting > 0:
            arduino_data = self.serial.readline().decode('ascii').rstrip()
            x, y, z = arduino_data.split(',')
            self.UI.Heart_Rate_LCD.display(float(x))
            self.UI.Temperature_LCD.display(float(y))
            self.UI.Solution_Volume_LCD.display(float(z))

