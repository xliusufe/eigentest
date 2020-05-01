from ._EIGENTEST import RandomDxDMatrix_


def generateMatrix(n):
    if(n<=0):
        return "n must be a positive integer!"      
    else:  
        dims = n
        M = np.array(RandomDxDMatrix_(dims), order="F")
        M.shape= dims,dims    
    return M