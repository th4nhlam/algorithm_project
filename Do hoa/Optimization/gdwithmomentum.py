import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def f(x):
	return x**2 + 10 * np.sin(x) 

# Đạo hàm
def fd(x):
	return 2*x + 10 * np.cos(x)

x_min = -4
x_max = 6
x = np.linspace(x_min, x_max, 200)
y = f(x)
a = 0.1  # Learning rate
b = 0.9
x_est = 6  # Starting point
y_est = f(x_est)
v_est=0
 

def animate(i):
	global x_est
	global y_est
	global v_est

	# Gradient descent
	v_est = b*v_est + a * fd(x_est)
	x_est= x - v_est
	y_est = f(x_est)

	# Update the plot
	scat.set_offsets([[x_est,y_est]])
	text.set_text("x=: %.2f y= : %.2f" % (x_est,y_est))
	line.set_data(x, y)
	return line, scat, text

def init():
	line.set_data([], [])
	return line,

# Visualization Stuff
fig, ax = plt.subplots()
ax.set_xlim([x_min, x_max])
ax.set_ylim([-15, 25])
ax.set_xlabel("x")
ax.set_ylabel("f(x)")
plt.title("Gradient Descent")
line, = ax.plot([], [])
scat = ax.scatter([], [], c="red")
text = ax.text(-2,20,"")

ani = animation.FuncAnimation(fig, animate, 100,
	init_func=init, interval=100, blit=True)

plt.show()

