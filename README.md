# Musical-Keyboard
Taking Input: Like a usual piano, our model has different keys assigned to different notes and frequencies, so the input signal is taken through keys. We have seven push buttons to represent the seven notes of the piano.

Processing the input through Arduino: After taking the digital input, it is processed using the code in the Arduino and then, according to the input, a signal is sent out through the digital input.

Attenuating the signal: The signal given by the Arduino is then passed through the resistors, which reduce the voltage across the output buzzer, thus reducing the volume.

Changing Octave: For changing the octave, we have an Ultrasonic Sensor that measures the distance of the nearest obstacle and maps that distance to find a multiplication factor that eventually changes the octave.

Final Output: For producing the final output sound using the processed signal, we use piezo buzzers, which can produce sound using piezoelectric materials based on the magnitude of the current.


