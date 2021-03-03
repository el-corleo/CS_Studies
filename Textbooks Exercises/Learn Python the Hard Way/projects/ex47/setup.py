try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    "description": "Exercise 47 LPTHW",
    "author": "EC",
    "url": "null",
    "download_url": "null",
    "author_contact": "chaos.is.harmony.official@gmail.com",
    "version": "0.1",
    "install_requires": ["nose"],
    "packages": ["ex47"],
    "scripts": [],
    "name": "ex47"
    }
