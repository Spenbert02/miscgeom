import pytest
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
import time

import logging
LOGGER = logging.getLogger(__name__)  # LOGGER.info("message yaddayadda") will show up in the pytest output

from miscgeom.curves import lagrangeInterpolation1D


def test_lagrangeInterpolation1D():
    # uncomment to run the interactive plot
    assert True
    return

    # Initial control points
    control_points = np.array([
        [0, 5],
        [1, 5],
        [2, 5],
        [3, 5],
        [4, 5],
        [5, 5],
        [6, 5],
        [7, 5],
        [8, 5],
        [9, 5]
    ], dtype=np.float64)
    t = np.linspace(0, control_points[-1, 0], 100)

    # Create the figure and axis
    fig, ax = plt.subplots(figsize=(10, 8))
    plt.subplots_adjust(bottom=0.3)  # Make room for sliders

    # Initial plot
    curve_y = lagrangeInterpolation1D(t, control_points)
    line, = ax.plot(t, curve_y, 'b-', linewidth=2, label='Lagrange Interpolation')
    scatter = ax.scatter(control_points[:, 0], control_points[:, 1], c='red', s=100, zorder=5, label='Control Points')

    # Set up the plot
    ax.set_xlabel('t')
    ax.set_ylabel('y')
    ax.set_xlim(-0.2, control_points[-1, 0] + 0.2)
    ax.set_ylim(-0.2, 10)
    ax.set_title('1D Lagrange Interpolation')
    ax.grid(True, alpha=0.3)
    ax.legend()

    # Function to update the plot
    def update(val):
        # Update control points with current slider values
        for i in range(len(control_points)):
            control_points[i, 1] = sliders[i].val
        
        # Recalculate the curve
        curve_y = lagrangeInterpolation1D(t, control_points)
        
        # Update the plot
        line.set_ydata(curve_y)
        scatter.set_offsets(control_points)

    # Create sliders
    sliders = []
    slider_height = 0.02
    slider_spacing = 0.03

    for i in range(len(control_points)):
        # Create slider axis
        ax_slider = plt.axes([0.2, 0.1 + i * slider_spacing, 0.6, slider_height])
        
        # Create slider
        slider = Slider(
            ax_slider, 
            f'Y_{i}', 
            valmin=0, 
            valmax=10, 
            valinit=control_points[i, 1]
        )
        
        slider.on_changed(update)
        sliders.append(slider)

    plt.show()
    
    assert True