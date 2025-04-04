from miscgeom.mindist import fast_mindist


def PointPoint(p1, q1):
    """
    Compute the 'minimum distance' between two points, which is just the Euclidean distance between them.

    Parameters
    ----------
    p1 : numpy.ndarray
        The first point, Shape (3,)
    q1 : numpy.ndarray
        The second point, Shape (3,)

    Returns
    -------
    float
        The Euclidean distance between p1 and q1.
    """
    return fast_mindist.cPointPoint(p1, q1)


def PointSegment(p1, q1, q2):
    """
    Compute the minimum distance between a point and a line segment.

    Parameters
    ----------
    p1 : numpy.ndarray
        The point, Shape (3,)
    q1 : numpy.ndarray
        The start of the segment, Shape (3,)
    q2 : numpy.ndarray
        The end of the segment, Shape (3,)

    Returns
    -------
    float
        The minimum distance between p1 and the segment defined by q1 and q2.
    """
    return fast_mindist.cPointSegment(p1, q1, q2)


def PointLine(p1, q1, q2):
    """
    Compute the minimum distance between a point and an 'infinite' line.

    Parameters
    ----------
    p1 : numpy.ndarray
        The point, Shape (3,)
    q1 : numpy.ndarray
        One point on the line, Shape (3,)
    q2 : numpy.ndarray
        Another point on the line, Shape (3,)

    Returns
    -------
    float
        The minimum distance between p1 and the line containing q1 and q2.
    """
    return fast_mindist.cPointLine(p1, q1, q2)


def SegmentSegment(p1, p2, q1, q2):
    """
    Compute the minimum distance between two line segments.
    
    Parameters
    ----------
    p1 : numpy.ndarray
        The start of the first segment, Shape (3,)
    p2 : numpy.ndarray
        The end of the first segment, Shape (3,)
    q1 : numpy.ndarray
        The start of the second segment, Shape (3,)
    q2 : numpy.ndarray
        The end of the second segment, Shape (3,)

    Returns
    -------
    float
        The minimum distance between the two segments.
    """
    return fast_mindist.cSegmentSegment(p1, p2, q1, q2)


def SegmentLine(p1, p2, q1, q2):
    """
    Compute the minimum distance between a line segment and an 'infinite' line.

    Parameters
    ----------
    p1 : numpy.ndarray
        The start of the segment, Shape (3,)
    p2 : numpy.ndarray
        The end of the segment, Shape (3,)
    q1 : numpy.ndarray
        One point on the 'infinite' line, Shape (3,)
    q2 : numpy.ndarray
        Another point on the 'infinite' line, Shape (3,)

    Returns
    -------
    float
        The minimum distance between the segment and the line.
    """
    return fast_mindist.cSegmentLine(p1, p2, q1, q2)


def LineLine(p1, p2, q1, q2):
    """
    Compute the minimum distance between two 'infinite' lines.

    Parameters
    ----------
    p1 : numpy.ndarray
        One point on the first line, Shape (3,)
    p2 : numpy.ndarray
        Another point on the first line, Shape (3,)
    q1 : numpy.ndarray
        One point on the second line, Shape (3,)
    q2 : numpy.ndarray
        Another point on the second line, Shape (3,)

    Returns
    -------
    float
        The minimum distance between the two lines.
    """
    return fast_mindist.cLineLine(p1, p2, q1, q2)
