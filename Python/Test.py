#------------BubbleSort------------------
def bubblesort(arr):
    if len(arr) == 1:
        return arr
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

array = [64, 34, 25, 12, 22, 11, 90]
print(array)
bubblesort(array)
print(array)

#----------------Turtle----------------

import turtle

turtle.setup(1280,720)                # Fenstergröße
wn = turtle.Screen()                 # wn repräsentiert das Fenster 
wn.title("Tastendruck-Ereignisse")   # Fenster Titel
wn.bgcolor("lightgray")              # Hintergrundfarbe
schildkroete = turtle.Turtle()       # Schildkröte anlegen

# Event-Handler:
def h1():
   schildkroete.forward(50)

def h2():
   schildkroete.left(15)

def h3():
   schildkroete.right(15)

def h4():
    wn.bye()                        

def h5(x, y):
   schildkroete.penup()
   schildkroete.goto(x, y)
   schildkroete.pendown()

# Verknüpfung herstellen zwischen Tastenereignissen und Handlern
wn.onkey(h1, "w")
wn.onkey(h2, "a")
wn.onkey(h3, "d")
wn.onkey(h4, "q")
wn.onclick(h5)  # "onclick" reagiert auf Mausklick


# Mit "listen" fängt die Anwendung an nach Ereignissen zu "horchen".
# Ein richtiger Tastendruck löst den zugehörigen Eventhandler aus.
wn.listen()
wn.mainloop()




# ---------MathLab-----------------
#import matplotlib.pyplot as plt
#import numpy as np

#x = np.linspace(-20, 20, 1000)  # Create a list of evenly-spaced numbers over the range
#func = np.sin(x)/x
#plt.plot(x, func)       # Plot the sine of each x point
#plt.show()