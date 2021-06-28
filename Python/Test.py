msg1 = "Hello"
msg2 = "World"

print(msg1,msg2)


import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-20, 20, 1000)  # Create a list of evenly-spaced numbers over the range
func = np.sin(x)/x
plt.plot(x, func)       # Plot the sine of each x point
plt.show()