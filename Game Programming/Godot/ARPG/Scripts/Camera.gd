extends Camera2D

const ZOOM_IN_DELTA = 0.0125
const ZOOM_OUT_DELTA = 0.0125
const DURATION = 3

onready var timer = $Timer
onready var player = get_node("../YSort/Player")
onready var top_left = $Limits/TopLeft
onready var bottom_right = $Limits/BottomRight


func _ready():
	limit_bottom = bottom_right.position.y
	limit_right = bottom_right.position.x
	limit_top = top_left.position.y
	limit_left = top_left.position.x
	player.connect("in_combat", self, "zoom_in")
	player.connect("not_in_combat", self, "zoom_out")


func start_timer():
	timer.start(DURATION)


func zoom_in():
	if self.zoom.x > 0.75:
		self.zoom = Vector2(self.zoom.x-ZOOM_IN_DELTA, self.zoom.y-ZOOM_IN_DELTA)


func zoom_out():
	if timer.time_left == 0 and self.zoom.x < 0.99:
		self.zoom = Vector2(self.zoom.x+ZOOM_OUT_DELTA, self.zoom.y+ZOOM_OUT_DELTA)
