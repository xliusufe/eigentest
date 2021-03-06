from ._EIGENTEST import MatrixPlus_
import numpy

def generateMatrix(n):
    if(n<=0):
        return "n must be a positive integer!"      
    else:  
        dims = n
        M0 = numpy.eye(dims,dims)
        V0 = numpy.random.randn(dims,dims)
        M = numpy.array(MatrixPlus_(M0, V0, dims), order="F")
        M.shape= dims,dims    
    return M