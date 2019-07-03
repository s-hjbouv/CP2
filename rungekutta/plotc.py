import matplotlib.pyplot as plt
import numpy as np


dy5=np.loadtxt("dy.5")
y5=np.loadtxt("phase.5")


T=0.5*dy5**2
V=-9.81*np.cos(y5)
H=T+V

x=np.linspace(0,30,300)

plt.plot(x,T,"-r",label="T")
plt.plot(x,V,"-b",label="V")
plt.plot(x,H,"-g",label="H=T+V")


plt.legend(loc='best')
plt.xlabel('timestep/s')
plt.ylabel('energy/J')
plt.title('conservation of energy with initial angle 3/4$\pi$')
plt.show()

