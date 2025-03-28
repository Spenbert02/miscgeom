from . import mindist


def PointPoint(p1, q1):
    return mindist.cPointPoint(p1, q1)

def PointSegment(p1, q1, q2):
    return mindist.cPointSegment(p1, q1, q2)

def PointLine(p1, q1, q2):
    return mindist.cPointLine(p1, q1, q2)

def SegmentSegment(p1, p2, q1, q2):
    return mindist.cSegmentSegment(p1, p2, q1, q2)

def SegmentLine(p1, p2, q1, q2):
    return mindist.cSegmentLine(p1, p2, q1, q2)

def LineLine(p1, p2, q1, q2):
    return mindist.cLineLine(p1, p2, q1, q2)
