#!/bin/env python
import urllib2
import urllib
import json

#response = urllib2.urlopen("http://www.baidu.com")
request = urllib2.Request("http://www.baidu.com")
response = urllib2.urlopen(request)
print response.read()

d = {'first_name': 'Guido',
        'second_name': 'Rossum',
        'titles': ['BDFL', 'Developer'],
}

parsed_json = json.loads(json.dumps(d))

print parsed_json['first_name']
print parsed_json
