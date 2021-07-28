extends Control

const HEART_SIZE = 15

var health = 4 setget set_health
var max_health = 4 setget set_max_health

onready var healthUIfull = $HealthUIFull
onready var healthUIempty = $HealthUIEmpty

func _ready():
	self.max_health = PlayerStats.max_health
	self.health = PlayerStats.health
	PlayerStats.connect("health_change", self, "set_health")
	PlayerStats.connect("max_health_change", self, "set_max_health")


func set_health(value):
	health = clamp(value, 0, max_health)
	if healthUIfull != null:
		healthUIfull.rect_size.x = health * HEART_SIZE


func set_max_health(value):
	max_health = max(value, 1)
	if healthUIempty != null:
		healthUIempty.rect_size.x = max_health * HEART_SIZE
