import matplotlib.pyplot as plt
import numpy as np

y0=np.loadtxt("phase.0")
y1=np.loadtxt("phase.1")
#y2=np.loadtxt("phase.2")
#y3=np.loadtxt("phase.3")
y4=np.loadtxt("phase.4")
y5=np.loadtxt("phase.5")

x=np.linspace(0,30,300)

plt.plot(x,y0,"-r",label="y0=0")
plt.plot(x,y1,"-b",label="y0=$\pi$/16")
#plt.plot(x,y2,"-g",label="y0=$\pi$/8")
#plt.plot(x,y3,"-k",label="y0=$\pi$/4")
plt.plot(x,y4,"-c",label="y0=$\pi$/2")
plt.plot(x,y5,"-m",label="y0=3$\pi$/4")

plt.legend(loc='best')
plt.xlabel('timestep/s')
plt.ylabel('phase')
plt.title('pendulum')
plt.show()



