import numpy as np

with open("input.txt", "r") as f:
    lines = f.readlines()
    
    total = 0.0
    for i in range(0, len(lines), 4):
             
        chunk = lines[i:i+3]
        
        matrix = np.array([[0.0, 0.0],[0.0, 0.0]])
        #result = np.array([[0.0], [0.0]])
        result = np.array([0.0, 0.0])

        for i in range(0, len(chunk)):
            row = chunk[i].split()
            if i == 0 or i == 1:
                matrix[0][i] = row[2].split("+")[1].replace(",", "")
                matrix[1][i] = row[3].split("+")[1]
            else:
                result[0] = row[1].split("=")[1].replace(",", "")
                result[1] = row[2].split("=")[1]
        
        result[0] += 10000000000000
        result[1] += 10000000000000
        m = matrix 
        r = np.linalg.solve(matrix, result)
        a = round(r[0])
        b = round(r[1])
        
        if (a * m[0][0] + b * m[0][1] == result[0]) and (a * m[1][0] + b * m[1][1] == result[1]):
            total += a*3
            total += b
    
    print(total)
