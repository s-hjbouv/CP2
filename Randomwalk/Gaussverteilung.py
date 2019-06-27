# -*- coding: utf-8 -*-
import math as m 
import numpy as np
import matplotlib.pyplot as plt
import sympy as sy


x1 = ([-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9])
y1 = ([9670,0,97357,0,439671,0,1.17083*10**6,0,2.05271*10**6,0,2.46094*10**6,0,2.0511*10**6,0,1.17118*10**6,0,438785,0,97957,0])

x2 = np.linspace(-10.0,10.0,1000)
y2 = (10000000/(np.sqrt(0.999682)*np.sqrt(2*np.pi)))*np.exp(-((x2*x2)/(2*0.999682)))

# Plots mit einem Label versehen:
plt.plot(x1, y1, color="r", linewidth=2.5, label='berechnete Gaussverteilung')
plt.plot(x2, y2, color="b",  linewidth=2.5, linestyle="-", label='theoretische Gaussverteilung')

# Legende einblenden:
plt.legend(loc='upper right', frameon=True)

plt.grid(True)
plt.title('Gaussverteilung')

plt.plot(x1,y1,'r-o')
plt.plot(x2,y2, "-b") 

#plt.axis( [-10, 9, 0, 3.00*10**6] )

plt.xlabel("Teilchenposition")
plt.ylabel("Haeufigkeit")
plt.show()                
        

