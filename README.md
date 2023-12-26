# Vital-Signals-Monitor

Vital-Signals-Monitor is a Python desktop application designed to monitor vital signs of a patient, including heartbeat, body temperature, and the flow rate from a medical IV bag to the patient's body. The application integrates Arduino for sensor interfacing and PyQt5 for the graphical user interface.

![image](https://github.com/MoHazem02/Vital-Signals-Monitor/assets/66066832/2ec6f997-07dc-413a-828b-40e30e3ee9eb)


## Features

1. **Heartbeat Monitoring:** Utilizes a heartbeat sensor to continuously monitor and display the patient's heart rate in real-time.

2. **Temperature Monitoring:** Measures the patient's body temperature using an NTC thermistor and provides a visual representation of the temperature trends.

3. **IV Bag Flow Rate Monitoring:** Monitors the flow rate from a medical IV bag to the patient, ensuring accurate and timely administration of fluids.

## Hardware Requirements

- Arduino board
- Heartbeat sensor
- NTC thermistor
- Water flow rate sensor
- Medical IV bag with tubing
- Required connecting wires

## Software Requirements

- Python 3.x
- PyQt5 library
- pySerial library for Arduino communication

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/MoHazem02/Vital-Signals-Monitor.git
   cd Vital-Signals-Monitor
   ```

2. Install the required Python packages:

   ```bash
   pip install PYQT5
   ```

3. Upload the Arduino sketch (`arduino_monitoring.ino`) to your Arduino board using the Arduino IDE.

4. Connect the sensors (heartbeat sensor, NTC thermistor, and water flow rate sensor) to the corresponding pins on the Arduino board.

5. Run the Python application:

   ```bash
   python Vital_Signals_Monitor.py
   ```

## Usage

1. Launch the application after connecting the Arduino board with the sensors.

2. The main dashboard will display real-time information on heartbeat, temperature, and IV bag flow rate.

3. The application allows you to set thresholds for vital signs, generating alerts if any value exceeds the defined limits.

4. Use the graphical user interface to navigate through different monitoring features.

## Contributing

Contributions are welcome! If you have ideas for improvements, open an issue or create a pull request.


## Acknowledgments

- Thanks to the open-source community for providing valuable resources and libraries.
- Inspiration for the project came from the need for efficient and reliable vital sign monitoring in healthcare settings.
