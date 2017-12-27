z1 = 1.3
z2 = 1.4

numberOfFiles = 35

for i in range(numberOfFiles):
	filename1 = 'files/input' + str(i) + '.lp'
	filename2 = 'files/input' + str(i) + '.in'
	filename3 = 'files/input' + str(i) + '.int'	
	n = i
	with open(filename1, 'w') as file:
		file.write("Maximize\n\t")
		file.write("obj: ")
		for j in range(n + 2):
			file.write(str(round(z1**(n + 3 - j), 2)))
			file.write(" x" + str(j + 1) + " + ")
		file.write("1 x" + str(n + 3))
		file.write("\nSubject To\n")
		for j in range(n + 3):
			file.write("\tc" + str(j + 1) + ": ")
			
			for k in range(j):
				file.write(str(round(z1**(j + 1 - k), 2)))
				file.write(" x" + str(k + 1) + " + ")
			file.write("1 x" + str(j + 1) + " <= " + str(round(z2 ** (j + 1), 2)))
			file.write("\n")
		file.write("End")
	with open(filename2, 'w') as file:
		file.write("1\n")
		file.write(str(n + 3) + " " + str(n + 3) + "\n")
		for j in range(n + 2):
			file.write(str(round(z1**(n + 3 - j), 2)) + " 0 ")
		file.write("1 0\n")
		for j in range(n + 3):
			for k in range(j):
				file.write(str(round(z1**(j + 1 - k), 2)) + " ")
			file.write("1 ")			
			for k in range(j, n + 2):
				file.write(str(0) + " ")			
			file.write(str(round(z2**(j + 1), 2)) + " 0\n")
	with open(filename3, 'w') as file:
		file.write("1 " + str(n + 4) + " " + str(n + 4) + "\n")
		file.write("0 ")
		for j in range(n + 2):
			file.write(str(round(z1**(n + 3 - j), 2)) + " ")
		file.write("1\n")
		for j in range(n + 3):
			file.write("l ")
			file.write(str(round(z2**(j + 1), 2)) + " ")
			for k in range(j):
				file.write(str(round(z1**(j + 1 - k), 2)) + " ")
			file.write("1")
			for k in range(j, n + 2):
				file.write(" " + str(0))
			file.write("\n")

