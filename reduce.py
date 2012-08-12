import sys

last_key = ""
count = 0
sum = 0.0
total_count = 0
for line in sys.stdin:
    (key, value) = line.split("\t", 1)
    if key != last_key:
        if last_key != "":
            print "%s\t%d\t%f" % (last_key, count, sum)
        last_key = key
        count = 0
        sum = 0.0
    sum += float(value)
    count += 1
print "%s\t%d\t%f" % (last_key, count, sum)
