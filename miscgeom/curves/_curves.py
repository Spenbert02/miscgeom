from miscgeom.curves import fast_curves
import numpy as np


def lagrangeInterpolation1D(t, control_points):
    """evaluate a 1D lagrange interpolation fit given a set of control points

    Parameters
    ----------
    t : numpy.ndarray
        The parameter values at which to evaluate the curve.
    control_points : numpy.ndarray
        shape (N, 2) where N is the number of control points, each point is (t_i, p_i).
        Given N control points, the resulting curve is a polynomial of degree N-1.

    Returns
    -------
    numpy.ndarray
        The evaluated curve.
    """

    return fast_curves.cLagrangeInterpolation1D(t, control_points)
