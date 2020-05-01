# eigentest
Python package "eigentest" is a toy example for package Python including Eigen of C/C++.

# Installation

    pip install git+https://github.com/xliusufe/eigentest.git

   
# Example 1


    import eigentest as ep
    import numpy as np
    DIM = 4
    M = np.array(ep.randomDxDMatrix(DIM), order="F")
    M.shape= DIM,DIM
    print(M)
    

# Development
This Python package is developed by Xu Liu (liu.xu@sufe.edu.cn).

