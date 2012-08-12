reduce
======

reduce values into counts and sums by key in a unix pipeline    
ensure that keys are sorted, or you will end up with duplicate keys    

## invocation

Say you have a file that looks like this:

    $ cat test
    547E34E3    625.541881
    5E89C7ED    46.530887
    77C63B96    607.471872
    77C63B96    312.987605
    65607553    406.177782
    3EE956A8    659.357774
    5E89C7ED    791.170035
    77C63B96    611.615921
    5E89C7ED    31.559096
    50A7503E    76.006676

You can use reduce to show counts and sums by key:

    $ sort test | reduce
    3EE956A8    1   659.357774
    50A7503E    1   76.006676
    547E34E3    1   625.541881
    5E89C7ED    3   869.260018
    65607553    1   406.177782
    77C63B96    3   1532.075398

## installation

    git clone git://github.com/thinkjson/reduce.git
    cd reduce
    make
    sudo make install

## a more useful example

Say you have an Apache log file:

    $ head -n 1 /var/log/apache/access_log
    11.11.11.11 - - [08/Sep/2011:09:54:07 -0500] "GET /some/endpoint?page=23 HTTP/1.1" 200 23414

You could use awk and reduce to get number of requests and total download size by IP:

    $ awk '{ print $1,"\t",$10 }' <test2 | sort | reduce
    11.11.11.11     9   23622397.000000
    22.22.22.22     3   59571.000000
    33.33.33.33     2   36979.000000


## unscientific benchmark

C implementation as compared to Python reference implementation:

    $ junk | head -c 536870912 | sort > test

    $ time python reduce.py <test
    12295AA     1594057 797027391.917313
    176DB578    1591997 796713786.895693
    1B6AC571    1593859 796683991.847406
    2832BCBB    1591308 795813102.401661
    28B7C900    1590218 794926035.116776
    2FF2BBA0    1592749 796364424.422276
    335BC38B    1593920 797092799.875688
    354EA099    1592517 796091494.804439
    36616783    1590134 795260976.175797
    38B01E63    1591729 795498131.549879
    3B832AB6    1591751 795651015.583024
    3FAC4937    1592660 796958985.433190
    5733ECF2    1592809 796763147.739992
    64D1A314    1593714 796934804.583485
    67691121    1592459 796363917.955302
    69158B01    1592363 796440560.420301
    6FE6939C    1593860 797736562.409239

    real    0m40.028s
    user    0m39.725s
    sys     0m0.250s

    $ time reduce <test
    12295AA     1594057 797027391.917313
    176DB578    1591997 796713786.895693
    1B6AC571    1593859 796683991.847406
    2832BCBB    1591308 795813102.401661
    28B7C900    1590218 794926035.116776
    2FF2BBA0    1592749 796364424.422276
    335BC38B    1593920 797092799.875688
    354EA099    1592517 796091494.804439
    36616783    1590134 795260976.175797
    38B01E63    1591729 795498131.549879
    3B832AB6    1591751 795651015.583024
    3FAC4937    1592660 796958985.433190
    5733ECF2    1592809 796763147.739992
    64D1A314    1593714 796934804.583485
    67691121    1592459 796363917.955302
    69158B01    1592363 796440560.420301
    6FE6939C    1593860 797736562.409239

    real    0m8.730s
    user    0m8.526s
    sys     0m0.197s


Copyright (c) 2012 Mark Cahill

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
