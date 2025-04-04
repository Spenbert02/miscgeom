# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import os
import sys
import importlib

# Add the project root to the Python path
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

# Pre-import the modules to avoid import errors
try:
    import miscgeom
    import miscgeom.intersection
    import miscgeom.mindist
except ImportError as e:
    print(f"WARNING: Could not import miscgeom modules: {e}")

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'miscgeom'
copyright = '2025, Spencer Bertram'
author = 'Spencer Bertram'
release = '0.0.2'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.autodoc',
    'numpydoc',
    'sphinx.ext.autosummary'
]

# Autosummary settings
autosummary_generate = True
autosummary_imported_members = True

# Configure numpydoc
numpydoc_show_class_members = False

templates_path = ['_templates']
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_book_theme'
html_static_path = ['_static']


# Setup function to handle autodoc
def setup(app):
    # Preload module members to avoid circular import issues
    for modname in ['miscgeom.intersection', 'miscgeom.mindist']:
        try:
            mod = importlib.import_module(modname)
            for attr_name in dir(mod):
                if not attr_name.startswith('_'):
                    getattr(mod, attr_name)
        except Exception as e:
            print(f"Warning: Failed to preload members of {modname}: {e}")
    return {'version': release}

