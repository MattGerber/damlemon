from random import randint
import sys

CONST_X = 60
CONST_Y = 40

ROOMS = 30

if len(sys.argv) == 2:
	ROOMS = int(sys.argv[1])

ended = False
end_room = - 1
print 10
for room in range(0, ROOMS + 1):
	if room == 0:
		print "##start"
	if not ended and room == randint(room, ROOMS) and room != 0:
		ended = True
		end_room = room
		print "##end"
	if not ended and room == ROOMS - 1:
		print "##end"
		end_room = room
	print room, randint(3, CONST_X), randint(3, CONST_Y)

for link in range(0, ROOMS * 2):
	print "{0}-{1}".format(randint(0, ROOMS), randint(0, ROOMS))

print "0-1"
print "0-3"
print "{0}-{1}".format(randint(ROOMS / 2, ROOMS), end_room)
print "{0}-{1}".format(randint(ROOMS / 2, ROOMS), end_room)
print "{0}-{1}".format(randint(ROOMS / 2, ROOMS), end_room)