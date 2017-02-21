#!/bin/sh
        #Created by Ian Shaw

host=$1
file=$2

echo "Getting $file from $host"

bastion=x.x.x.x
username=<username>

cd /tmp

scp $username@$bastion:root@$host:$file .
diff $(basename $file) $file
