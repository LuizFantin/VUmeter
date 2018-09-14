"# VUmeter" 

Author: Luiz Fantin Neto
Version: (1.0.0)

A prototype of a Volume Unit(VU) Meter implemented in the Arduíno Nano.

The prototype works with an analog data input that is captured by a microphone. After processing, the visual output is made by means of a LED board connected to busbars. The LED's are activated according to the amplitude of the microphone input signal.
The project was done using an integrated circuit (IC) called ShiftRegister for the expansion of Arduino digital outputs. The use of the IC consists in sending data to it serially and have the output of these data in parallel. The control of the integrated circuit is done by the LATCH and CLOCK input pins.