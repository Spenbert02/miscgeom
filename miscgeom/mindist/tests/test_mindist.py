import pytest
import numpy as np

from miscgeom.mindist import PointPoint, PointSegment, PointLine, SegmentSegment, SegmentLine, LineLine


def test_PointPoint():
    p1 = np.array([0, 0, 0])
    q1 = np.array([1, 0, 0])
    assert PointPoint(p1, q1) == 1.0


def test_PointSegment():
    # t_min < 0
    p1 = np.array([0, -1, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointSegment(p1, q1, q2), np.sqrt(2), atol=1e-6, rtol=0.0)

    # t_min = 0 'exactly'
    p1 = np.array([0, 0, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointSegment(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # 0 < t_min < 1
    p1 = np.array([0, 0.5, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointSegment(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # t_min = 1 'exactly'
    p1 = np.array([0, 1, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointSegment(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # t_min > 1
    p1 = np.array([0, 2, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointSegment(p1, q1, q2), np.sqrt(2), atol=1e-6, rtol=0.0)


def test_PointLine():
    # t_min < 0
    p1 = np.array([0, -1, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointLine(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # t_min = 0 'exactly'
    p1 = np.array([0, 0, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointLine(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # 0 < t_min < 1
    p1 = np.array([0, 0.5, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointLine(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # t_min = 1 'exactly'
    p1 = np.array([0, 1, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointLine(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # t_min > 1
    p1 = np.array([0, 2, 0])
    q1 = np.array([1, 0, 0])
    q2 = np.array([1, 1, 0])
    assert np.isclose(PointLine(p1, q1, q2), 1.0, atol=1e-6, rtol=0.0)

def test_SegmentSegment():
    pass

def test_SegmentLine():
    pass

def test_LineLine():
    # nonparallel but no z component. Min dist is z-offset
    p1 = np.array([0, 0, 0])
    p2 = np.array([1, 1, 0])
    q1 = np.array([1, 0, 1])
    q2 = np.array([0, 1, 1])
    assert np.isclose(LineLine(p1, p2, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # parallel lines, offset in z
    p1 = np.array([0, 0, 0])
    p2 = np.array([1, 1, 0])
    q1 = np.array([0, 0, 1])
    q2 = np.array([1, 1, 1])
    assert np.isclose(LineLine(p1, p2, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # identical lines
    p1 = np.array([0, 0, 0])
    p2 = np.array([1, 1, 1])
    q1 = np.array([0, 0, 0])
    q2 = np.array([1, 1, 1])
    assert np.isclose(LineLine(p1, p2, q1, q2), 0.0, atol=1e-6, rtol=0.0)

    # intersecting lines
    p1 = np.array([0, 0, 0])
    p2 = np.array([1, 1, 1])
    q1 = np.array([1, 0, 0])
    q2 = np.array([0, 1, 1])
    assert np.isclose(LineLine(p1, p2, q1, q2), 0.0, atol=1e-6, rtol=0.0)

    # almost parallel lines (within parallel tolerance)
    p1 = np.array([0, 1, 0])
    p2 = np.array([1, 1, 0])
    q1 = np.array([0, 0, 0])
    q2 = np.array([1, 1e-10, 0])
    assert np.isclose(LineLine(p1, p2, q1, q2), 1.0, atol=1e-6, rtol=0.0)

    # almost parallel lines (outside parallel tolerance)
    p1 = np.array([0, 1, 0])
    p2 = np.array([1, 1, 0])
    q1 = np.array([0, 0, 0])
    q2 = np.array([1, 1e-2, 0])
    assert np.isclose(LineLine(p1, p2, q1, q2), 0.0, atol=1e-6, rtol=0.0)
