try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    "description": "ex48 - creating a parser for text-based game",
    "author": "EC",
    "url": "null",
    "download_url": "null",
    "author_contact": "chaos.is.harmony.official@gmail.com",
    "version": "0.1",
    "install_requires": ["nose"],
    "packages": ["game"],
    "scripts": [],
    "name": "ex48"
    }
