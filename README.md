# Daltonic Assistant
A pal to to make life of people with daltonism (green/red), easier.

# Configuration:
The machine is using a:
* microcontroller (arduino uno)
* a color sensor  for the data input
* an LCD screen for communication with the outer world
* 2 buttons

# Aim:
The machine aims to be able to understand the red and green colours given to it.
It communicates their values via english strings (red/green) on its integrated LCD screen.
What is _cool_ about the project though, is that the machine initialises knowing nothing.
Nevertheless it keeps inside a Perceptron, so (someone that is not daltonic in green/red) can train it.
The progress of the training can be also tracked using the notebook, _monitor_leaarning.ipyb_.
So by now we have already a _learning machine_.
As soon as the machine is trained the colours, then it can be used from daltonic people for green/red colour separation.

Perceptron is just a binary classifier so, actually the learning can happen for any two classes of inputs that can be separated with a linear plane. So e.g. we can just separate two other colors (blue / green).

This demonstrates the power of a single neuron (the biological analog of Perceptron).
Interesting reference for the use of the 100M neurons of a normal human being, and how much they are used on average.


# Relevant Information
The project was developed in a 2 days internal hackathon of my employer Siroop (www.siroop.ch)


 # Perceptron Class
 The file perceptron.h is used from Tomas de Camino Beck (thanks!).
 In case one is interested for a more simplified version easily understood in python, can have a look in the
 Perceptron Class I prepared in the notebook: _perceptron_demo.ipynb_ .


# Electronics Schematics
You can find the schematics of electronics
* electronics_breadboard , for a view of how the cabling looks like
* electronics_ciruit , for a view how the electronics look like
The files were generated with the fritzing application.
The relevant fzz file is the
* electronics_sketch.fzz

# Images
In case the old saying is true, that 1ximage = 10^3 words, please find some images of the project under the dir (guess what) _images_.
Why not?...

