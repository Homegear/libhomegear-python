#!/bin/bash
rm -Rf dist
python3 setup.py sdist
twine upload dist/*