import os
import datetime
n = 35


with open('data.txt', 'w') as file:
	for i in range(n):
	
		command1 = "glpsol --cpxlp ./files/input" + str(i) + ".lp -o ./files/output/output" + str(i) + ".txt1 > ./files/output/outputb" + str(i) + ".txt1"
		command2 = "./main < ./files/input" + str(i) + ".in" + "> ./files/output/outputb" + str(i) + ".txt2"
	
		z1 = datetime.datetime.now()
		os.system(command1)
		z1 = datetime.datetime.now() - z1

		print("")	
		z2 = datetime.datetime.now()
		os.system(command2)
		z2 = datetime.datetime.now() - z2
	
		file.write(str(i) + " " + str(z1.seconds * 1000000 + z1.microseconds) + " " + str(z2.seconds * 1000000 + z2.microseconds) + "\n")


