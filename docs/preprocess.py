"""
Script to prepare API documentation.
"""


import os


def ensure_api_directory():
    """Ensure the API directory exists and is clean."""
    docs_dir = os.path.dirname(os.path.abspath(__file__))
    api_dir = os.path.join(docs_dir, 'source', 'api')
    
    # Create or clean the api directory
    if os.path.exists(api_dir):
        # Only remove generated files, keep our manual RST files
        for file in os.listdir(api_dir):
            if file.endswith('.rst') and file not in ['index.rst', 'intersection.rst', 'mindist.rst']:
                os.remove(os.path.join(api_dir, file))
    else:
        os.makedirs(api_dir)


if __name__ == '__main__':
    ensure_api_directory()