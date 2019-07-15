import math 
import numpy as np
import pylab as plt


file = '/home/s-hjbouv/Schreibtisch/CP2/Poisson/Potential0.txt'

x,y,phi = np.loadtxt(file,dtype=float,delimiter=None,unpack=True)

print(phi)

x_label=plt.xlabel(r'y',position=(500,0))
y_label=plt.ylabel(r'x',position=(0,500))

fig=plt.figure()

k=phi.reshape(10,10)
x=np.arange(0,10,1)
y=np.arange(0,10,1)

print(k)
X,Y = np.meshgrid(x,y)
plt.subplot(111)
h=plt.contourf(X,Y,k,cmap='magma')
cbar=fig.colorbar(h)

plt.show()
