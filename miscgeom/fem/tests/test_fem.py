import pytest
import numpy as np
import matplotlib.pyplot as plt

import logging
LOGGER = logging.getLogger(__name__)  # LOGGER.info("message yaddayadda") will show up in the pytest output

from miscgeom.fem import idk

@pytest.mark.fem
def test_idk():
    # c, phis = idk()

    b = idk()
    LOGGER.info(b)

    # # LOGGER.info(str(result) + f" | {0.5 / 6}")
    # LOGGER.info("\n" + str(4* (result / np.max(result))))
    # LOGGER.info("\n" + str(result))

    # x = np.linspace(-2, 2, 1000)
    # f = np.pow(x, 2)
    # def _u(_x):
    #     ret = 0
    #     for i in range(c.shape[0]):
    #         ret = ret + (c[i] * phis[i](_x))
    #     return ret
    # u = [_u(__x) for __x in x]

    # LOGGER.info([np.min(u), np.max(u)])
    # LOGGER.info(c)

    # fig = plt.figure()
    # ax = fig.add_subplot()
    # ax.plot(x, f)
    # ax.plot(x, u, "r--")
    # ax.set_xlim(-3, 3)
    # ax.set_aspect('equal')
    # plt.show()

    assert 1 == 1
