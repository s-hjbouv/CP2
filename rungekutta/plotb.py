import matplotlib.pyplot as plt
import numpy as np
import sympy as sy

y1=np.loadtxt("phase.1")
y5=np.loadtxt("phase.5")

x=np.linspace(0,30,300)

z1=-9.81*0.1963*np.cos(np.sqrt(9.81)*x)
z5=-9.81*2.3562*np.cos(np.sqrt(9.81)*x)


plt.plot(x,y1,".b",label="y0=$\pi$/16, numerical")
plt.plot(x,y5,".m",label="y0=3$\pi$/4, numerical")


plt.plot(x,z1,"-b",label="y0=$\pi$/16, approximation")
plt.plot(x,z5,"-m",label="y0=3$\pi$/4, approximation")



plt.legend(loc='best')
plt.xlabel('timestep/s')
plt.ylabel('phase')
plt.title('comparison approximation - numerical result')
plt.show()


