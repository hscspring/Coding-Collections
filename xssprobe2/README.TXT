XSSProbe2

XSSProbe2 contains JavaScript Probe and PNG Probe.

2017/12/22
by evilcos@gmail.com

[Basic]
sudo apt-get install python-dev
sudo apt-get install nginx
sudo apt-get install python-pip
sudo pip install -r requirement.txt
sudo service nginx restart

cd xssprobe2

[Debug Mode]
python manage.py runserver 0.0.0.0:8000

[uWSGI Mode]
Please Google "uWSGI Django".

[JavaScript Probe]
./probe_create.py a1 http://192.168.1.123:8000
./cmd_create.py a1 cmd1.txt

Then, probe url:
http://192.168.1.123:8000/a1.js

[PNG Probe]
cp js/payload/probe.png js/probe/a1.png

Then, probe url:
http://192.168.1.123:8000/a1.png

Result will be in dir(./js/probe/).

