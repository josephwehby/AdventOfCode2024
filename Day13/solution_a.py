import numpy as np

with open("input.txt", "r") as f:
    lines = f.readlines()
    
    total = 0.0
    for i in range(0, len(lines), 4):
             
        chunk = lines[i:i+3]
        
        matrix = np.array([[0.0, 0.0],[0.0, 0.0]], dtype=float)
        result = np.array([[0.0], [0.0]], dtype=float)
        for i in range(0, len(chunk)):
            row = chunk[i].split()
            if i == 0 or i == 1:
                matrix[0][i] = float(row[2].split("+")[1].replace(",", ""))
                matrix[1][i] = float(row[3].split("+")[1])
            else:
                result[0][0] = float(row[1].split("=")[1].replace(",", ""))
                result[1][0] = float(row[2].split("=")[1])

        inv = np.linalg.inv(matrix)
        result = np.matmul(inv, result)

        if not np.all(np.isclose(result, np.round(result))):
            continue
        

        total += result[0][0] * 3
        total += result[1][0]
    
    print(total)
