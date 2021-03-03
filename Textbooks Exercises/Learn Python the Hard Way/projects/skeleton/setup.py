try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    "description": "<PROJECT_NAME>",
    "author": "EC",
    "url": "<WEBSITE_URL>",
    "download_url": "<DOWNLOAD_URL>",
    "author_contact": "chaos.is.harmony.official@gmail.com",
    "version": "0.1",
    "install_requires": ["nose"],
    "packages": ["NAME"],
    "scripts": [],
    "name": "<project_name>"
    }
