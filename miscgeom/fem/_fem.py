import numpy as np
# import sympy as sym
import mpmath as mp


def get_reference_basis_funcs(d):
    nodes = np.linspace(-1, 1, d+1)  # for d=1 gives [-1, 1], for d=2 gives [-1, 0, 1], etc.
    ret_basis_funcs = []
    for r in range(d + 1):
        ret_basis_funcs.append(get_lagrange_basis_func(r, nodes))
    return ret_basis_funcs


def get_lagrange_basis_func(r, nodes):  # this a general lagrange function - local indices s and r used but just cosmetic
    def retfunc(x, r=r, nodes=nodes):
        ret_val = 1
        for s in range(len(nodes)):
            if s != r:
                ret_val *= (x - nodes[s]) / (nodes[r] - nodes[s])
        return ret_val
    return retfunc


def get_element_matrix(e, nodes, elements, ref_bases, d):
    dxdX = (nodes[elements[e][-1]] - nodes[elements[e][0]]) / 2
    Ae = np.zeros((d+1, d+1))
    for r in range(d+1):
        for s in range(r, d+1):
            Ae[r][s] = mp.quad(lambda X: ref_bases[r](X) * ref_bases[s](X) * dxdX, [-1, 1])
            Ae[s][r] = Ae[r][s]
    return Ae


def get_element_vector(e, nodes, elements, bases, f, d):
    def x_affine(X, xL, xR):
        return (0.5 * (xL + xR)) + (0.5 * (xL - xR) * X)
    be = np.zeros((d+1,))
    for r in range(d+1):
        be[r] = mp.quad(lambda X: bases[r](X) * f(x_affine(X, nodes[elements[e][0]], nodes[elements[e][-1]])), [-1, 1])
    return be


# def get_full_basis_functions(nodes):
#     ret_bases = []

#     # boundary element 0
#     def _phi_0(x, nodes=nodes):
#         if x < nodes[0] or x > nodes[1]:  # x outside nonzero portion of phi_0 (element 0)
#             return 0
#         else:  # x in [x0, x1] (element 0)
#             return get_lagrange_basis_func(0, nodes[0:2])(x)
#     ret_bases.append(_phi_0)

#     # internal elements
#     for i in range(1, nodes.shape[0] - 1):
#         def _phi_i(x, i=i, nodes=nodes):
#             if x < nodes[i-1] or x > nodes[i+1]:  # x outside nonzero portion of phi_i
#                 return 0
#             elif x <= nodes[i]:  # x in [x_i-1, x_i]
#                 return get_lagrange_basis_func(1, nodes[i-1:i+1])(x)
#             else:  # x in [x_i, x_i+1]
#                 return get_lagrange_basis_func(0, nodes[i:i+2])(x)
#         ret_bases.append(_phi_i)

#     # boundary element N
#     def _phi_N(x, nodes=nodes):
#         if x < nodes[-2] or x > nodes[-1]:  # x outside last element, phi_N is nonzero outside element N
#             return 0
#         else:  # x inside element N
#             return get_lagrange_basis_func(1, nodes[-2:])(x)
#     ret_bases.append(_phi_N)

#     return ret_bases


def get_u_func(c, nodes, elements, ref_bases):
    def u(x, c=c, nodes=nodes, elements=elements, ref_bases=ref_bases):
        ret = np.zeros_like(x)
        for e in range(elements.shape[0]):
            element_eval_inds = (x > nodes[elements[e][0]]) & (x < nodes[elements[e][1]])
            for r in range(2):
                # ret[element_eval_inds] = 
                pass


def idk():
    d = 1
    # define mesh
    Ne = 3
    nodes = np.linspace(-2, 2, Ne + 1)
    elements = np.array([[i, i+1] for i in range(Ne)])
    ref_phis = get_reference_basis_funcs(d)  # d=1, reference basis functions for linear elements
    f = lambda x : x*x  # f = x^2, function to approximate

    # # testing numerical integration
    # f1 = lagrangeLinear(nodes[elements[0][0]], nodes[elements[0][1]])
    # f2 = lagrangeLinear(nodes[elements[0][1]], nodes[elements[0][0]])
    # return(innerProd(f1, f2, nodes[elements[0][0]], nodes[elements[0][1]]))

    # compute element matrix
    A = np.zeros((Ne+1, Ne+1))  # one basis function for each node
    for e in range(elements.shape[0]):  # elementwise assembly
        Ae = get_element_matrix(e, nodes, elements, ref_phis, d)
        for r in range(d+1):
            for s in range(d+1):
                A[elements[e][r], elements[e][s]] += Ae[r][s]
    
    # compute element vector
    b = np.zeros((nodes.shape[0],))
    for e in range(len(elements)):
        be = get_element_vector(e, nodes, elements, ref_phis, f, d)
        for r in range(d+1):
            b[elements[e][r]] = b[elements[e][r]] + be[r]

    # solve system
    c = np.linalg.solve(A, b)

    # reconstruct solution
    phis = get_full_basis_functions(nodes)
    return c, phis
