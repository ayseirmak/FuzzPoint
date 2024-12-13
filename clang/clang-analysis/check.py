import os
be_op1 = "/users/a_irmak/backend_optimization_files.log"
be_op2 = "/users/a_irmak/backend_optimization_files2.log"

with open(be_op1, 'r') as file:
    opt1 = file.readlines()

with open(be_op2, 'r') as file:
    opt2 = file.readlines()

for  i in opt1:
    if i not in opt2:
        print(i)