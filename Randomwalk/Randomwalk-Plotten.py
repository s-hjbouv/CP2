# -*- coding: utf-8 -*-
import math 
import numpy as np
import matplotlib.pyplot as plt
import sympy as sy


t=([0,1,2,3,4,5,6,7,8,9])

M1 = ([0,0.0002968,0.0004186,0.0006092,0.0003316,0.000159,0.0006148,0.0005448,-0.0001984,-0.00017])
M2 = ([0,1,2.00071,3.00098,4.00092,5.00073,5.99957,6.9984,7.998,8.9975])


# Plots mit einem Label versehen:
plt.plot(t, M1, color="r", linewidth=2.5, linestyle="-", label='1. Moment(t)')
plt.plot(t, M2, color="b",  linewidth=2.5, linestyle="-", label='2. Moment(t)')

# Legende einblenden:
plt.legend(loc='top left', frameon=True)


plt.grid(True)
#plt.title('Erstes und zweites Moment über die Zeit')

plt.plot(t,M1,'-or')
plt.plot(t,M2, "-ob") 

plt.show()                
        
