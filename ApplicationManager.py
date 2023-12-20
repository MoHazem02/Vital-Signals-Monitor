import serial
from PyQt5 import QtCore
class ApplicationManager:
    def __init__(self, ui):
        self.UI = ui
        self.serial = serial.Serial('COM7', 9600)
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_data)
        self.timer.start(500)  # Update every 0.5 second

    def update_data(self):
        if self.serial.in_waiting > 0:
            arduino_data = self.serial.readline().decode('ascii').rstrip()
            value_to_be_displayed = float(arduino_data[1:-1])
            if arduino_data[0] == 'T':
                self.UI.Temperature_LCD.display(value_to_be_displayed)
            elif arduino_data[0] == 'V':
                self.UI.Solution_Volume_LCD.display(value_to_be_displayed)


