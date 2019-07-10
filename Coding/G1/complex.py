import numpy as np

sum = 0
mul = 1 + 0j

with open('complex.txt', 'w') as out_file:
	for i in range(100):
		x = np.random.random() + (np.random.random())*1j
		out_file.write(str(x) + "\n")
		sum += x
		mul *= x
print(sum)
print(mul)