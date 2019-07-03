import matplotlib.pyplot as plt
import numpy as np


x=np.linspace(0,30,300)


z5=-9.81*2.3562*np.cos(np.sqrt(9.81)*x)
dz5=np.sqrt(9.81)**3*2.3562*np.sin(np.sqrt(9.81)*x)

T=0.5*dz5**2
V=-9.81*np.cos(z5)
H=T+V


plt.plot(x,T,"-r",label="T")
plt.plot(x,V,"-b",label="V")
plt.plot(x,H,"-g",label="H=T+V")


plt.legend(loc='best')
plt.xlabel('timestep/s')
plt.ylabel('energy/J')
plt.title('approximated energy for initial angle 3/4$\pi$')
plt.show()


