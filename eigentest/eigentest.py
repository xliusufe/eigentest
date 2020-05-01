from ._EIGENTEST import MatrixPlus_
import numpy

def generateMatrix(n):
    if(n<=0):
        return "n must be a positive integer!"      
    else:  
        dims = n
        M = numpy.array(MatrixPlus_(dims), order="F")
        M.shape= dims,dims    
    return M