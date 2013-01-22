#! /bin/bash

touch install-sh
cd src/libstrophe && ./bootstrap.sh && cd ../..
autoconf
