from nose.tools import *
from ex47.game import Room

def test_room():
    gold = Room("Gold Room", """Go north and/or grab gold""")
    assert(gold.name == "Gold Room")
    assert(gold.paths == {})

def test_room_paths():
    center = Room("Center", "Center room")
    north = Room("North", "North room")
    south = Room("South", "North room")

    center.add_paths({"north" : north, "south" : south})
    assert(center.go("north") == north)
    assert(center.go("south") == south)

def test_map():
    start = Room("Start", "")
    west = Room("Trees", "")
    down = Room("Dungeon", "")

    start.add_paths({"west": west, "down": down})
    west.add_paths({"east": start})
    down.add_paths({"north": start})

    assert(start.go("west") == west)
    assert(start.go("west").go("east") == start)
    assert(start.go("down").go("north") == start)
