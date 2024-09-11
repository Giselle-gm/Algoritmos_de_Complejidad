from random import randint

def generate_matrix(rows, cols, min_val=1, max_val=100):
    return [[randint(min_val, max_val) for _ in range(cols)] for _ in range(rows)]
    
def write_matrices_to_file(file_name, matrixA, matrixB):
    with open(file_name, 'w') as file:
        file.write(f"{len(matrixA)} {len(matrixA[0])}\n")
    
        for row in matrixA:
            file.write(" ".join(map(str, row)) + "\n")
            
        file.write("\n")
        file.write(f"{len(matrixB)} {len(matrixB[0])}\n")
        
        for row in matrixB:
            file.write(" ".join(map(str, row)) + "\n")
        

x, y, z = 100, 500, 100
matrixA = generate_matrix(x, y, min_val=1, max_val=500)
matrixB = generate_matrix(y, z, min_val=1, max_val=500)
write_matrices_to_file("Matriz XxY.txt", matrixA, matrixB)

