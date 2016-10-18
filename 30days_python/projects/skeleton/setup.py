try:
	from setuptools import setuptools
except ImportError:
	from distutils.core import setup

setup = {
	'description': '30days Project',
	'Author': 'Yam',
	'url': 'URL to get it at.',
	'download_url': 'Where to download it.',
	'author_email': 'haoshaochun@gmail.com',
	'version': '0.1',
	'install_requires': ['nose'],
	'packages': ['LOVEMAY'],
	'scripts': [],
	'name': 'Yam\'s Project'
}

#setup(**config)
