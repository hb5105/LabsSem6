out= open("output2.txt", "w")
with open("q4.py", "r") as myfile: 
    file_str = myfile.read()
reversed_str = file_str[::-1] 
out.write(reversed_str)   
out.close() 