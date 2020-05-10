#!/bin/bash

t Test/test_$1.{c,h}

echo #include "../lib_unittest/myunittest.h"\n\nvoid test_foo()\n{\n\n}
