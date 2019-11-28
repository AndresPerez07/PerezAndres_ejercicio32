import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#%%

data = np.loadtxt("cuerda.dat")

np.shape(data)
size_x = np.shape(data)[1]
size_y = np.shape(data)[0]

x = np.linspace(0,1, size_x)
y = np.linspace(0,size_y, size_y)

#%%
plt.plot(x,data[-1])
plt.show()
#%%
X, Y = np.meshgrid(x,y)

np.shape(y)

fig = plt.figure(figsize=(10,10))
ax = fig.gca(projection='3d')

surf = ax.plot_surface(X,Y,data, cmap='inferno', antialiased=False)
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("y")

plt.show()
